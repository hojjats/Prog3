
#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"

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
    void handleEvent(SDL_Event event) override{}
    void draw() const override {
        SDL_Rect rect = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
    void tick() override {
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
    void draw() const override {}
    void tick() override {}
    void handleEvent(SDL_Event event) override {
        switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                mouseDown(event.button.x, event.button.y);
                break;
        }
    }
    void mouseDown(int x, int y) {
        Bird* b = Bird::getInstance(x);
        ses.add(b);
    }
};

int main(int argc, char** argv) {
    Pistol* pistol = new Pistol();
    ses.add(pistol);
    ses.run();
    return 0;
}
