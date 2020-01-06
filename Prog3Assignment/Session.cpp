#include "Session.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void Session::addBackground(char path[])
{
    background = IMG_LoadTexture(sys.ren,path);
}

void Session::add(Sprite* sprite) {
    added.push_back(sprite);
}

void Session::remove(Sprite* sprite) {
    removed.push_back(sprite);
}

void Session::run(){
    bool exit = false;
    //SDL_Texture* background = IMG_LoadTexture(sys->ren, "background.png");
    // These 3 rows can be removed if the variables is replaced with handcoded values: 700, 500, 2100
    int windowW, windowH, backgroundW;
    SDL_QueryTexture(background, NULL, NULL, &backgroundW, NULL);
    SDL_GetWindowSize(sys.win, &windowW,&windowH);
    
    SDL_Rect bgCrop = { 0, 0, windowW, windowH };
    SDL_Rect bgRect = { 0, 0, windowW, windowH };
    
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
        
        // "tick" the background, if last section is displayed -> resets to zero
        bgCrop.x++;
        if (bgCrop.x >= backgroundW - windowW) {
            bgCrop.x = 0;
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
        
        //        SDL_SetRenderDrawColor(sys.ren, 66,180,190, 255);
        //        SDL_RenderClear(sys.ren);
        SDL_RenderCopy( sys.ren, background, &bgCrop, &bgRect );
        for (Sprite* sprite: sprites){
            sprite->draw();
        }
        SDL_RenderPresent(sys.ren);
        
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    }
    
}


