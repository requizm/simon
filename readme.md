# Simon

Simon is a memorization game with colored buttons. This game is made with C++ and the [SDL Game Engine](https://github.com/JelleVos1/sdl-game-engine)

![Game preview](images/simon.png)


## Setting up Simon

Requirements:

 - CMake
 - [SDL Game Engine](https://github.com/JelleVos1/sdl-game-engine)
 - SDL2
 - SDL2 image
 - SDL2 mixer
 - SDL2 ttf
 - C++17 or higher

You can use the CMake GUI or you can run the following commands in the commandline:
```
mkdir build
cd build
cmake .. -D SDL_GAME_ENGINE_INCLUDE_DIR=path -D SDL_GAME_ENGINE_LIBRARIES=path
cmake build .
```