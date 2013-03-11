#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <SDL/SDL.h>

class Clock
{
public:
    Clock() :
        start(SDL_GetTicks()) {}

    void Restart()
    {
        start = SDL_GetTicks();
    }

    Uint32 Ticks()
    {
        return SDL_GetTicks() - start;
    }

private:
    Uint32 start;
};

#endif // CLOCK_HPP
