#ifndef WALL_HPP
#define WALL_HPP

#include "Texture.hpp"

class Wall : public Texture
{
public:
    GLfloat x, y, z, psizex,psizey, psizez;

    Wall(GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizex, GLfloat _sizey,GLfloat _sizez);
    void Draw();

private:
    GLfloat wall[12];
};

#endif // WALL_HPP
