#pragma once

#include "Entity.h"
#include "../physics/Collider.h"
#include "../main/InputHandler.h"

class Player : public Entity{
    //members
    private:
        float speed = 256.f;
        InputHandler *input = nullptr;
        Collider *col;
    //methods
    public:
        Player(InputHandler* in);
        void update(float delta) override;
        void render(SDL_Renderer *r) override;
    private:
        void shoot();
};