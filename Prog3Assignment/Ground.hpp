//
//  Ground.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-07.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef Ground_hpp
#define Ground_hpp

#include "Sprite.hpp"
#include <stdio.h>

class Ground : public Sprite {
public:
    Ground(std::string path);
    ~Ground();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw(SDL_Renderer* ren) const override;
    void generateTexture(SDL_Renderer* ren) override;
private:
    SDL_Texture* texture = nullptr;
    SDL_Rect crop;
    std::string path;
};

#endif /* Ground_hpp */