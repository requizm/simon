#include "scenes/game.h"

#include <wase/core/engine.h>
#include <wase/core/managers/scene_manager.h>
#include <wase/core/managers/resource_manager.h>
#include <memory>

int main(int argc, char* argv[])
{
    // Initialize engine
    Engine::getInstance()->init("Simon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, NULL);

    // Load resources
    ResourceManager::loadFont("opensans", "fonts/OpenSans-Regular.ttf", 42);
    ResourceManager::loadAudio("keysound", "sounds/pianokey.wav");

    // Load scenes
    SceneManager::addScene("simon", std::make_shared<Game>());

    // Run the game
    Engine::getInstance()->run("simon");

    return 0;
}