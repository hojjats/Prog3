# Flappybird clone

In this game you play as a bird, your mission is to avoid crashing into the ground or the pipes. The bird (you) is of course pulled down by gravity, you can fight the gravity by flapping your wings (using SPACE). For every pipe that you manage to fly through, you will be rewarded with one point! Fly safe and enjoy!

Build the game using: g++  {Source code folder}/**.cpp -I{path to SDL Include} -L{path to SDL lib} -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -o {Source code folder}/main

while standing one folder above the source code folder and necessary .dll files (SDL2_ttf, SDL2_image and SDL2_mixer) is copied into the source code folder.

Paths to assesets in the game are relative to the source code folder and should work if they are not moved.
