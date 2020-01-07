#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"
#include "Pipe.hpp"
#include "GameEngine.hpp"

Session ses;

void addPipeSection(int gapCenter, int gapDistance) {
    const int screenH = 500, pipeH = 700;
    int y =  screenH - gapCenter + (gapDistance/2);
    Pipe* bottom = new Pipe(gapCenter, gapDistance, false, y);
    ses.add(bottom);
    y = -pipeH + (screenH - gapCenter - (gapDistance/2));
    Pipe* top  = new Pipe(gapCenter, gapDistance, true, y);
    ses.add(top);
}


int main(int argc, char** argv) {
    GameEngine game;
    Bird bird;
    ses.add(&bird);
    ses.addBackground("background.png");
    
    addPipeSection(250, 100);
    
    ses.run();
    return 0;
}

