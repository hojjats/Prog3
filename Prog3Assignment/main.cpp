
#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"
#include "GameEngine.hpp"


int main(int argc, char** argv) {
    std::cout<<"GameEngine made"<<std::endl;
    GameEngine game;
    game.addBackground("background.png");
    std::cout<<"Background made"<<std::endl;
    Bird* b = Bird::getInstance(10);
    std::cout<<"Bird made"<<std::endl;
    game.addSprite(b);
    std::cout<<"Sprite made"<<std::endl;
    game.run();
    std::cout<<"run made"<<std::endl;
    return 0;
}
