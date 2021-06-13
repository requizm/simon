#pragma once

#include "../sdl-game-engine/core/scene.h"
#include "../sdl-game-engine/ecs/components/colliders/box_collider_2d.h"
#include "../sdl-game-engine/ecs/components/audio_source.h"

#include "game/game_manager.h"
#include "game/score_manager.h"

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