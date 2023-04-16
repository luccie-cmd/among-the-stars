#include <player.h>

Player::Player(Vec2i pos, SDL_Texture* texture){
    Player::pos = pos;
    Player::texture = texture;
}

void Player::Draw(SDL_Renderer* renderer, int scale){
    int w, h;
    if(SDL_QueryTexture(Player::texture, NULL, NULL, &w, &h) < 0) {
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

void Player::SetX(int x){
    Player::pos.SetX(x);
}
void Player::SetY(int y){
    Player::pos.SetY(y);
}
void Player::SetPos(Vec2i pos){
    Player::pos.SetPos(pos);
}
int Player::GetX(){
    return Player::pos.GetX();
}
int Player::GetY(){
    return Player::pos.GetY();
}
int Player::getW(){
    int w;
    if(SDL_QueryTexture(Player::texture, NULL, NULL, &w, NULL) < 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    return w;
}
int Player::getH(){
    int h;
    if(SDL_QueryTexture(Player::texture, NULL, NULL, NULL, &h) < 0) {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    return h;
}
Vec2i Player::GetPos(){
    return Player::pos.GetPos();
}