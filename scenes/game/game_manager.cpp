#include "game_manager.h"

#include "../../colors.h"

#include <wase/core/window.h>
#include <thread>
#include <functional>

void GameManager::start()
{
	entityManager = owner->entityManager;

	// Get the ScoreManager and the game Board 
	scoreManager = entityManager->getEntity("ScoreManager")->getComponent<ScoreManager>();
	board = entityManager->getEntity("Board")->getComponent<Board>();

	// Display the 'Press space to start' text
	startText = entityManager->addEntity("StartText");
	startLabel = startText->addComponent<Label>("Press space to start", "opensans", Color::white);
	centerText();

	// Add an audio source
	keyAudio = entityManager->addEntity("KeyAudio")->addComponent<AudioSource>("keysound");
}

void GameManager::startGame()
{
	startLabel->setActive(false);

	isPlaying = true;

	nextTurn();
}

void GameManager::nextTurn()
{
	// Clear the colors vector so new colors can be put in
	colors.clear();

	canGuess = false;
	guessCount = 0;

	// Start putting in the new colors
	std::thread add(std::bind(&GameManager::addColors, this));
	add.detach();
}

void GameManager::gameOver()
{
	scoreManager->reset();
	startLabel->setText("Press space to start over");
	centerText();
	startLabel->setActive(true);
	isPlaying = false;
}

void GameManager::addColors()
{
	// Depending on the score more colors will be shown
	for (int i = 0; i <= scoreManager->getScore(); i++)
	{
		// Pick a random color
		srand((unsigned int)time(NULL));
		int color = rand() % 4 + 1;

		// Start the thread to add the color to the vector
		std::thread add(std::bind(&GameManager::addColor, this, color));
		add.join();
	}

	canGuess = true;
}

void GameManager::addColor(int color)
{
	std::this_thread::sleep_for(std::chrono::milliseconds((long)(timeBetweenColors * 1000)));

	board->highlightColor(color);

	keyAudio->play();

	colors.push_back(color);

	std::this_thread::sleep_for(std::chrono::milliseconds((long)(timeHighlightedColor * 1000)));

	board->resetColors();
}

void GameManager::centerText()
{
	startText->getComponent<Transform>()->setPosition(float((Window::getRect()->w - startLabel->getSize().w) / 2), (float)(Window::getRect()->h - 90));
}