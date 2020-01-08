#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"
#include "Sprite.hpp"
#include "Bird.hpp"
#include "Pipe.hpp"
#include "Ground.hpp"
#include "GameEngine.hpp"
#include "BirdGame.hpp"

Session ses;

int main(int argc, char **argv)
{
    BirdGame b;
    b.start();
    
    //Bird bird;
    //ses.add(&bird);
    //    ses.addBackground("Assets/background.png");
    //
    //    addPipeSection(250, 300);
    //    Ground ground;
    //    ses.add(&ground);
    //    ses.run();
    return 0;
}
