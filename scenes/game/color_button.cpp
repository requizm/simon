#include "color_button.h"

#include "../../sdl-game-engine/core/window.h"
#include "../../sdl-game-engine/ecs/components/colliders/box_collider_2d.h"

ColorButton::ColorButton(const int width, const int height, const SDL_Color& color)
{
	rect = { 0, 0, width, height };
	this->color = color;
}

void ColorButton::init()
{
	owner->addComponent<BoxCollider2D>(rect.w, rect.h);

	transform = owner->getComponent<Transform>();

	// Draw the ColorButton rectangle
	rectangle = Draw::rectangle(rect, color.r, color.g, color.b, color.a);
}

void ColorButton::update(float dt)
{
	// Set the ColorButton position to the Transform position
	rectangle->rect.x = (int)transform->x;
	rectangle->rect.y = (int)transform->y;
}

void ColorButton::highlight(const SDL_Color& highlightedColor)
{
	rectangle->r = highlightedColor.r;
	rectangle->g = highlightedColor.g;
	rectangle->b = highlightedColor.b;
	rectangle->a = highlightedColor.a;
}

void ColorButton::resetColor()
{
	rectangle->r = color.r;
	rectangle->g = color.g;
	rectangle->b = color.b;
	rectangle->a = color.a;
}