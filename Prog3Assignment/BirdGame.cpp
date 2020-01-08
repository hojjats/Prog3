//
//  BirdGame.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "BirdGame.hpp"
#include <cstdlib>

BirdGame::BirdGame() {}

void BirdGame::run() {
    bool cont = true;
    while (cont) {
        cont = startScreen();
        if (cont) {
            cont = newGame();
        }
    }
}

bool BirdGame::startScreen() {
    ge.setMusic("Assets/bgm_menu.wav");
    Background* bg = Background::getInstance("Assets/background.png", { 0,0,700,500}, { 0,0,700,500});
    ge.add(bg);
    Text* startText = Text::getInstance("PRESS SPACE TO START", "Assets/ARCADE_N.TTF", { 100, 200, 500, 40});
    ge.add(startText);
    while (true) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT)
            {
                return false;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                ge.clearSprites();
                return true;
            }
        }
        ge.update();
        ge.render();
    }
}

Pipe* BirdGame::addPipeSection(int gapCenter, int gapDistance)
{
    const int screenH = 500, pipeH = 700;
    int y = screenH - gapCenter + (gapDistance / 2);
    Pipe* bottom = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, false, y);
    ge.add(bottom);
    y = -pipeH + (screenH - gapCenter - (gapDistance / 2));
    Pipe* top = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, true, y);
    ge.add(top);
    return top;
}

bool BirdGame::newGame() {
    ge.setMusic("Assets/bgm_action_4.wav");
    Background* bg = Background::getInstance("Assets/background.png", { 0,0,700,500}, { 0,0,700,500});
    ge.add(bg);
    Bird* bird = Bird::getInstance("Assets/bird.png", "Assets/bird2.png");
    ge.add(bird);
    
    std::vector<Pipe*> futurePipes;
    Pipe* p = addPipeSection(320, 160);
    futurePipes.push_back(p);
    int scoreVal = 0;
    int lastGapHeight = 320;
    
    Ground* ground = Ground::getInstance("Assets/ground.png");
    ge.add(ground);
    Text* score = Text::getInstance(std::to_string(scoreVal),"Assets/ARCADE_N.TTF",  {350,50,50,50});
    ge.add(score);
    bool crashed = false;
    bool cont = true;
    while (!crashed && cont) {
        cont = ge.pollEvents();
        ge.update();
        crashed = ge.checkCollisions(*bird);
        ge.render();
        
        
        // Add new pipes
        Pipe* lastpipe = futurePipes.back();
        if (lastpipe->getRect().x <  700 - 80) {
            int gapDelta = (rand()%60)-20;
            if (lastGapHeight + gapDelta > 700 - 160) {
                gapDelta = -gapDelta;
            }else if (lastGapHeight + gapDelta < 0 + 160) {
                gapDelta = +gapDelta;
            }
            Pipe* p = addPipeSection(lastGapHeight + gapDelta, 160);
            lastGapHeight = lastGapHeight + gapDelta;
            futurePipes.push_back(p);
            
        }
        
        // passed the pipe
        Pipe* firstpipe = futurePipes.front();
        if (firstpipe->getRect().x < bird->getRect().x) {
            ge.remove(score);
            scoreVal++;
            score = Text::getInstance(std::to_string(scoreVal),"Assets/ARCADE_N.TTF",  {350,50,50,50});
            ge.add(score);
            futurePipes.erase(futurePipes.begin());
        }
    }
    
    ge.clearSprites();
    
    return cont;
}
