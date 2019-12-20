
#include "Session.hpp"
#include "Component.hpp"
#include "System.hpp"
#include <SDL2/SDL.h>

#define FPS 60

void Session::add(Component* component) {
    added.push_back(component);
}

void Session::remove(Component* component) {
    removed.push_back(component);
}

void Session::run(){
    bool exit = false;
    
    Uint32 tickInterval = 1000 / FPS;
    
    while (!exit) {
        SDL_Event event;
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    for (Component* component: components) {
                        component->mouseDown(event.button.x, event.button.y);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    for (Component* component: components) {
                        component->mouseUp(event.button.x, event.button.y);
                    }
                    break;
            }
        }
        
        for (Component* component : components) {
            component->tick();
        }
        
        for (Component* component : added) {
            components.push_back(component);
        }
        added.clear();
        
        for (Component* component : removed){
            for (std::vector<Component*>::iterator i = components.begin(); i !=components.end();){
                if (*i == component) {
                    i = components.erase(i);
                }
                else
                    i++;
            }
        }
        removed.clear();
        
        SDL_SetRenderDrawColor(sys.ren, 255, 255, 255, 255);
        SDL_RenderClear(sys.ren);
        for (Component* component : components){
            component->draw();
        }
        SDL_RenderPresent(sys.ren);
        
        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    }
    
}


