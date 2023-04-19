#include <player.h>

Player::Player(Vec2i pos, SDL_Texture* texture){
    Player::pos = pos;
    Player::texture = texture;
}

void Player::Move(int key, SDL_Window* window){
    int window_w, window_h;
    SDL_GetWindowSize(window, &window_w, &window_h);
    switch(key){
        case SDLK_UP: {
            if(Player:GetY()-PLAYER_SPEED <= 0){
                break;
            }
            Player:SetY(Player:GetY()-PLAYER_SPEED);
        } break;
        case SDLK_DOWN: {
            if(Player:getH()+Player:GetY()+PLAYER_SPEED >= window_h){
                break;
            }
            Player:SetY(Player:GetY()+PLAYER_SPEED);
        } break;
        case SDLK_LEFT: {
            if(Player:GetX()-PLAYER_SPEED <= 0){
                break;
            }
            Player:SetX(Player:GetX()-PLAYER_SPEED);
        } break;
        case SDLK_RIGHT: {
            if(Player:getW()+Player:GetX()+PLAYER_SPEED >= window_w){
                break;
            }
            Player:SetX(Player:GetX()+PLAYER_SPEED);
        } break;
    }
}

void Player::Move(int key, int window_w, int window_h) {
    switch(key){
        case SDLK_UP: {
            if(Player:GetY()-PLAYER_SPEED <= 0){
                break;
            }
            Player:SetY(Player:GetY()-PLAYER_SPEED);
        } break;
        case SDLK_DOWN: {
            if(Player:getH()+Player:GetY()+PLAYER_SPEED >= window_h){
                break;
            }
            Player:SetY(Player:GetY()+PLAYER_SPEED);
        } break;
        case SDLK_LEFT: {
            if(Player:GetX()-PLAYER_SPEED <= 0){
                break;
            }
            Player:SetX(Player:GetX()-PLAYER_SPEED);
        } break;
        case SDLK_RIGHT: {
            if(Player:getW()+Player:GetX()+PLAYER_SPEED >= window_w){
                break;
            }
            Player:SetX(Player:GetX()+PLAYER_SPEED);
        } break;
    }
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