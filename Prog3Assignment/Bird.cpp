
#include "Bird.hpp"

Bird* Bird::getInstance(std::string path1, std::string path2)
{
    return new Bird(path1,path2);
}

Bird::Bird(std::string path1, std::string path2): Sprite(320, 220, 40, 40, true){
    this->path1 = path1;
    this->path2 = path2;
}

Bird::~Bird(){
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(tex1);
    SDL_DestroyTexture(tex2);
    texture = nullptr;
    tex1 = nullptr;
    tex2 = nullptr;
    //std::cout<<"Bird Destructor"<<std::endl;
}

void Bird::generateTexture(SDL_Renderer *ren) {
    this->tex1 = IMG_LoadTexture(ren, path1.c_str());
    this->tex2 = IMG_LoadTexture(ren, path2.c_str());
    this->texture = tex1;
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

void Bird::draw(SDL_Renderer* ren) const {
    SDL_Rect rect = getRect();
    SDL_RenderCopy(ren, texture, NULL, &rect);
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
