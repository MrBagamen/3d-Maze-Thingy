#ifndef WALL_HPP
#define WALL_HPP

#include "Texture.hpp"

class Wall
{
public:
    GLfloat x, y, z, psizex,psizey, psizez;

    Wall(const Texture& texture, GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizex, GLfloat _sizey,GLfloat _sizez);
    void Draw();

private:
    GLfloat wall[12];
    GLubyte indices[6] = {0, 1, 2, 2, 3, 0};
    const Texture& texture;
};

#endif // WALL_HPP
