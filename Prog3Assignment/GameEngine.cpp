#include "GameEngine.hpp"

GameEngine::GameEngine()
{}

void GameEngine::addSprite(Sprite* sprite)
{
    mSession.add(sprite);
}

void GameEngine::addBackground(char path[])
{
    mSession.addBackground(path);
}

void GameEngine::setFps(int fps)
{
    mSession.setFps(fps);
}

void GameEngine::run()
{
    mSession.run();
}