#pragma once
#ifndef PLAYER_SPEED
#define PLAYER_SPEED 10
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <util.h>

class Player{
    public: 
        Player(Vec2i pos, SDL_Texture *texture);
        void Draw(SDL_Renderer* renderer, int scale=1);
        void SetX(int x);
        void SetY(int y);
        void SetPos(Vec2i new_pos);
        int GetX();
        int GetY();
        int getW();
        int getH();
        Vec2i GetPos();
    private:
        Vec2i pos;
        SDL_Texture* texture;
};
