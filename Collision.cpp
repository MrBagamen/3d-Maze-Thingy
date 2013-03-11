#include "Collision.hpp"

Collision::Collision()
{
}

bool Collision::IsCollision(GLfloat x, GLfloat z, Wall *w)
{
    return (x > w->x &&
            x < w->x+1.0f &&
            z > w->z-w->psizez &&
            z < w->z+w->psizez);
}
