#ifndef PLANE_HPP
#define PLANE_HPP

#include "Texture.hpp"

class Plane : public Texture
{
public:
    Plane(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size);

    void Draw();
private:
    GLfloat x, y, z, psize;
    GLubyte indices[6] = {0, 1, 2, 2, 3, 0};

    GLfloat plane[12];
};

#endif // PLANE_HPP
