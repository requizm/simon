#pragma once

#include <wase/ecs/component.h>
#include <wase/ecs/entity_manager.h>
#include <wase/ecs/components/ui/label.h>
#include <wase/ecs/components/transform.h>
#include <wase/ecs/entity.h>
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