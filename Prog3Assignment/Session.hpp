

#ifndef Session_hpp
#define Session_hpp

#include <vector>
#include "Component.hpp"

class Session
{
public:
    void add(Component* component);
    void remove(Component* component);
    void run();
    
private:
    std::vector<Component*> components;
    std::vector<Component*> added, removed;
    
    
};

#endif /* Session_hpp */
