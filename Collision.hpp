#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Wall.hpp"

class Collision
{
    public:
        Collision();

        bool IsCollision(GLfloat x, GLfloat z, Wall *w);
    private:
};

#endif // COLLISION_HPP
