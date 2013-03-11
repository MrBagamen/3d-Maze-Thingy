#include "Wall.hpp"

Wall::Wall(GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizey,GLfloat _sizez)
{
    x = _x;
    y = _y;
    z = _z;
    psizey = _sizey / 2;
    psizez = _sizez / 2;

    wall[0] = 0.0f;wall[1] = psizey;wall[2] = psizez;
    wall[3] = 0.0f;wall[4] = psizey;wall[5] = -psizez;
    wall[6] = 0.0f;wall[7] = -psizey;wall[8] = -psizez;
    wall[9] = 0.0f;wall[10] = -psizey;wall[11] =  psizez;
}

void Wall::Draw()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, tex);
    glTranslatef(x, y, z);
    glVertexPointer(3, GL_FLOAT, 0, wall);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoord);
    glDrawArrays(GL_QUADS, 0, 4);
    glPopMatrix();
}
