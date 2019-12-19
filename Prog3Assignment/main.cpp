
#include <iostream>
#include "Session.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "System.hpp"

Session ses;

class Bullet : public Component {
public:
    static Bullet* getInstance(int x) {
        return new Bullet(x);
    }
    Bullet(int x) : Component(x, 500, 40,40){
        //texture = IMG_LoadTexture(sys.ren, filePath);
    }
    ~Bullet() {
        SDL_DestroyTexture(texture);
    }
    void draw() const {
        //Needs fix
        //SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
    }
    void tick() {
        counter++;
        if (rect.y <= 0)
            ses.remove(this);
        else if (counter % 10 == 0)
            rect.y--;
    }
private:
    SDL_Texture* texture;
    int counter = 0;
};

class Pistol : public Component {
public:
    Pistol() :Component(0, 0, 0, 0) {}
    void draw() const {}
    void tick() {}
    void mouseDown(int x, int y) {
        Bullet* b = Bullet::getInstance(x);
        ses.add(b);
    }
};

int main(int argc, char** argv) {
    Pistol* pistol = new Pistol();
    ses.add(pistol);
    ses.run();
    return 0;
}
