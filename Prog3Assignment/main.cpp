#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"
#include "GameEngine.hpp"

Session ses;

int main(int argc, char** argv) {
    GameEngine game;
    Bird bird;
    game.addSprite(&bird);
    game.addBackground("background.png");
    game.run();
    return 0;
}
