#pragma once

#include "../entity/Entity.h"
#include "../graphics/Sprite.h"
#include "../physics/Collider.h"

class Bullet : public Entity{
    //methods
    public:
        Bullet();
        void update(float delta) override;
};