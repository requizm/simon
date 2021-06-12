#pragma once

#include "../../sdl-game-engine/ecs/component.h"
#include "../../sdl-game-engine/ecs/entity_manager.h"
#include "../../sdl-game-engine/ecs/components/ui/label.h"
#include "../../sdl-game-engine/ecs/components/transform.h"
#include "../../sdl-game-engine/ecs/entity.h"

#include <SDL.h>

class ScoreManager : public Component
{
public:
	void init();
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