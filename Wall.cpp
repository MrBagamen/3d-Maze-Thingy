#include "Wall.hpp"

Wall::Wall(const Texture& texture, GLfloat _x, GLfloat _y, GLfloat _z,GLfloat _sizex, GLfloat _sizey,GLfloat _sizez) :
    texture(texture)
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
    glBindTexture(GL_TEXTURE_2D, texture.tex);
    glTranslatef(x, y, z);
    glVertexPointer(3, GL_FLOAT, 0, wall);
    glTexCoordPointer(2, GL_FLOAT, 0, texture.texcoord);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glPopMatrix();
}
