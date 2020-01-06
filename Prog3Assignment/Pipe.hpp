//
//  Pipe.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-06.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef Pipe_hpp
#define Pipe_hpp

#include "Sprite.hpp"
#include <stdio.h>

class Pipe : public Sprite {
public:
    Pipe(int gapHeight, int gapWidth, bool isTop, int y);
    ~Pipe();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw() const override;
private:
    SDL_Texture* texture = IMG_LoadTexture(sys.ren, "pipe.png");
    int gapCenter;
    int gapDistance;
    int isTop;
};

#endif /* Pipe_hpp */
