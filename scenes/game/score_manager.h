#pragma once

#include "../../sdl-game-engine/ecs/component.h"

class ScoreManager : public Component
{
private:
	int score = 0;
};