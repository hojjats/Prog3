//
//  Pipe.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-06.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Pipe.hpp"

Pipe* Pipe::getInstance(std::string path, int gapCenter, int gapDistance, bool isTop, int y)
{
    return new Pipe(path,gapCenter,gapDistance,isTop,y);
}

Pipe::Pipe(std::string path, int gapCenter, int gapDistance, bool isTop, int y): Sprite(700,y,30,700,true) {
    this->path = path;
    this->gapCenter = gapCenter;
    this->gapDistance = gapDistance;
    this->isTop = isTop;
    this->shouldRemove = false;
    if (!isTop) {
        int h =  gapCenter - (gapDistance/2) - 41;
        this->crop = {0,0, 30, h};
        rect.h = h;
    }
}

Pipe::~Pipe() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
    //std::cout<<"Pipe Destructor"<<std::endl;
}

void Pipe::generateTexture(SDL_Renderer *ren) {
    this->texture = IMG_LoadTexture(ren, path.c_str());
}

void Pipe::draw(SDL_Renderer* ren) const {
    SDL_Rect rect = getRect();
    if (isTop) {
        // Top pipe
        SDL_Point center = { rect.w/2, rect.h/2 }; // the center where the texture will be rotated.
        SDL_RenderCopyEx(ren, texture, NULL, &rect, 180.0f, &center, SDL_FLIP_HORIZONTAL);
    } else {
        // Bottom pipe
        SDL_RenderCopy(ren, texture, &crop, &rect);
    }
}

void Pipe::handleEvent(SDL_Event event) {};

void Pipe::tick() {
    rect.x--;
    if(rect.x < -30)
    {
       setRemove(true);
    }
}
