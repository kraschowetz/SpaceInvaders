#pragma once

#include "../main/Node.h"
#include <SDL.h>

class Entity : public Node{
    //members
    protected:
        Vector2 size;
        Vector2 velocity;
        Vector2 externalForce;
        SDL_Rect rect;
    // methods
    public:
        Entity();
        virtual void applyForce(Vector2 force);
        virtual void applyVelocity();
        virtual void checkBounds(Vector2 s, Vector2 e);
    // getters & setters
    public:
        Vector2 getPosition();
        SDL_Rect &getRect();

};