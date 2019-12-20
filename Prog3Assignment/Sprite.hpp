#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite{
public:
    virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect; }
    virtual void tick() = 0;
    virtual ~Sprite(){}
    virtual void handleEvent(SDL_Event event) = 0;
    
protected:
    Sprite(int x, int y, int w, int h) : rect{ x,y,w,h } {}
    SDL_Rect rect;
};

#endif
