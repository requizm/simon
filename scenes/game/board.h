#pragma once

#include "../../sdl-game-engine/ecs/component.h"
#include "../../sdl-game-engine/core/draw.h"
#include "../../sdl-game-engine/ecs/entity_manager.h"

#include <SDL.h>

class Board : public Component
{
public:
	Board(const int boxWidth, const int boxHeight, const int margin = 0);
	void init();
	void highlightColor(int color);
	void resetColors();

private:
	int boxWidth, boxHeight, margin;

	EntityManager* entityManager;

	Entity* green;
	Entity* red;
	Entity* blue;
	Entity* yellow;

	Rectangle* greenRectangle;
	Rectangle* redRectangle;
	Rectangle* blueRectangle;
	Rectangle* yellowRectangle;

	SDL_Rect greenRect;
	SDL_Rect redRect;
	SDL_Rect blueRect;
	SDL_Rect yellowRect;
};