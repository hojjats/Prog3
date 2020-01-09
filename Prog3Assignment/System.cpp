#include "System.hpp"
#include <iostream>

static const int WINDOW_WIDTH = 700;
static const int WINDOW_HEIGHT = 500;

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    win = SDL_CreateWindow("Game", 10, 10, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
    Mix_Volume(-1, MIX_MAX_VOLUME/15);
    // music = Mix_LoadWAV("bgm_menu.wav");
    // Mix_PlayChannel(-1, music, -1);
}

void System::setMusic(const char path[])
{
    Mix_FreeChunk(music);
    music = Mix_LoadWAV(path);
    Mix_PlayChannel(-1, music, -1);
}

System::~System() {
    Mix_FreeChunk(music);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
    music = nullptr;
    win = nullptr;
    ren = nullptr;
    std::cout<<"System Destructor"<<std::endl;
}

// System sys;

