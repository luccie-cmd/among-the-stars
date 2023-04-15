#define SDL_MAIN_HANDLED
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <util.h>

class Star{
    public:
        Star(Vec2i pos, int diameter, SDL_Texture* texture);
        void draw(SDL_Renderer* renderer, float scale=1);
        // void SetX(int x);
        // void SetY(int y);
        // void SetPos(Vec2i pos);

    private:
        Vec2i pos;
        int dia;
        SDL_Texture* texture;
};