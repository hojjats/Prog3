#ifndef System_hpp
#define System_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
struct System
{
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    Mix_Chunk* music;

    void setMusic(const char path[]);
};

// extern System sys;   


#endif /* System_hpp */
