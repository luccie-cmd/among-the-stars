#pragma once
class Vec2i {
    public:
        Vec2i(int x, int y){
            Vec2i::x = x;
            Vec2i::y = y;
        }
        Vec2i(){
            Vec2i::x = 0;
            Vec2i::y = 0;
        }
        int GetX(){
            return Vec2i::x;
        }
        int GetY(){
            return Vec2i::y;
        }
        void SetX(int x){
           Vec2i::x = x;
        }
        void SetY(int y){
            Vec2i::y = y;
        }
        void SetPos(Vec2i pos){
            Vec2i::SetX(pos.x);
            Vec2i::SetY(pos.y);
        }
        Vec2i GetPos(){
            return (Vec2i){
                Vec2i::GetX(),
                Vec2i::GetY(),
            };
        }
    private:
        int x, y;
};
class Vec2f {
    public:
        Vec2f(float x, float y){
            Vec2f::x = x;
            Vec2f::y = y;
        }
        float GetX(){
            return Vec2f::x;
        }
        float GetY(){
            return Vec2f::y;
        }
        void SetX(float x){
           Vec2f::x = x;
        }
        void SetY(float y){
            Vec2f::y = y;
        }
        void SetPos(Vec2f pos){
            Vec2f::SetX(pos.x);
            Vec2f::SetY(pos.y);
        }
        Vec2f GetPos(){
            return (Vec2f){
                Vec2f::GetX(),
                Vec2f::GetY(),
            };
        }
    private:
        float x, y;
};