#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "../glfw/include/GLFW/glfw3.h"
#include <string>
#include <iostream>

SpriteRenderer* renderer;

Game::Game(unsigned int width, unsigned int height) 
		: state(ACTIVE), keys(), width(width), height(height), level(0) {

}

Game::~Game() {
	delete renderer;
}

inline std::string file(const char* fName) {
	// K:/Programming/c/bpa/bpa/
	std::string dir("C:/Users/honor/source/repos/Kelhai/bame/"); // C:/Users/honor/source/repos/Kelhai/bame/
	return (dir + std::string(fName));
}

void Game::init() {
	ResourceManager::loadShader(file("src/vertex.vs").c_str(), file("src/fragment.fs").c_str(), nullptr, "sprite");
	
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width), static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);
	
	ResourceManager::getShader("sprite").use().setInteger("image", 0);
	ResourceManager::getShader("sprite").setMatrix4("projection", projection);

	renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));

	ResourceManager::loadTexture(file("pizza.png").c_str(), true, "pizza");
	ResourceManager::loadTexture(file("rob.png").c_str(), true, "rob");
	ResourceManager::loadTexture(file("background.png").c_str(), true, "background");
	ResourceManager::loadTexture(file("sigma.png").c_str(), true, "sigma");
	ResourceManager::loadTexture(file("nixon.png").c_str(), true, "nixon");
	
	GameLevel one = GameLevel();
	one.load(file("src/one.lvl").c_str(), this->width, this->height, 1);

	this->levels.push_back(one);
	this->level = 0;

	characters.push_back(Character(400, 300, ResourceManager::getTexture("sigma")));
}

void Game::update(float dt) {

}

void Game::processInput(float dt) {
	if (keys[GLFW_KEY_UP]) {
		if (characters.size() > 0) {
			if (characters[0].y > 1)
				characters[0].y -= 1;
		}
	}
	if (keys[GLFW_KEY_DOWN]) {
		if (characters.size() > 0) {
			if (characters[0].y < 563)
				characters[0].y += 1;
		}
	}
	if (keys[GLFW_KEY_LEFT]) {
		if (characters.size() > 0) {
			if (characters[0].x > 1)
				characters[0].x -= 1;
		}
	}
	if (keys[GLFW_KEY_RIGHT]) {
		if (characters.size() > 0) {
			if (characters[0].x < 773)
				characters[0].x += 1;
		}
	}
}

void Game::render() {
	if (this->state == ACTIVE) {
		renderer->drawSprite(ResourceManager::getTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(this->width, this->height), 0.0f);
		this->levels[this->level].draw(*renderer);
		// draw all characters
		for (Character& character : characters) {
			character.draw(*renderer, this->levels[level].unitWidth, this->levels[level].unitHeight);
		}
	} else if (this->state == MENU) {

	}
}
