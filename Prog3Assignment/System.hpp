#ifndef System_hpp
#define System_hpp

#include <SDL2/SDL.h>
struct System
{
    System();
    ~System();
    
    SDL_Window* win;
    SDL_Renderer* ren;
    

};

 extern System sys;   


#endif /* System_hpp */
