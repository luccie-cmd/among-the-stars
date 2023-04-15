#pragma once
#include <SDL2/SDL.h>
#include <util.h>

class Player{
    public: 
        Player(Vec2i pos, SDL_Texture *texture);
        void Draw(SDL_Renderer* renderer);
        void setX(int x);
        void setY(int y);
        void setPos(int x, int y);
        int getX();
        int getY();
        Vec2i getPos();
    private:
        Vec2i pos;
        SDL_Texture* texture;
};
