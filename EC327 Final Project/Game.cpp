#include <iostream>
#include "Game.h"

//Private Functions
void Game::initVar()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor
Game::Game()
{
	this->initVar();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Getters
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)	//change this to open a game menu when pressed.
				this->window->close();
			break;
		}
	}
}

//Functions
void Game::update()
{
	//Event Polling
	this->pollEvents();
}

void Game::render()
{
	/*
	Render game objects (window, tiles, scoreboard, etc.)
	*/
	this->window->clear(sf::Color(255, 255, 255, 255)); //change this to actual graphics window

	
	this->window->display();
}
