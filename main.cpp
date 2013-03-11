#include "Plane.hpp"
#include "Camera.hpp"

bool keys[317] = {false};

void InitGL();
int main (int argc, char** argv)
{
    SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_OPENGL);
    SDL_Event event;
    InitGL();

    //Camera
    Camera cam(0.0f, 5.0f, 0.0f);

    //Plane/Floor
    Plane floor(0.0f, 0.0f, 0.0f, 500);
    floor.LoadTexture("res/floor.png", true, 16);

    bool is_running = true;
    while(is_running)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                is_running = false;
                break;
                case SDL_KEYDOWN:
                    keys[event.key.keysym.sym] = true;
                break;
                case SDL_KEYUP:
                    keys[event.key.keysym.sym] = false;
                break;
                default:;
            }
        }
        if(keys[SDLK_ESCAPE]){is_running = false;}
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        if(keys[SDLK_a])
        {
            cam.rotateLoc(1.0f, 0.0f,-1.0f, 0.0f);
        }
        if(keys[SDLK_d])
        {
            cam.rotateLoc(1.0f, 0.0f, 1.0f, 0.0f);
        }
        if(keys[SDLK_w])
        {
            cam.moveLoc(0.0f, 0.0f, 1.0f, 0.5f);
        }
        if(keys[SDLK_s])
        {
            cam.moveLoc(0.0f, 0.0f, 1.0f,-0.5f);
        }
        cam.setView();


        floor.Draw();

        SDL_GL_SwapBuffers();
    }

    SDL_Quit();
    return 0;
}

void InitGL()
{
    if(GLEW_OK != glewInit())
    {
        exit(1);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1024.0f/768.0f, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
