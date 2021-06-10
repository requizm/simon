#pragma once

#include "../sdl-game-engine/core/scene.h"

#include "game/game_manager.h"

class Game : public Scene
{
public:
	void start();
	void update(float dt);

private:
	GameManager* gameManager;
};