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
	//Window Vars
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Font font;
	sf::Texture mainbgTexture, lvl1Texture, lvl2Texture, lvl3Texture, lvl4Texture, lvl5Texture, lvl6Texture, lvl7Texture, lvl8Texture, lvl9Texture, lvl10Texture, marathonTexture;
	sf::Sprite mainbgSprite, lvl1Sprite, lvl2Sprite, lvl3Sprite, lvl4Sprite, lvl5Sprite, lvl6Sprite, lvl7Sprite, lvl8Sprite, lvl9Sprite, lvl10Sprite, marathonSprite;
	sf::Texture gridTexture;
	sf::Sprite gridSprite;
	sf::Text gameTitle;

	//Mouse positions
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	/* gameState will represent which screen the window will be showing
	1 = title screen
	2 = game board
	3 = game board (in memo mode)
	*/
	int gameState;

	//Private Functions
	void initVar();
	void initTexture();
	void initSprite();
	void initText();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Getters
	const bool isRunning() const;

	//Functions
	void updateMousePosition();
	void renderScreen();
	void pollEvents();
	void update();
	void render();
};
