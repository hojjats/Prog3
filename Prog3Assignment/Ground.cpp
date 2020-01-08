//
//  Ground.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-07.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Ground.hpp"

Ground* Ground::getInstance(std::string path)
{
    return new Ground(path);
}

Ground::Ground(std::string path) : Sprite(0, 500-41, 700, 41, true) {
    this->path = path;
    this->crop = { 0, 0, 700, 41 };
}

Ground::~Ground() {
    SDL_DestroyTexture(texture);
}

void Ground::draw(SDL_Renderer* ren) const {
    SDL_Rect rect = getRect();
    SDL_RenderCopy(ren, texture, &crop, &rect);
}

void Ground::generateTexture(SDL_Renderer *ren) {
    this->texture = IMG_LoadTexture(ren, path.c_str());
}

void Ground::handleEvent(SDL_Event event) {};

void Ground::tick() {
    crop.x++;
    if (crop.x >= 20) {
        crop.x = 0;
    }
}
