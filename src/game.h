#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "game_level.h"
#include "character.h"

enum GameState {
	ACTIVE, MENU
};

class Game {
	public:
		GameState state;
		std::vector<GameLevel> levels;
		unsigned int level;
		std::vector<Character> characters;
		bool keys[1024];
		unsigned int width, height;
		unsigned int tileWidth, tileHeight;

		Game(unsigned int width, unsigned int height);
		~Game();

		void init();

		void processInput(float dt);
		void update(float dt);
		void render();
		void addLevel(const char* path, int number);
};

#endif
