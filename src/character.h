#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "texture.h"
#include "sprite_renderer.h"
#include <string>

class Character {
	public:
		unsigned int x, y;
		std::string name;
		Texture2D texture;
	
		Character() : x(0), y(0), name(std::string("")), texture() {}
		Character(unsigned int x, unsigned int y, Texture2D texture);

	public:
		void draw(SpriteRenderer& renderer, float width, float height);
		void init();
};

#endif
