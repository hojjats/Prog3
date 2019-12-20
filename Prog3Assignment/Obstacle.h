#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Sprite.hpp"
#include "System.hpp"

class Obstacle : public Sprite {
public:
    static Obstacle* getInstance(char* fp);

    void handleEvent(SDL_Event event) override{}

    void draw() const override {
        SDL_Rect rect = getRect();
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
    void tick() override {}

    ~Obstacle() {
        SDL_DestroyTexture(texture);
    }

private:
    SDL_Texture* texture;
    Obstacle(char* filePath) : Sprite(0,100,100,100) {
        texture = IMG_LoadTexture(sys.ren,filePath);
    }
};

Obstacle* Obstacle::getInstance(char *fp){
    new Obstacle(fp);
}
#endif