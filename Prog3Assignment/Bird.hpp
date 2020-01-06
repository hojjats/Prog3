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
    Bird();
    ~Bird();
    void handleEvent(SDL_Event event) override;
    void draw() const override;
    void tick() override;
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
