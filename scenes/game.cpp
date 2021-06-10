#include "game.h"

#include "../sdl-game-engine/core/draw.h"
#include "../sdl-game-engine/core/window.h"
#include "../sdl-game-engine/ecs/entity.h"
#include "../sdl-game-engine/ecs/components/ui/label.h"
#include "../sdl-game-engine/ecs/components/transform.h"

#include <SDL_ttf.h>

#include <iostream>

const int boxWidth = 160;
const int boxHeight = 160;
const int margin = 5;

// Score text variables
Entity* score;
Label* scoreLabel;
Transform* scoreTransform;

// Colored rectangles
Rectangle* green;
Rectangle* red;
Rectangle* blue;
Rectangle* yellow;

void Game::start()
{
	// Get the horizontal and vertical center point of the window
	const int xCenter = (Window::getRect()->w - boxWidth) / 2;
	const int yCenter = (Window::getRect()->h - boxHeight) / 2;

	// Position the rectangles
	SDL_Rect greenRect = { xCenter - (boxWidth / 2) - margin, yCenter + (boxHeight / 2) + margin, boxWidth, boxHeight };
	SDL_Rect redRect = { xCenter + (boxWidth / 2) + margin, yCenter + (boxHeight / 2) + margin, boxWidth, boxHeight };
	SDL_Rect blueRect = { xCenter + (boxWidth / 2) + margin, yCenter - (boxHeight / 2) - margin, boxWidth, boxHeight };
	SDL_Rect yellowRect = { xCenter - (boxWidth / 2) - margin, yCenter - (boxHeight / 2) - margin, boxWidth, boxHeight };

	// Draw the rectangles
	green = Draw::rectangle(greenRect, 0, 255, 0, 255);
	red = Draw::rectangle(redRect, 255, 0, 0, 255);
	blue = Draw::rectangle(blueRect, 0, 0, 255, 255);
	yellow = Draw::rectangle(yellowRect, 255, 255, 0, 255);

	SDL_Color white = { 255, 255, 255, 255 };

	// Create the score text
	score = entityManager.addEntity("ScoreLabel");
	scoreLabel = score->addComponent<Label>("Score: 0", "opensans", white);

	// Position the score text
	scoreTransform = score->getComponent<Transform>();
	scoreTransform->x = (float)((Window::getRect()->w - scoreLabel->getSize()->w) / 2);
	scoreTransform->y = 35;
}