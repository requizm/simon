#include "game.h"

#include "../sdl-game-engine/core/input.h"

#include "game/board.h"
#include "game/score_manager.h"

void Game::start()
{
	// Create a ScoreManager
	scoreManager = entityManager.addEntity("ScoreManager")->addComponent<ScoreManager>();
	entityManager.addEntity("Board")->addComponent<Board>(180, 180, 5);

	// Create a GameManager
	gameManager = entityManager.addEntity("GameManager")->addComponent<GameManager>();

	// Get all the color button colliders
	redCollider = entityManager.getEntity("Red")->getComponent<BoxCollider2D>();
	blueCollider = entityManager.getEntity("Blue")->getComponent<BoxCollider2D>();
	greenCollider = entityManager.getEntity("Green")->getComponent<BoxCollider2D>();
	yellowCollider = entityManager.getEntity("Yellow")->getComponent<BoxCollider2D>();
}

void Game::update(float dt)
{
	// Start the game when space is pressed
	if (input::getKeyDown(SDLK_SPACE))
	{
		if (!gameManager->isPlaying)
		{
			gameManager->start();
		}
	}

	// Get the mouse input for the color buttons
	guessInput();
}

void Game::guessInput()
{
	if (!gameManager->canGuess)
		return;

	if (yellowCollider->onMouseDown(SDL_BUTTON_LEFT))
		guess(1);

	if (blueCollider->onMouseDown(SDL_BUTTON_LEFT))
		guess(2);

	if (greenCollider->onMouseDown(SDL_BUTTON_LEFT))
		guess(3);

	if (redCollider->onMouseDown(SDL_BUTTON_LEFT))
		guess(4);
}

void Game::guess(int color)
{
	// If the pressed color button is not the next one in the array
	if (gameManager->colors[gameManager->guessCount] != color)
	{
		gameManager->gameOver();
		return;
	}

	gameManager->guessCount++;

	// If all the colors in the array are pressed go to the next turn
	if (gameManager->colors.size() == gameManager->guessCount)
	{
		scoreManager->increaseScore();
		gameManager->nextTurn();
	}
}