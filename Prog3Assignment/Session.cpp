#include "Session.hpp"
#include "System.hpp"
#include <SDL2/SDL.h>

#define FPS 60

void Session::add(Sprite* sprite) {
    added.push_back(sprite);
}

void Session::remove(Sprite* sprite) {
    removed.push_back(sprite);
}

void Session::run(){
    bool exit = false;
    
    Uint32 tickInterval = 1000 / FPS;
    
    while (!exit) {
        SDL_Event event;
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit = true;
            }
            for (Sprite* sprite : sprites) {
                sprite->handleEvent(event);
            }
        }
        
        for (Sprite* sprite : sprites) {
            sprite->tick();
        }
        
        for (Sprite* sprite : added) {
            sprites.push_back(sprite);
        }
        added.clear();
        
        for (Sprite* sprite : removed){
            for (std::vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();){
                if (*i == sprite) {
                    i = sprites.erase(i);
                }
                else
                    i++;
            }
        }
        removed.clear();
        
        SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
        SDL_RenderClear(sys.ren);
        for (Sprite* sprite: sprites){
            sprite->draw();
        }
        SDL_RenderPresent(sys.ren);
        
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    }
    
}


