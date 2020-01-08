//
//  Text.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include "Sprite.hpp"

class Text : public Sprite {
public:
    static Text* getInstance(char msg[], char fontPath[], SDL_Rect rect);
    ~Text();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw(SDL_Renderer* ren) const override;
    void generateTexture(SDL_Renderer* ren) override;
private:
    Text(char msg[], char fontPath[], SDL_Rect rect);
    const SDL_Color black = {0,0,0,255};
    const SDL_Color white = {255, 255, 255, 255};
    SDL_Rect shadow;
    TTF_Font* font;
    SDL_Texture* whiteMessage = nullptr;
    SDL_Texture* blackMessage = nullptr;
    char msg[];
};

#endif /* Text_hpp */
