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
    Ground();
    ~Ground();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw() const override;
private:
    SDL_Texture* texture = IMG_LoadTexture(sys.ren, "Assets/ground.png");
    SDL_Rect crop;
};

#endif /* Ground_hpp */
