#pragma once

#include <SDL.h>

#include "Timer.h"
#include "InputHandler.h"
#include "Root.h"
#include "../entity/Entity.h"
#include "../entity/Player.h"

class Game {
    //members
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = false;
        float deltaTime;

        Root root;
    public:
        InputHandler input;
    //methods
    public:
        void start();
        void stop();
    private:
        void run();
        void pollEvents();
        void initGame();
        void update(float delta);
        void render();
};