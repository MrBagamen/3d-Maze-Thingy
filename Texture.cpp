#include "Texture.hpp"

Texture::Texture()
{
}

void Texture::LoadTexture(const char* fileName, bool anisotropicFiltering, GLfloat afLevel)
{
    SDL_Surface *temp = IMG_Load(fileName);
    if(!temp)
    {
        printf("Error loading %s\n", fileName);
        exit(1);
    }
    printf("Loaded %s\n", fileName);

    w = temp->w;
    h = temp->h;
    pixels = temp->pixels;

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    if(anisotropicFiltering)
    {
        if(GLEW_EXT_texture_filter_anisotropic)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
            glGenerateMipmap(GL_TEXTURE_2D);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, afLevel);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);

            return;
        }
            printf("EXT_texture_filter_anisotropic is not supported");
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void Texture::LoadTexture(const char* fileName, bool anisotropicFiltering, GLfloat afLevel, GLfloat tx, GLfloat ty)
{
    texcoord[0] = 0.0f;texcoord[1] = 0.0f;
    texcoord[2] = tx;texcoord[3] = 0.0f;
    texcoord[4] = tx;texcoord[5] = ty;
    texcoord[6] = 0.0f;texcoord[7] = ty;
    LoadTexture(fileName, anisotropicFiltering, afLevel);
}
