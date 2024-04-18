#include "Player.h"

#include <iostream>

Player::Player(InputHandler* in){
    /*
        PLAYER():

        -create collider
        -set position

        -add inputhandler pointer
    */
    this->col = new Collider(
        this->position,
        Vector2(32.f, 32.f),
        this
    );
    addChild(col);
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
    std::cout << "pew\n";
}

void Player::render(SDL_Renderer *r){
    renderChildren(r);
}