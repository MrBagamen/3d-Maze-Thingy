#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL/SDL_image.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Texture
{
public:
    GLuint tex;
    Texture();

    void LoadTexture(const char* fileName, bool anisotropicFiltering, GLfloat afLevel);
    void LoadTexture(const char* fileName, bool anisotropicFiltering, GLfloat afLevel, GLfloat tx, GLfloat ty);

    GLfloat texcoord[8] = { 0.0f, 0.0f,
                            1.0f, 0.0f,
                            1.0f, 1.0f,
                            0.0f, 1.0f};
private:

    int w, h;
    void *pixels;
};

#endif // TEXTURE_HPP
