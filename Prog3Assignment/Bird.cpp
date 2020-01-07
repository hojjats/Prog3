

#include "Bird.hpp"

Bird::Bird(): Sprite(320, 220, 40, 40){
    texture = IMG_LoadTexture(sys.ren, "bird.png");
}

Bird::~Bird(){
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(tex1);
    SDL_DestroyTexture(tex2);
}

void Bird::handleEvent(SDL_Event event){
    switch (event.type) {
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    texture = tex1;
                    jumped = true;
                    break;
            }
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    texture = tex2;
                    break;
            }
            break;
    }
}

void Bird::draw() const {
    SDL_Rect rect = getRect();
    SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Bird::tick() {
    const static float gravity = 0.01;
    const static float lift = -0.3;
    velocity += gravity;
    timeSinceJump += 1000 / FPS;
    if (jumped && timeSinceJump > 0.3)
    {
        velocity += lift;
        timeSinceJump = 0;
        jumped = false;
    }
    
    velocity = std::max(velocity, -0.4f);
    velocity = std::min(velocity, 0.4f);
    
    double deltaY = velocity * (1000/60);
    if (rect.y + deltaY < 0) {
        rect.y = 0;
    } else {
        rect.y += deltaY;
    }
}
