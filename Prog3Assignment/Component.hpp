

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Component
{
public:
    virtual void mouseDown(int x, int y){}
    virtual void mouseUp(int x, int y) {}
    virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect; }
    virtual void tick() = 0;
    
protected:
    Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
    SDL_Rect rect;
};

#endif /* Component_hpp */
