#include "System.hpp"

#ifndef Session_hpp
#define Session_hpp

#include <vector>
#include "Sprite.hpp"

class Session
{
public:
    void add(Sprite* sprite);
    void remove(Sprite* sprite);
    void addBackground(char path[]);
    void setFps(int fps){FPS = fps;}
    void run();
    
private:
    std::vector<Sprite*> sprites;
    std::vector<Sprite*> added, removed;
    int FPS = 60;
    SDL_Texture* background;
};

#endif /* Session_hpp */
