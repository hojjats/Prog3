

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
    static Bird* getInstance(int y) {
        return new Bird(y);
    }
    Bird(int y) : Sprite(320,220,40,40) {
        texture = IMG_LoadTexture(sys.ren, "bird.png");
    }
    ~Bird() {
        SDL_DestroyTexture(texture);
    }
    void handleEvent(SDL_Event event) override {
        switch (event.type) {
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        texture = tex1;
                        jumped = true;
                        break;
                }
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        texture = tex2;
                        break;
                }
                break;
        }
    }
    void draw() const override {
        SDL_Rect rect = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
        void tick() override {
    //        counter++;
            const static float gravity = 0.01;
            const static float lift = -0.3;
            velocity += gravity;
            timeSinceJump += 1000 / 60;
            if (jumped && timeSinceJump > 0.3) {
                velocity += lift;
                timeSinceJump = 0;
                jumped = false;
            }
            double deltaY = velocity * (1000/60);
            rect.y += deltaY;
            //        if (counter % 10 == 0){
            //            rect.y--;
            //        }
        }
private:
    SDL_Texture* texture;
    SDL_Texture* tex1 = IMG_LoadTexture(sys.ren, "bird.png");
    SDL_Texture* tex2 = IMG_LoadTexture(sys.ren, "bird2.png");
    int counter = 0;
    float velocity = 0;
    bool jumped = false;
    float timeSinceJump = 0;
};

#endif /* Bird_hpp */
