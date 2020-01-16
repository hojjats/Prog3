//
//  BirdGame.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "BirdGame.hpp"
#include <cstdlib>

BirdGame::BirdGame() {
    windowSize = ge.getWindowSize();
}

void BirdGame::run() {
    bool cont = true;
    while (cont) {
        cont = startScreen();
        if (cont) {
            cont = newGame();
            cont = gameOver();
        } 
        
    }
}

bool BirdGame::startScreen() {
    ge.setMusic("Assets/bgm_menu.wav");
    Background* bg = Background::getInstance("Assets/background.png", windowSize, windowSize);
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

bool BirdGame::gameOver()
{
    ge.setMusic("Assets/bgm_gameover.wav");
    Background* bg = Background::getInstance("Assets/backgroundGameOver.png", windowSize, windowSize);
    ge.add(bg);
    Text* endText = Text::getInstance("GAME OVER", "Assets/ARCADE_N.TTF", { 250, 200, 250, 40});
    Text* scoreText = Text::getInstance("SCORE "+std::to_string(scoreVal), "Assets/ARCADE_N.TTF", { 280, 270, 200, 40});
    ge.add(endText);
    ge.add(scoreText);

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
    const int pipeH = 700;
    int y = windowSize.h - gapCenter + (gapDistance / 2);
    Pipe* bottom = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, false, y);
    ge.add(bottom);
    y = -pipeH + (windowSize.h - gapCenter - (gapDistance / 2));
    Pipe* top = Pipe::getInstance("Assets/pipe.png", gapCenter, gapDistance, true, y);
    ge.add(top);
    return top;
}

bool BirdGame::newGame() {
    int gapDistance = 160; // Distance between top- and bottompipe.
    int distanceBetweenPipes = 150; // Pixel interval between pipes.
    int maxPipeGapDelta = 100; // Maximum diff in gap height between consecutive pipes.
    scoreVal = 0;
    ge.setMusic("Assets/bgm_action_4.wav");
    Background* bg = Background::getInstance("Assets/background.png", windowSize, windowSize);
    ge.add(bg);
    Bird* bird = Bird::getInstance("Assets/bird.png", "Assets/bird2.png");
    ge.add(bird);
    
    std::vector<Pipe*> futurePipes;
    Pipe* p = addPipeSection(windowSize.h/2, gapDistance);
    int lastGapHeight = windowSize.h/2;
    futurePipes.push_back(p);
    
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
        if (lastpipe->getRect().x <  windowSize.w - distanceBetweenPipes) {
            int gapDelta = (rand() % maxPipeGapDelta) - (maxPipeGapDelta/2);
            if (lastGapHeight + gapDelta > windowSize.w - gapDistance) {
                gapDelta = -gapDelta;
            }else if (lastGapHeight + gapDelta < 0 + gapDistance) {
                gapDelta = +gapDelta;
            }
            Pipe* p = addPipeSection(lastGapHeight + gapDelta, gapDistance);
            lastGapHeight = lastGapHeight + gapDelta;
            futurePipes.push_back(p);
            
        }
        
        // passed the pipe
        Pipe* firstpipe = futurePipes.front();
        if (firstpipe->getRect().x < bird->getRect().x) {
            score->setRemove(true);
            scoreVal++;
            score = Text::getInstance(std::to_string(scoreVal),"Assets/ARCADE_N.TTF",  {350,50,50,50});
            ge.add(score);
            futurePipes.erase(futurePipes.begin());
        }
    }
    
    ge.clearSprites();
    
    return cont;
}
