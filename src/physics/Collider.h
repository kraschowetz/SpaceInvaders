#pragma once

#include <SDL.h>
#include <string>
#include "../main/Node.h"
#include "../entity/Entity.h"

class Collider : public Node{
    //members
    private:
        SDL_Rect shape;
        bool isStatic;
        bool isTrigger = false;
        bool isActive = true;
        Vector2 centerPosition;
        Vector2 size;
        std::string data;
        Entity *entity;
    //getters
    public:
        SDL_Rect* getShape();
        Vector2 getCenter();
        void setData(std::string _d);
    // methods
    public:
        Collider();
        Collider(Vector2 _pos);
        Collider(Vector2 _pos, Vector2 _size);
        Collider(Vector2 _pos, Vector2 _size, Entity* _p);
        void translate(Vector2 _pos) override;
        void setIsTrigger(bool _t);
        void setIsStatic(bool _s);
        void setOffset(Vector2 of);
        std::string getData();
        bool isColliding(Collider *other);
        void render(SDL_Renderer* r);
};