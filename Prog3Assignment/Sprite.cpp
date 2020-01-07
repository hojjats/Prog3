#include "Sprite.hpp"

bool Sprite::checkCollision(SDL_Rect a, SDL_Rect b){
    int leftA = a.x, leftB = b.x, rightA = a.x + a.w, rightB = b.x + b.w, topA = a.y, topB = b.y, bottomA = a.y + a.h, bottomB = b.y + b.h;
    
    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB) {
        return false;
    }
    return true;
}
