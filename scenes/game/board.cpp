#include "board.h"

#include "../../sdl-game-engine/core/window.h"
#include "../../sdl-game-engine/ecs/components/transform.h"
#include "../../sdl-game-engine/ecs/components/colliders/box_collider_2d.h"

Board::Board(const int boxWidth, const int boxHeight, const int margin)
{
	this->boxWidth = boxWidth;
	this->boxHeight = boxHeight;
	this->margin = margin;
}

void Board::init()
{
	entityManager = owner->entityManager;

	// Create entities
	green = entityManager->addEntity("Green");
	red = entityManager->addEntity("Red");
	blue = entityManager->addEntity("Blue");
	yellow = entityManager->addEntity("Yellow");

	// Get window center point
	const int xCenter = (Window::getRect()->w - boxWidth) / 2;
	const int yCenter = (Window::getRect()->h - boxHeight) / 2;

	// Set up the positions
	greenRect = { xCenter - (boxWidth / 2) - margin, yCenter + (boxHeight / 2) + margin, boxWidth, boxHeight };
	redRect = { xCenter + (boxWidth / 2) + margin, yCenter + (boxHeight / 2) + margin, boxWidth, boxHeight };
	blueRect = { xCenter + (boxWidth / 2) + margin, yCenter - (boxHeight / 2) - margin, boxWidth, boxHeight };
	yellowRect = { xCenter - (boxWidth / 2) - margin, yCenter - (boxHeight / 2) - margin, boxWidth, boxHeight };

	// Draw the rectangles
	greenRectangle = Draw::rectangle(greenRect, 0, 140, 0, 255);
	redRectangle = Draw::rectangle(redRect, 140, 0, 0, 255);
	blueRectangle = Draw::rectangle(blueRect, 0, 0, 140, 255);
	yellowRectangle = Draw::rectangle(yellowRect, 140, 140, 0, 255);

	// Configure the rectangle entities
	green->addComponent<BoxCollider2D>(boxWidth, boxHeight);
	green->getComponent<Transform>()->setPosition((float)greenRect.x, (float)greenRect.y);

	red->addComponent<BoxCollider2D>(boxWidth, boxHeight);
	red->getComponent<Transform>()->setPosition((float)redRect.x, (float)redRect.y);

	blue->addComponent<BoxCollider2D>(boxWidth, boxHeight);
	blue->getComponent<Transform>()->setPosition((float)blueRect.x, (float)blueRect.y);

	yellow->addComponent<BoxCollider2D>(boxWidth, boxHeight);
	yellow->getComponent<Transform>()->setPosition((float)yellowRect.x, (float)yellowRect.y);
}

void Board::highlightColor(int color)
{
	switch (color)
	{
	case 1:
		yellowRectangle->r = 255;
		yellowRectangle->g = 255;
		break;

	case 2:
		blueRectangle->b = 255;
		break;

	case 3:
		greenRectangle->g = 255;
		break;

	case 4:
		redRectangle->r = 255;
		break;
	}
}

void Board::resetColors()
{
	redRectangle->r = 140;
	greenRectangle->g = 140;
	blueRectangle->b = 140;
	yellowRectangle->r = 140;
	yellowRectangle->g = 140;
}