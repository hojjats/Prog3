
#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"

Session ses;

class Bullet : public Sprite {
public:
    static Bullet* getInstance(int x) {
        return new Bullet(x);
    }
    Bullet(int x) : Sprite(x, 500, 40,40){
        // add filePath
        texture = IMG_LoadTexture(sys.ren, "filePath");
    }
    ~Bullet() {
        SDL_DestroyTexture(texture);
    }
    void draw() const {
        SDL_Rect rect = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
    void tick() {
        counter++;
        if (rect.y <= 0)
            ses.remove(this);
        else if (counter % 10 == 0)
            rect.y--;
    }
private:
    SDL_Texture* texture;
    int counter = 0;
};

class Pistol : public Sprite {
public:
    Pistol() :Sprite(0, 0, 0, 0) {}
    void draw() const {}
    void tick() {}
    void mouseDown(int x, int y) {
        Bullet* b = Bullet::getInstance(x);
        ses.add(b);
    }
};

int main(int argc, char** argv) {
    Pistol* pistol = new Pistol();
    ses.add(pistol);
    ses.run();
    return 0;
}
