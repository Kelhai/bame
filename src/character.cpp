#include "character.h"
#include "../glm/vec2.hpp"
#include <iostream>

Character::Character(unsigned int x, unsigned int y, Texture2D texture) : x(x), y(y), texture(texture) {

}

void Character::draw(SpriteRenderer& renderer, float width, float height) {
	glm::vec2 position(x, y);
	renderer.drawSprite(texture, position, glm::vec2(width, height), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void Character::init() {

}

std::pair<int, int> Character::getTile(int screenWidth, int screenHeight, int tileWidth, int tileHeight) {
	std::pair<int, int> tile;
	//tile.first = width / this->x;
	return tile;
}
