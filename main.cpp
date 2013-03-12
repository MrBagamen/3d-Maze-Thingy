#include "Plane.hpp"
#include "Wall.hpp"
#include "Camera.hpp"
#include "Clock.hpp"
#include "Config.hpp"
#include "Collision.hpp"
#include <vector>
#include <GL/glew.h>

using namespace std;

bool keys[317] = {false};

void InitGL();
int main (int argc, char** argv)
{
    Config conf;

    if (!conf.LoadFromFile("maze.conf"))
    {
        puts("Could not find maze.conf. Using default configuration.");
    }

    SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_OPENGL);
    SDL_Event event;
    InitGL();

    //Camera
    Camera cam(0.0f, 5.0f, 0.0f);

    //Plane/Floor
    Plane floor(0.0f, 0.0f, 0.0f, 500);
    floor.LoadTexture("res/floor.png", conf.GetBool("anisotropic"), conf.GetFloat("afLevel"), 50.0f, 50.0f);

    //Test/Wall
    Wall w(-10.0f, 0.0f, -30.0f, 0.0f, 20.0f, 50.0f);
    Wall w2(15.0f, 0.0f, -30.0f, 50.0f, 20.0f, 0.0f);
    w.LoadTexture("res/wall.png", conf.GetBool("anisotropic"), conf.GetFloat("afLevel"), 5.0f, 2.0f);
    w2.LoadTexture(w.tex, conf.GetBool("anisotropic"), conf.GetFloat("afLevel"), 5.0f, 2.0f);

    //Test collision
    Collision c;

    bool is_running = true;
    int framesRendered = 0;
    Clock clock;

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
        if(c.IsCollision(cam.Position[0], cam.Position[2], &w, true) || c.IsCollision(cam.Position[0], cam.Position[2], &w2, false))
        {
            if(keys[SDLK_w])
            {
                cam.moveLoc(0.0f, 0.0f, 1.0f,-0.5f);

            }
            if(keys[SDLK_s])
            {
                cam.moveLoc(0.0f, 0.0f, 1.0f, 0.5f);
            }
        }
        //printf("X: %f, Z: %f\n", cam.Position[0], cam.Position[2]);
        cam.setView();

        floor.Draw();
        w.Draw();
        w2.Draw();


        SDL_GL_SwapBuffers();
        ++framesRendered;

        if (clock.Ticks() >= 1000)
        {
            static char buf[30];
            sprintf(buf, "%d fps", framesRendered);
            SDL_WM_SetCaption(buf, nullptr);
            framesRendered = 0;
            clock.Restart();
        }
    }

    SDL_Quit();

    if (!conf.SaveToFile("maze.conf"))
    {
        puts("Warning: Failed to save maze.conf.");
    }

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

    //Fog
    GLfloat density = 0.05; //set the density to 0.3 which is acctually quite thick
    GLfloat fogColor[4] = {0.8, 0.8, 0.8, 1.0}; //set the for color to grey

    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_EXP);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, density);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
