#include "Collider.h"

Collider::Collider(){
    // default constructor
    this->shape.x = 0;
    this->shape.y = 0;
    this->shape.w = 32;
    this->shape.h = 32;
    this->size = Vector2(32.f, 32.f);
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

Collider::Collider(Vector2 _pos){
    // custom position constructor
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = 32;
    this->shape.h = 32;
    this->size = Vector2(32.f, 32.f);
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

Collider::Collider(Vector2 _pos, Vector2 _size){
    // custom position & size constructor
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = _size.x;
    this->shape.h = _size.y;
    this->size = _size;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

Collider::Collider(Vector2 _pos, Vector2 _size, Entity* _p){
    // entity collider constructor
    this->shape.x = _pos.x;
    this->shape.y = _pos.y;
    this->shape.w = _size.x;
    this->shape.h = _size.y;
    this->size = _size;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->entity = _p;
    this->isStatic = false;
}

void Collider::translate(Vector2 _pos){
    /*
        OVERRIDE VOID TRANSLATE:
        
        -update node position

        -update rect position

        -update children position
    */
    this->position = _pos + this->offset;

    this->shape.x = _pos.x + this->offset.x;
    this->shape.y = _pos.y + this->offset.y;
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );

    for (Node *n : children){
        n->translate(this->position);
    }
}

void Collider::setIsTrigger(bool _t){
    this->isTrigger = _t;
}

void Collider::setIsStatic(bool _s){
    this->isStatic = _s;
}

void Collider::setData(std::string _d){
    this->data = _d;
}

std::string Collider::getData(){
    return this->data;
}


bool Collider::isColliding(Collider *other){
    /*
        BOOL IS COLLIDING:
        
        -return true if collider1 intersects with collider 2
        -pushes collider 1 back if 1 is an entity
    */
    bool r = SDL_HasIntersection(
            this->getShape(), other->getShape()
        );

    if(r && !this->isStatic && !this->isTrigger){
        Vector2 force = (
                centerPosition - other->getCenter()
            );
        entity->applyForce(force.normalized() * 16.f);
    }
    return r;
}

void Collider::render(SDL_Renderer* r){
    /*
        VOID RENDER:
        --used only for debugging--

        -draws collider shape, bounds and center point
    */
    if(!debug){
        return;
    }

    SDL_Rect renderShape {
        shape.x + (int)offset.x,
        shape.y + (int)offset.y,
        shape.w,
        shape.h
    };


    SDL_SetRenderDrawColor(r, 123, 128, 255, 128);
    SDL_RenderFillRect(r, &renderShape);

    SDL_SetRenderDrawColor(r, 64, 64, 255, 255);
    SDL_RenderDrawRect(r, &renderShape);

    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
    SDL_RenderDrawPoint(
        r,
        centerPosition.x + offset.x,
        centerPosition.y + offset.y
    );
}

Vector2 Collider::getCenter(){
    return this->centerPosition;
}

SDL_Rect* Collider::getShape(){
    return &this->shape;
}

void Collider::setOffset(Vector2 of){
    this->offset = of;
}