//
//  Background.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Background.hpp"

Background::Background(std::string path, SDL_Rect rect, SDL_Rect crop) : Sprite(rect.x,rect.y, rect.w, rect.h)  {
    this->path = path;
    this->crop = crop;
}

Background::~Background() {
    SDL_DestroyTexture(texture);
}

void Background::tick() {
    crop.x++;
    if (crop.x >= rect.w - 700) {
        crop.x = 0;
    }
}

void Background::generateTexture(SDL_Renderer* ren) {
    this->texture = IMG_LoadTexture(ren, path.c_str());
}

void Background::handleEvent(SDL_Event event) {};

void Background::draw(SDL_Renderer* ren) const {
    SDL_RenderCopy(ren, texture, &crop, &rect);
};
