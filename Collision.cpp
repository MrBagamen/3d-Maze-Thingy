#include "Collision.hpp"

Collision::Collision()
{
}

bool Collision::IsCollision(GLfloat x, GLfloat z, Wall *w, bool vert)
{
    if(vert)
    {
        return (x+1.5f > w->x &&
                x < w->x+1.5f &&
                z > w->z-w->psizez &&
                z < w->z+w->psizez);
    }
    return (w->x > x-w->psizex &&
            w->x < x+w->psizex &&
            w->z+1.5f > z &&
            w->z < z+1.5f);
}
