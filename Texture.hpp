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
private:
    int w, h;
    void *pixels;
};

#endif // TEXTURE_HPP
