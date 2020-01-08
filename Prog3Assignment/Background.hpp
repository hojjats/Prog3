//
//  Background.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-08.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>
#include "Sprite.hpp"

class Background : public Sprite {
public:
    Background(std::string path, SDL_Rect rect, SDL_Rect crop);
    ~Background();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw(SDL_Renderer* ren) const override;
    void generateTexture(SDL_Renderer* ren) override;
private:
    SDL_Texture* texture = nullptr;
    SDL_Rect crop;
    std::string path;
};

#endif /* Background_hpp */
