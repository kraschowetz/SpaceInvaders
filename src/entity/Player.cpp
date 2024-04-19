#include "Player.h"

#include <iostream>

Player::Player(InputHandler* in, SDL_Renderer *r){
    /*
        PLAYER():

        -create collider
        -set position

        -add inputhandler pointer
    */
    this->size = Vector2(32.f, 32.f);

    this->col = new Collider(
        this->position,
        this->size,
        this
    );
    addChild(col);

    this->spr = new Sprite();
    spr->load("res/player.png", r);
    spr->setSize(this->size);
    addChild(spr);

    position = Vector2(0.f, 416.f);
    
    this->input = in;
}

void Player::update(float delta){
    /*
        VOID UPDATE:

        -get move direction
        -apply speed based on direction
        -check for boundaries

        -get input

        -update children
    */

    Vector2 dir;
    if(input->getKeyPressed(SDLK_RIGHT)){
        dir.x += 1;
    }
    if(input->getKeyPressed(SDLK_LEFT)){
        dir.x -= 1;
    }

    velocity = dir.normalized() * speed * delta;
    applyVelocity();

    checkBounds(
        Vector2(0.f, 0.f),
        Vector2(288.f, 448.f)
    );

    if(input->getKeyJustPressed(SDLK_UP)){
        shoot();
    }

    updateChildren(delta);
}

void Player::shoot(){
    Bullet *b = new Bullet();
    b->translate(
        Vector2(
            this->position.x + this->size.x / 2 - 2,
            this->position.y + this->size.y / 2
        )
    );
    getParent()->addChild(b);
}

void Player::render(SDL_Renderer *r){
    renderChildren(r);
}