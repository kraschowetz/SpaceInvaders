#pragma once

#include <vector>
#include <SDL.h>
#include "../math/Vector2.h"

class Node{
    //members
    protected:
        char name[256]; //TODO: Node* getNode(char name[256]);
        Vector2 position = Vector2();
        Vector2 offset = Vector2();
        Vector2 size = Vector2();
        Vector2 scale = Vector2(1.f, 1.f);
        Node *parent = nullptr;
        std::vector<Node*> children;
    //methods
    public:
        virtual void translate(Vector2 to);
        virtual void setOffset(Vector2 of);
        virtual void setSize(Vector2 s);
        virtual void setScale(Vector2 s);
        virtual void setParent(Node *p);
        virtual void addChild(Node *p);
        virtual void update(float delta);
        virtual void updateChildren(float delta);
        virtual void render(SDL_Renderer *r);
        virtual void renderChildren(SDL_Renderer *r);
        Node *getParent();
        std::vector<Node*> getChildren();
};