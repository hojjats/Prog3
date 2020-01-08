//
//  BirdGame.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "BirdGame.hpp"

void addPipeSection(int gapCenter, int gapDistance);

void BirdGame::start() {
    GameEngine ge;
    Bird* bird = Bird::getInstance("Assets/bird.png", "Assets/bird2.png");
    Ground* ground = Ground::getInstance("Assets/ground.png");
    Background* bg = Background::getInstance("Assets/background.png", { 0,0,700,500}, { 0,0,700,500});
    Text* startText = Text::getInstance("PRESS SPACE TO START", "Assets/ARCADE_N.TTF", { 100, 200, 500, 40});
    Text* score = Text::getInstance("0","Assets/ARCADE_N.TTF",  {350,50,50,50});
    
    ge.add(bg);
    ge.add(startText);
    
    
    bool startGame = false;
    bool exit = false;
    while (!exit) {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                exit = true;
            }
            
            if(!startGame && event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                        startGame = true;
                        ge.remove(startText);
                        setupGame(&ge, bird);
                }
            }
            if (startGame) {
                ge.handleEvent(event);
            }
        }
        ge.update();
        bool crash = ge.checkCollisions(*bird);
        if (crash) {
            exit = true;
        }
        ge.render();
    }
}

void BirdGame::setupGame(GameEngine* ge, Bird* bird) {
    ge->add(bird);
    addPipeSection(ge, 200, 200);
    Ground* ground = Ground::getInstance("Assets/ground.png");
    ge->add(ground);
    Text* score = Text::getInstance("0","Assets/ARCADE_N.TTF",  {350,50,50,50});
    ge->add(score);
}


void BirdGame::addPipeSection(GameEngine* ge, int gapCenter, int gapDistance)
{
    const int screenH = 500, pipeH = 700;
    int y = screenH - gapCenter + (gapDistance / 2);
    Pipe* bottom = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, false, y);
    ge->add(bottom);
    y = -pipeH + (screenH - gapCenter - (gapDistance / 2));
    Pipe* top = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, true, y);
    ge->add(top);
}
