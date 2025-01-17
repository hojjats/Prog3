#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "System.hpp"
#include "Sprite.hpp"
#include <vector>
#include <string>

class GameEngine
{
public:
    GameEngine();
    void add(Sprite* sprite);
    void remove(Sprite* sprite);
    void addBackground(char path[]);
    void setMusic(const char path[]);
    void setFps(int fps){
        FPS = fps;
        tickInterval = 1000 / FPS;
    }
    void run();
    bool pollEvents();
    void handleEvent(SDL_Event event);
    void update();
    bool checkCollisions(Sprite &sprite);
    void render();
    void clearSprites();
    SDL_Rect getWindowSize();
private:
    System mSys;
    std::vector<Sprite*> sprites;
    std::vector<Sprite*> added, removed;
    int FPS = 100;
    // SDL_Texture* background;
    Uint32 tickInterval = 1000 / FPS;
};






#endif
