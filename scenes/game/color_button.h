#pragma once

#include "../../sdl-game-engine/ecs/components/transform.h"
#include "../../sdl-game-engine/ecs/component.h"
#include "../../sdl-game-engine/core/draw.h"

#include <SDL.h>

class ColorButton : public Component
{
public:
	ColorButton(const int width, const int height, const SDL_Color& color);
	void init();
	void update(float dt);
	void highlight(const SDL_Color& color);
	void resetColor();

private:
	Transform* transform;
	int xCenter;
	int yCenter;
	SDL_Rect rect;
	SDL_Color color;
	Rectangle* rectangle;
};