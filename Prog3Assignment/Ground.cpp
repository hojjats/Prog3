//
//  Ground.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-07.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Ground.hpp"

Ground::Ground() : Sprite(0, 500-41, 700, 41) {
    this->crop = { 0, 0, 700, 41 };
}

Ground::~Ground() {
    SDL_DestroyTexture(texture);
}

void Ground::draw() const {
    SDL_Rect rect = getRect();
    SDL_RenderCopy(sys.ren, texture, &crop, &rect);
}

void Ground::handleEvent(SDL_Event event) {};

void Ground::tick() {
    crop.x++;
    if (crop.x >= 20) {
        crop.x = 0;
    }
}
