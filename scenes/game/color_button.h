#pragma once

#include "../../sdl-game-engine/ecs/components/colliders/box_collider_2d.h"
#include "../../sdl-game-engine/ecs/components/transform.h"
#include "../../sdl-game-engine/ecs/component.h"
#include "../../sdl-game-engine/core/draw.h"

#include <SDL.h>

class GameManager;

class ColorButton : public Component
{
public:
	ColorButton(const int width, const int height, const SDL_Color& color, const SDL_Color& highlightColor);
	void start();
	void update(float dt);
	void highlight();
	void resetColor();

private:
	Transform* transform;
	BoxCollider2D* collider;

	int xCenter;
	int yCenter;

	SDL_Rect rect;
	SDL_Color color;
	SDL_Color highlightColor;

	Rectangle* rectangle;
};