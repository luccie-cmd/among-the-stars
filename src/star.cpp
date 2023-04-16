#include <star.h>

Star::Star(Vec2i pos, int diameter, SDL_Texture* texture){
    Star::pos = pos;
    Star::dia = diameter;
    Star::texture = texture;
}

void Star::draw(SDL_Renderer* renderer, int scale){
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

void Star::SetX(int x){
    Star::pos.SetX(x);
}
void Star::SetY(int y){
    Star::pos.SetY(y);
}
void Star::SetPos(Vec2i pos){
    Star::pos.SetPos(pos);
}
int Star::getX(){
    return Star::pos.GetX();
}
int Star::getY(){
    return Star::pos.GetY();
}
int Star::getW(){
    int w;
    if(SDL_QueryTexture(Star::texture, NULL, NULL, &w, NULL) < 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    return w;
}
int Star::getH(){
    int h;
    if(SDL_QueryTexture(Star::texture, NULL, NULL, NULL, &h) < 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    return h;
}
Vec2i Star::getPos(){
    return Star::pos.GetPos();
}