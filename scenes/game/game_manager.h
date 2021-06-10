#pragma once

#include "../../sdl-game-engine/ecs/component.h"

class GameManager : public Component
{
public:
	bool isPlaying = false;
};