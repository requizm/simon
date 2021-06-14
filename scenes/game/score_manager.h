#pragma once

#include <sge/ecs/component.h>
#include <sge/ecs/entity_manager.h>
#include <sge/ecs/components/ui/label.h>
#include <sge/ecs/components/transform.h>
#include <sge/ecs/entity.h>
#include <SDL.h>

class ScoreManager : public Component
{
public:
	void start();
	void increaseScore();
	int getScore();
	void reset();

private:
	EntityManager* entityManager;

	Entity* scoreText;
	Label* scoreLabel;
	Transform* scoreTransform;

	int score = 0;

private:
	void centerText();
	void refreshText();
};