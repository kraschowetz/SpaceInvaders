#pragma once

#include "Entity.h"
#include "../physics/Collider.h"
#include "../main/InputHandler.h"
#include "../graphics/Sprite.h"
#include "../entity/Bullet.h"

class Player : public Entity{
    //members
    private:
        float speed = 256.f;
        InputHandler *input = nullptr;
        Collider *col;
        Sprite *spr;
    //methods
    public:
        Player(InputHandler *in, SDL_Renderer *r);
        void update(float delta) override;
        void render(SDL_Renderer *r) override;
    private:
        void shoot();
};