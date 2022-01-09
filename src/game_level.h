#ifndef GAME_LEVEL_H_
#define GAME_LEVEL_H_

#include "../glad/include/glad/glad.h"
#include "../glm/glm.hpp"
#include <vector>
#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"

class GameLevel {
	public:
		std::vector<GameObject> bricks;
		GameLevel() {}

		void load(const char* file, unsigned int levelWidth, unsigned int levelHeight, int number);

		void draw(SpriteRenderer& renderer);

		bool isCompleted();

	public:
		void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
		float unitWidth;
		float unitHeight;
		int number;
};
	
#endif
