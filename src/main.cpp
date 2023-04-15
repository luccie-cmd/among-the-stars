#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <star.h>

SDL_Texture* load_texture(SDL_Renderer* renderer, const char* location){
    SDL_Texture* texture = IMG_LoadTexture(renderer, location);
    if(texture == NULL){
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    return texture;
}

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("among the stars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1180, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event evs;
    bool should_quit = false;
    SDL_Texture* s_texture = load_texture(renderer, "./bin/gfx/star.png");
    Star s(Vec2i(50, 50), 25, s_texture);
    while(!should_quit){
        while(SDL_PollEvent(&evs)){
            switch(evs.type){
                case SDL_QUIT: {
                    should_quit = true;
                    break;
                }
            }
        }
        SDL_RenderClear(renderer);
        s.draw(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    return 0;
}