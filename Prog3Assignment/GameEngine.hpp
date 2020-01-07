#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "System.hpp"
#include "Session.hpp"
#include "Sprite.hpp"
#include <string>

class GameEngine
{
public:
    GameEngine();
    void addSprite(Sprite* sprite);
    void addBackground(char path[]);
    void setFps(int fps);
    void run();
private:
    Session mSession;
};







#endif