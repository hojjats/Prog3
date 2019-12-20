

#ifndef Bird_hpp
#define Bird_hpp
#include "Sprite.hpp"
#include "Session.hpp"
#include "Session.hpp"
#include <SDL2/SDL.h>
#include "System.hpp"
#include <SDL2/SDL_image.h>

class Bird : public Sprite {
public:
    static Bird* getInstance(int x) {
        return new Bird(x);
    }
    Bird(int x) : Sprite(x,500,40,40) {
        texture = IMG_LoadTexture(sys.ren, "bird.png");
    }
    ~Bird() {
        SDL_DestroyTexture(texture);
    }
    void handleEvent(SDL_Event event) override {}
    void draw() const override {
        SDL_Rect rect = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
    void tick() override {
        counter++;
        if (counter % 10 == 0){
            rect.y--;
        }
    }
private:
    SDL_Texture* texture;
    int counter = 0;
    
};

#endif /* Bird_hpp */
