#pragma once

#include <cstdlib>
#include <ctime>
#include "Window.h"
#include "EventManager.h"
#include "StateManager.h"
#include "TextureManager.h"
#include "EntityManager.h"


class Game {
public:
	Game();
	~Game();

	void update();
	void lateUpdate();
	void render();

	Window*  getWindow();
	sf::Time getElapsed();

private:
	Window        _window;
	StateManager  _stateManager;
	SharedContext _context;
	EntityManager _entityManager;
	TextureManager _textureManager;

	sf::Clock _clock;
	sf::Time  _elapsed;

};

