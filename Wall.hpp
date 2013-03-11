#ifndef WALL_HPP
#define WALL_HPP

#include "Texture.hpp"

class Wall : public Texture
{
public:
    Wall(GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizey,GLfloat _sizez);

    void Draw();
private:
    GLfloat x, y, z, psizey, psizez;
    GLfloat texcoord[8] = { 0.0f, 0.0f,
                            1.0f, 0.0f,
                            1.0f, 1.0f,
                            0.0f, 1.0f};
    GLfloat wall[12];
};

#endif // WALL_HPP
