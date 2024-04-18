#include "Entity.h"   

Entity::Entity(){
    position = Vector2(0.f, 0.f);
    rect.x = position.x;
    rect.y = position.y;
    rect.w = 32.f;
    rect.h = 32.f;

    translate(position);
}

void Entity::applyForce(Vector2 force){
    externalForce += force;
}

void Entity::applyVelocity(){
    translate(position + velocity);
}

void Entity::checkBounds(Vector2 s, Vector2 e){
    /*
        VOID CHECK BOUNDS:

        -check if position < min position:
            if it is, snap position to min position
        
        -check if position > max position:
            if it is, snap position to max position
    */
    if(position.x < s.x){
        translate(Vector2(s.x, position.y));
    }
    if(position.y < s.y){
        translate(Vector2(position.x, s.y));
    }

    if(position.x > e.x){
        translate(Vector2(e.x, position.y));
    }
    if(position.y > e.y){
        translate(Vector2(position.x, e.y));
    }
}

Vector2 Entity::getPosition(){
    return position;
}

SDL_Rect& Entity::getRect(){
    return rect;
}