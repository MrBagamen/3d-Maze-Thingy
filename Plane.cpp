#include "Plane.hpp"

Plane::Plane(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size)
{
    x = _x;
    y = _y;
    z = _z;
    psize = _size / 2;

    plane[0] = x+psize;plane[1] = 0.0f;plane[2] = z+psize;
    plane[3] = x-psize;plane[4] = 0.0f;plane[5] = z+psize;
    plane[6] = x-psize;plane[7] = 0.0f;plane[8] = z-psize;
    plane[9] = x+psize;plane[10] = 0.0f;plane[11] = z-psize;
}

void Plane::Draw()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, tex);
    glTranslatef(x, y, z);
    glVertexPointer(3, GL_FLOAT, 0, plane);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoord);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glPopMatrix();
}
