//
//  BirdGame.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef BirdGame_hpp
#define BirdGame_hpp

#include "GameEngine.hpp"
#include "Bird.hpp"
#include "Pipe.hpp"
#include "Ground.hpp"
#include "Background.hpp"
#include "Text.hpp"

#include <stdio.h>

class BirdGame {
public:
    BirdGame();
    bool startScreen();
    Pipe* addPipeSection(int gapCenter, int gapDistance);
    bool newGame();
    bool gameOver();
    void run();
private:
    GameEngine ge;
    int scoreVal = 0;
};

#endif /* BirdGame_hpp */
