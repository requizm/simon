#pragma once

#include "game/game_manager.h"
#include "game/score_manager.h"

#include <wase/core/scene.h>
#include <wase/ecs/components/colliders/box_collider_2d.h>
#include <wase/ecs/components/audio_source.h>

using namespace wase;

class Game : public Scene
{
public:
	void start();
	void update(float dt);

private:
	GameManager* gameManager;
	ScoreManager* scoreManager;

	BoxCollider2D* redCollider;
	BoxCollider2D* blueCollider;
	BoxCollider2D* greenCollider;
	BoxCollider2D* yellowCollider;

private:
	void guessInput();
	void guess(int color);
};