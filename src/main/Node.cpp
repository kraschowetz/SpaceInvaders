#include "Node.h"

void Node::translate(Vector2 to){
    /*
        VOID TRANSLATE:

        -update self position
        -update children position
    */
    this->position = to + this->offset;
    for(Node *n : children){
        n->translate(this->position);
    }
}

void Node::setOffset(Vector2 of){
    /*
        VOID SET OFFSET:

        -set this->offeset
        -refresh this & children position via translante()
    */
    this->offset = of;
    this->translate(this->position);
}

void Node::setSize(Vector2 s){
    this->size = s;
}

void Node::setScale(Vector2 s){
    this->scale = s;
}

void Node::update(float delta){
    updateChildren(delta);
}

void Node::updateChildren(float delta){
    for(Node *n : children){
        n->update(delta);
    }
}

void Node::render(SDL_Renderer *r){
    renderChildren(r);
}

void Node::renderChildren(SDL_Renderer *r){
    for(Node *n : children){
        n->render(r);
    }
}

void Node::deleteNode(){
    Node *parent = getParent();
    for (int i = 0; i < parent->getChildren().size(); i++){
        if(parent->getChildren().at(i) == this){
            for(Node *n : children){
                n->deleteNode();
            }
            parent->children.erase(parent->children.begin() + i);
            delete this;
        }
    }
}

void Node::setParent(Node *p){
    this->parent = p;
}

void Node::addChild(Node *p){
    p->setParent(this);
    children.push_back(p);
}

Node* Node::getParent(){
    return this->parent;
}

std::vector<Node*> Node::getChildren(){
    return this->children;
}