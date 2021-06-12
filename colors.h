#pragma once

#include <SDL.h>

struct Color
{
	// Colors
	static const SDL_Color white;
	static const SDL_Color red;
	static const SDL_Color green;
	static const SDL_Color blue;
	static const SDL_Color yellow;

	// Highlighted colors
	static const SDL_Color redHighlighted;
	static const SDL_Color greenHighlighted;
	static const SDL_Color blueHighlighted;
	static const SDL_Color yellowHighlighted;
};