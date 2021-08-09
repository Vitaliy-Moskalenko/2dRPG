#include "Game.h"

Game::Game() :
	_window("Space oddity", sf::Vector2u(1024, 768)),
	_stateManager(&_context),
	_entityManager(&_context, 100) {

	_clock.restart();
	srand((int)time(nullptr));

	_context._window         = &_window;
	_context._eventManager   = _window.getEventManager();
	_context._textureManager = &_textureManager;
	_context._entityManager  = &_entityManager;
}

Game::~Game() {}

void Game::update() {
	_window.update();
	_stateManager.update();
}

void Game::lateUpdate() {
	_stateManager.processRequests();
	_restartClock();
}

void Game::render() {
	sf::RenderWindow* wnd = _window.getRenderWindow();

	wnd->clear(sf::Color::Black);

	_stateManager.draw();

	wnd->display();
}

Window* Game::getWindow() {
	return &_window;
}

sf::Time Game::getElapsed() {
	return _clock.getElapsedTime();
}

void Game::_restartClock() {
	_elapsed = _clock.restart();
}
