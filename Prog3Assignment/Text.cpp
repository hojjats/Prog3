//
//  Text.cpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#include "Text.hpp"
#include <cstring>

Text* Text::getInstance(std::string msg, const char fontPath[], SDL_Rect rect)
{
    return new Text(msg,fontPath,rect);
}

Text::Text(std::string msg, const char fontPath[], SDL_Rect rect) : Sprite(rect.x, rect.y, rect.w, rect.h,false) {
    font = TTF_OpenFont(fontPath, 24);
    msg = msg;

    shadow = {
        rect.x - 2,
        rect.y + 2,
        rect.w,
        rect.h
    };
}

Text::~Text() {
    SDL_DestroyTexture(whiteMessage);
    SDL_DestroyTexture(blackMessage);
    TTF_CloseFont(font);
}

void Text::handleEvent(SDL_Event event) {};

void Text::tick() {};

void Text::generateTexture(SDL_Renderer *ren) {
    SDL_Surface* whiteText = TTF_RenderText_Solid(font,msg.c_str(),white);
    SDL_Surface* blackText = TTF_RenderText_Solid(font,msg.c_str(),black);
    whiteMessage = SDL_CreateTextureFromSurface(ren,whiteText);
    blackMessage = SDL_CreateTextureFromSurface(ren,blackText);
    SDL_FreeSurface(whiteText);
    SDL_FreeSurface(blackText);
}

void Text::draw(SDL_Renderer* ren) const {
    SDL_RenderCopy(ren,blackMessage,NULL,&shadow);
    SDL_RenderCopy(ren,whiteMessage,NULL,&rect);
};
