#include "Wall.hpp"

Wall::Wall(GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizex, GLfloat _sizey,GLfloat _sizez)
{
    x = _x;
    y = _y;
    z = _z;
    psizey = _sizey / 2;
    psizez = _sizez / 2;
    psizex = _sizex / 2;

    wall[0] = psizex;wall[1] = psizey;wall[2] = psizez;
    wall[3] = -psizex;wall[4] = psizey;wall[5] = -psizez;
    wall[6] = -psizex;wall[7] = -psizey;wall[8] = -psizez;
    wall[9] = psizex;wall[10] = -psizey;wall[11] =  psizez;
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
