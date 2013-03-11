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
    GLfloat texcoord[8] = {  0.0f, 0.0f,
                            45.0f, 0.0f,
                            45.0f, 45.0f,
                            0.0f, 45.0f};
    GLfloat plane[12];
};

#endif // PLANE_HPP
