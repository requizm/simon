#include "game.h"

#include "../sdl-game-engine/core/input.h"

#include "game/board.h"
#include "game/score_manager.h"

void Game::start()
{
	gameManager = entityManager.addEntity("GameManager")->addComponent<GameManager>();
	entityManager.addEntity("ScoreManager")->addComponent<ScoreManager>();
	entityManager.addEntity("Board")->addComponent<Board>(180, 180, 5);
}

void Game::update(float dt)
{
	if (input::getKeyDown(SDLK_SPACE))
	{
		if (!gameManager->isPlaying)
		{
			// TODO: Run the gameplay
		}
	}
}