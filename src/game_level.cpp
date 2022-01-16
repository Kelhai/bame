#include "game_level.h"

#include <fstream>
#include <sstream>
#include <iostream>

void GameLevel::load(const char* file, unsigned int levelWidth, unsigned int levelHeight, int number) {
	this->number = number;
	this->bricks.clear();
	unsigned int tileCode;
	GameLevel level;
	std::string line;
	std::ifstream fstream;
	fstream.open(file, std::ifstream::in);
	std::vector<std::vector<unsigned int>> tileData;
	if (fstream) {
		while (std::getline(fstream, line)) {
			std::istringstream sstream(line);
			std::vector<unsigned int> row;
			while (sstream >> tileCode) {
				row.push_back(tileCode);
			}
			tileData.push_back(row);
		}
		if (tileData.size() > 0) {
			this->init(tileData, levelWidth, levelHeight);
		}
	}
}

void GameLevel::draw(SpriteRenderer& renderer) {
	for (GameObject& tile : this->bricks) {
		if (!tile.destroyed) {
			tile.draw(renderer);
		}
	}
}

bool GameLevel::isCompleted() {
	for (GameObject& tile : this->bricks) {
		if (!tile.isSolid && !tile.destroyed) {
			return false;
		}
	}
	return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight) {
	unsigned int height = tileData.size();
	unsigned int width = tileData[0].size();
	unitWidth = levelWidth / static_cast<float>(width);
	unitHeight = levelHeight / height;
	
	for (unsigned int x = 0; x < height; x++) {
		for (unsigned int y = 0; y < width; y++) {
			// if tile exists
			if (tileData[x][y] > 0) {
				// if level is one
				if (this->number == 1) {
					glm::vec2 pos(unitWidth * y, unitHeight * x);
					glm::vec2 size(unitWidth, unitHeight);
					if (tileData[x][y] == 1) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("pizza")));
					} else if (tileData[x][y] == 2) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("rob")));
					} else if (tileData[x][y] == 3) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("sigma")));
					} else if (tileData[x][y] == 4) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("nixon")));
					} else if (tileData[x][y] > 4) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("boat_left")));
					}
				} else if (this->number == 2) {
					glm::vec2 pos(unitWidth * y, unitHeight * x);
					glm::vec2 size(unitWidth, unitHeight);
					if (tileData[x][y] == 1) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("pizza")));
					} else if (tileData[x][y] == 2) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("rob")));
					} else if (tileData[x][y] == 3) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("sigma")));
					} else if (tileData[x][y] == 4) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("nixon")));
					} else if (tileData[x][y] > 4) {
						this->bricks.push_back(GameObject(pos, size, ResourceManager::getTexture("boat_left_s")));
					}
				}
			}
		}
	}
}
