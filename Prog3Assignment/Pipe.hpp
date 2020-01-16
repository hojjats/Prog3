//
//  Pipe.hpp
//  Prog3Assignment
//
//  Created by Gustav Junedahl on 2020-01-06.
//  Copyright © 2020 Hojjat Seyed. All rights reserved.
//

#ifndef Pipe_hpp
#define Pipe_hpp

#include "Sprite.hpp"
#include <stdio.h>

class Pipe : public Sprite {
public:
    static Pipe* getInstance(std::string path,int gapHeight,int gapWidth,bool isTop,int y);
    ~Pipe();
    void handleEvent(SDL_Event event) override;
    void tick() override;
    void draw(SDL_Renderer* ren) const override;
    void generateTexture(SDL_Renderer* ren) override;
private:
    Pipe(std::string path, int gapHeight, int gapWidth, bool isTop, int y);
    SDL_Texture* texture = nullptr;
    int gapCenter;
    int gapDistance;
    int isTop;
    std::string path;
    SDL_Rect crop;
    bool shouldRemove;
};

#endif /* Pipe_hpp */
