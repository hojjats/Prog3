

#ifndef Session_hpp
#define Session_hpp

#include <vector>
#include "Sprite.hpp"

class Session
{
public:
    void add(Sprite* sprite);
    void remove(Sprite* sprite);
    void run();
    
private:
    std::vector<Sprite*> sprites;
    std::vector<Sprite*> added, removed;
    
    
};

#endif /* Session_hpp */
