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
    Bird(std::string path1, std::string path2);
    ~Bird();
    void handleEvent(SDL_Event event) override;
    void draw(SDL_Renderer* ren) const override;
    void tick() override;
    void generateTexture(SDL_Renderer* ren) override;
private:
    SDL_Texture* texture = nullptr;
    SDL_Texture* tex1 = nullptr;
    SDL_Texture* tex2 = nullptr;
    int counter = 0;
    float velocity = 0;
    bool jumped = false;
    float timeSinceJump = 0;
    std::string path1;
    std::string path2;
};

#endif /* Bird_hpp */
