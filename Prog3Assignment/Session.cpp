#include "Session.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


void Session::addBackground(char path[])
{
    background = IMG_LoadTexture(sys.ren,path);
}

void Session::add(Sprite* sprite) {
    sprite->setFPS(FPS);
    added.push_back(sprite);
}

void Session::remove(Sprite* sprite) {
    removed.push_back(sprite);
}

bool Session::startScreen()
{   
    bool gameStart = false;
    int windowW, windowH, backgroundW;
    TTF_Init();
    TTF_Font* arcadeFont = TTF_OpenFont("ARCADE_N.TTF",24);
    SDL_Color white ={255,255,255,255};
    SDL_Color black ={0,0,0,255};
    SDL_Surface* whiteText = TTF_RenderText_Solid(arcadeFont,"PRESS SPACE TO START",white);
    SDL_Surface* blackText = TTF_RenderText_Solid(arcadeFont,"PRESS SPACE TO START",black);
    SDL_Texture* whiteMessage = SDL_CreateTextureFromSurface(sys.ren,whiteText);
    SDL_Texture* blackMessage = SDL_CreateTextureFromSurface(sys.ren,blackText);
    SDL_FreeSurface(whiteText);
    SDL_FreeSurface(blackText);
    SDL_Rect whiteMessageRect;
    whiteMessageRect.x = 100;
    whiteMessageRect.y = 200;
    whiteMessageRect.w = 500;
    whiteMessageRect.h = 100;

    SDL_Rect blackMessageRect;
    blackMessageRect.x = 98;
    blackMessageRect.y = 202;
    blackMessageRect.w = 500;
    blackMessageRect.h = 100;


    Uint32 tickInterval = 1000 / FPS;
    SDL_QueryTexture(background, NULL, NULL, &backgroundW, NULL);
    SDL_GetWindowSize(sys.win, &windowW,&windowH);
    
    SDL_Rect bgCrop = { 0, 0, windowW, windowH };
    SDL_Rect bgRect = { 0, 0, windowW, windowH };

    SDL_Event event;
    while(!gameStart)
    {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                return false;
            }

            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    gameStart = true;
                    return true;
                }
            }
        } // Poll event 
        bgCrop.x++;
        if (bgCrop.x >= backgroundW - windowW) {
            bgCrop.x = 0;
        }

        SDL_RenderClear(sys.ren);
        SDL_RenderCopy(sys.ren, background,&bgCrop, &bgRect );
        SDL_RenderCopy(sys.ren,blackMessage,NULL,&blackMessageRect);
        SDL_RenderCopy(sys.ren,whiteMessage,NULL,&whiteMessageRect);          
    
        SDL_RenderPresent(sys.ren);
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0){
            SDL_Delay(delay);
        }


    } // While Gamestart
    return false;
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
    if(!startScreen()){
        exit = true;
    }
    sys.setMusic("bgm_action_4.wav");

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
        SDL_RenderCopy(sys.ren, background, &bgCrop, &bgRect );
        for (Sprite* sprite: sprites){
            sprite->draw();
        }
        SDL_RenderPresent(sys.ren);
        
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    }
    
}


