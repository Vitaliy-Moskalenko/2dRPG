#pragma once

#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include <string>


class Window {

public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void update();

	bool isDone();
	bool isFullScreen();
	bool isFocused();

	EventManager* getEventManager();
	void          toggleFullScreen(EventDetails* details);
	void          close(EventDetails* details = nullptr) { isDone = true; }

	sf::RenderWindow* getRenderWindow() { return &_window; }
	sf::Vector2u      getWindowSize();
	sf::FloatRect     getViewSpace();

	void draw(sf::Drawable& drawable);

private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void create();
	void destroy();

	sf::RenderWindow _window;
	sf::Vector2u     _windowSize;
	std::string      _windowTitle;

	bool             _isDone;
	bool             _isFullScreen;
	bool             _isFocused;

	EventManager     _eventManager;

};

