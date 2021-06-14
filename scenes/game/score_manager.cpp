#include "score_manager.h"

#include "../../colors.h"

#include <sge/core/window.h>
#include <sstream>

void ScoreManager::start()
{
	entityManager = owner->entityManager;

	// Display the score text
	scoreText = entityManager->addEntity("ScoreText");
	scoreLabel = scoreText->addComponent<Label>("Score: 0", "opensans", Color::white);
	scoreTransform = scoreText->getComponent<Transform>();

	centerText();
}

void ScoreManager::increaseScore()
{
	score++;
	refreshText();
}

int ScoreManager::getScore()
{
	return score;
}

void ScoreManager::reset()
{
	score = 0;
	refreshText();
}

void ScoreManager::centerText()
{
	scoreTransform->setPosition(float((Window::getRect()->w - scoreLabel->getSize()->w) / 2), 20.0f);
}

void ScoreManager::refreshText()
{
	std::stringstream ss;
	ss << "Score: " << score;
	scoreLabel->setText(ss.str());

	centerText();
}
