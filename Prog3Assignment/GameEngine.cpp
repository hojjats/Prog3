#include "GameEngine.hpp"

GameEngine::GameEngine()
{}

SDL_Rect GameEngine::getWindowSize() {
    int windowHeight, windowWidth;
    SDL_GetWindowSize(mSys.win, &windowWidth, &windowHeight);
    return { 0,0,windowWidth, windowHeight};
}

void GameEngine::add(Sprite* sprite) {
    sprite->generateTexture(mSys.ren);
    sprite->setFPS(FPS);
    added.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite) {
    removed.push_back(sprite);
}

void GameEngine::clearSprites() {
    // Add sprites to removeVector!
    for(auto sprite : sprites){
        delete sprite;
    }
    sprites.clear();
    added.clear();
    removed.clear();
}

bool GameEngine::pollEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }
        for (Sprite* sprite : sprites) {
            sprite->handleEvent(event);
        }
    } // Poll event
    return true;
}

void GameEngine::update() {
    for (Sprite* sprite : sprites) {
        sprite->tick();
    }

    for(auto s = sprites.begin(); s<sprites.end();)
    {
        if((*s)->shouldBeRemoved()) 
        {
            removed.push_back((*s));
            s = sprites.erase(s);
        } else {
            s++;
        }            
    }

    for (Sprite* sprite : added) {
        sprites.push_back(sprite);
    }
    added.clear();
    
    for (auto sprite : removed) {
         delete sprite;
    }
    removed.clear();
}

void GameEngine::render() {
    SDL_RenderClear(mSys.ren);
    //SDL_RenderCopy(mSys.ren, background, &bgCrop, &bgRect );
    for (Sprite* sprite: sprites) {
        sprite->draw(mSys.ren);
    }
    //showScore();
    SDL_RenderPresent(mSys.ren);
    Uint32 nextTick = SDL_GetTicks() + tickInterval;
    int delay = nextTick - SDL_GetTicks();
    if (delay > 0)
        SDL_Delay(delay);
}

bool GameEngine::checkCollisions(Sprite &checkSprite) {
    for (Sprite* sprite : sprites) {
        if (!(sprite == &checkSprite) && sprite->hasHitBox) {
            if (checkSprite.checkCollision(checkSprite.getRect(), sprite->getRect())) {
                return true;
            }
        }
    }
    return false;
}

void GameEngine::setMusic(const char path[]) {
    mSys.setMusic(path);
}
