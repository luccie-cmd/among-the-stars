#include <star.h>

Star::Star(Vec2i pos, int diameter, SDL_Texture* texture){
    Star::pos = pos;
    Star::dia = diameter;
    Star::texture = texture;
}

void Star::draw(SDL_Renderer* renderer, float scale){
    int w, h;
    if(SDL_QueryTexture(Star::texture, NULL, NULL, &w, &h) < 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    SDL_Rect src = {
        .x = 0,
        .y = 0,
        .w = w,
        .h = h
    };
    SDL_Rect dst = {
        .x = pos.GetX(),
        .y = pos.GetY(),
        .w = w*scale,
        .h = h*scale,
    };
    SDL_RenderCopy(renderer, texture, &src, &dst);
}