
#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"

Session ses;

int main(int argc, char** argv) {
    Bird bird;
    ses.add(dynamic_cast<Sprite*>(&bird));
    ses.run();
    return 0;
}
