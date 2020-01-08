#include "GameEngine.hpp"

GameEngine::GameEngine()
{}


void GameEngine::addBackground(char path[])
{
    background = IMG_LoadTexture(mSys.ren,path);
}

void GameEngine::add(Sprite* sprite) {
    sprite->generateTexture(mSys.ren);
    sprite->setFPS(FPS);
    added.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite) {
    removed.push_back(sprite);
}

bool GameEngine::pollEvents() {
    SDL_Event event;
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
                
            }
        }
    } // Poll event
    return true;
}

void GameEngine::handleEvent(SDL_Event event) {
    for (Sprite* sprite : sprites) {
        sprite->handleEvent(event);
    }
}

void GameEngine::update() {
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
    
    for(int i = 0; i < removed.size();i++)
    {
        delete removed[i];
    }
    removed.clear();
    
}

void GameEngine::render() {
    SDL_RenderClear(mSys.ren);
    //SDL_RenderCopy(mSys.ren, background, &bgCrop, &bgRect );
    for (Sprite* sprite: sprites){
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
