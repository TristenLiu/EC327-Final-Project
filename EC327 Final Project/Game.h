#pragma once

#include <iostream>
#include <vector>	

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Game class that will define all functions and game activities
*/

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Font font;
	sf::Texture background;
	sf::Sprite mainbg;
	sf::Texture button1;
	sf::Sprite lvl1button;
	sf::Texture grid;
	sf::Sprite playGrid;

	/*
	gameState will represent which screen the window will be showing
	1 = title screen
	2 = game board
	3 = game board (in memo mode)
	*/
	int gameState;

	//Private Functions
	void initVar();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Getters
	const bool isRunning() const;

	//Functions
	void renderScreen();
	void pollEvents();
	void update();
	void render();
};
