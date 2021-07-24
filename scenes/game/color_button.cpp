#include "color_button.h"

#include <wase/core/window.h>

using namespace wase;

ColorButton::ColorButton(const int width, const int height, const SDL_Color& color, const SDL_Color& highlightColor)
{
	rect = { 0, 0, width, height };
	this->color = color;
	this->highlightColor = highlightColor;
}

void ColorButton::start()
{
	collider = owner->addComponent<BoxCollider2D>(rect.w, rect.h);

	transform = owner->getComponent<Transform>();

	// Draw the ColorButton rectangle
	rectangle = Draw::rectangle(rect, color.r, color.g, color.b, color.a);
}

void ColorButton::update(float dt)
{
	// Set the ColorButton position to the Transform position
	rectangle->rect.x = (int)transform->position.x;
	rectangle->rect.y = (int)transform->position.y;

	if (collider->onMouseDown(SDL_BUTTON_LEFT))
		highlight();

	if (collider->onMouseUp(SDL_BUTTON_LEFT))
		resetColor();
}

void ColorButton::highlight()
{
	rectangle->r = highlightColor.r;
	rectangle->g = highlightColor.g;
	rectangle->b = highlightColor.b;
	rectangle->a = highlightColor.a;
}

void ColorButton::resetColor()
{
	rectangle->r = color.r;
	rectangle->g = color.g;
	rectangle->b = color.b;
	rectangle->a = color.a;
}