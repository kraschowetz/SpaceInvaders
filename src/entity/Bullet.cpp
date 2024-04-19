#include "Bullet.h"

Bullet::Bullet(){
    size = Vector2(4.f, 4.f);

    Collider *col = new Collider(
        position,
        size,
        this
    );
    addChild(col);
}

void Bullet::update(float delta){

    if(position.y < -4){
       deleteNode();
       return;
    }

    velocity = Vector2(0.f, -1.f) * 512 * delta;
    applyVelocity();

    updateChildren(delta);
}

