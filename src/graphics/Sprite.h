#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "../main/Node.h"

class Sprite : public Node{
    //members
    private:
        SDL_Surface *image = nullptr;
        SDL_Texture *texture = nullptr;
    //methods
    public:
        void load(std::string path, SDL_Renderer *r);
        void render(SDL_Renderer *r) override;
};