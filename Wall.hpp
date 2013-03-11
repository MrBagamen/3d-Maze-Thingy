#ifndef WALL_HPP
#define WALL_HPP

#include "Texture.hpp"

class Wall : public Texture
{
public:
    Wall(GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizey,GLfloat _sizez);
    void Draw(GLfloat angle);
private:
    GLfloat x, y, z, psizey, psizez;

    GLfloat wall[12];
};

#endif // WALL_HPP
