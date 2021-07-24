#pragma once

#include <wase/ecs/components/colliders/box_collider_2d.h>
#include <wase/ecs/components/transform.h>
#include <wase/ecs/component.h>
#include <wase/core/draw.h>
#include <SDL.h>

using namespace wase;

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