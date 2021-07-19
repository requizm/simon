#include "board.h"

#include "../../colors.h"
#include "color_button.h"

#include <wase/core/window.h>
#include <wase/ecs/components/transform.h>
#include <wase/ecs/components/colliders/box_collider_2d.h>

Board::Board(const int boxWidth, const int boxHeight, const int margin)
{
	this->boxWidth = boxWidth;
	this->boxHeight = boxHeight;
	this->margin = margin;
}

void Board::start()
{
	entityManager = owner->entityManager;

	// Calculate the positions for the color buttons
	const int xCenter = (Window::getRect()->w - boxWidth) / 2;
	const int yCenter = (Window::getRect()->h - boxHeight) / 2;
	const float right = (float)(xCenter + (boxWidth / 2) + margin);
	const float left = (float)(xCenter - (boxWidth / 2) - margin);
	const float top = (float)(yCenter + (boxHeight / 2) + margin);
	const float bottom = (float)(yCenter - (boxHeight / 2) - margin);

	// Create the color button entities
	red = entityManager->addEntity("Red");
	green = entityManager->addEntity("Green");
	blue = entityManager->addEntity("Blue");
	yellow = entityManager->addEntity("Yellow");

	// Set the positions
	red->getComponent<Transform>()->setPosition(right, bottom);
	green->getComponent<Transform>()->setPosition(left, bottom);
	blue->getComponent<Transform>()->setPosition(right, top);
	yellow->getComponent<Transform>()->setPosition(left, top);

	// Add the ColorButton component to all the color button entities
	redButton = red->addComponent<ColorButton>(boxWidth, boxHeight, Color::red, Color::redHighlighted);
	greenButton = green->addComponent<ColorButton>(boxWidth, boxHeight, Color::green, Color::greenHighlighted);
	blueButton = blue->addComponent<ColorButton>(boxWidth, boxHeight, Color::blue, Color::blueHighlighted);
	yellowButton = yellow->addComponent<ColorButton>(boxWidth, boxHeight, Color::yellow, Color::yellowHighlighted);
}

void Board::highlightColor(int color)
{
	switch (color)
	{
	case 1:
		yellowButton->highlight();
		break;

	case 2:
		blueButton->highlight();
		break;

	case 3:
		greenButton->highlight();
		break;

	case 4:
		redButton->highlight();
		break;
	}
}

void Board::resetColors()
{
	redButton->resetColor();
	greenButton->resetColor();
	blueButton->resetColor();
	yellowButton->resetColor();
}