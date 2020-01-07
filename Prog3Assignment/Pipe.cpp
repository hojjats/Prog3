//
//  Pipe.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-06.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Pipe.hpp"

Pipe::Pipe(int gapCenter, int gapDistance, bool isTop, int y): Sprite(700,y,30,700) {
    this->gapCenter = gapCenter;
    this->gapDistance = gapDistance;
    this->isTop = isTop;
}

Pipe::~Pipe() {
    SDL_DestroyTexture(texture);
}

void Pipe::draw() const {
    SDL_Rect rect = getRect();
    if (isTop) {
        // Top pipe
        SDL_Point center = { rect.w/2, rect.h/2 }; // the center where the texture will be rotated.
        SDL_RenderCopyEx(sys.ren, texture, NULL, &rect, 180.0f, &center, SDL_FLIP_HORIZONTAL);
    } else {
        // Bottom pipe
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
}

void Pipe::handleEvent(SDL_Event event) {};

void Pipe::tick() {
    rect.x--;
}
