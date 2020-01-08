#ifndef System_hpp
#define System_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
struct System
{
    System();
    ~System();
    
    SDL_Window* win = nullptr;
    SDL_Renderer* ren = nullptr;
    Mix_Chunk* music = nullptr;

    void setMusic(const char path[]);
};

// extern System sys;   


#endif /* System_hpp */
