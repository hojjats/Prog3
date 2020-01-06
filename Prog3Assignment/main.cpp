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
    Bird bird;
    ses.add(&bird);
    ses.addBackground("background.png");
    ses.run();
    return 0;
}
