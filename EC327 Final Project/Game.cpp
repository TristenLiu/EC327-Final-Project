#include <iostream>
#include "Game.h"

//Private Functions
void Game::initVar()
{
	this->window = nullptr;
	this->font.loadFromFile("fonts/arial.ttf");
	this->background.loadFromFile("images/checkerboard2.png");
	this->mainbg.setTexture(background);
	this->button1.loadFromFile("images/button_select_level.png");
	this->lvl1button.setTexture(button1);
	this->grid.loadFromFile("images/grid_6.png");
	this->playGrid.setTexture(grid);
	this->playGrid.setScale(.1f, .1f);
	this->playGrid.setPosition(200.f, 200.f);

	this->gameState = 1; /*First game state is title menu*/
}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 1280;

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

//Functions

void Game::updateMousePosition() 
{
	//update the mouse position relative to window
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
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

			//temporary keyboard inputs for window changing
			else if (this->gameState == 2)
			{
				if (this->ev.key.code == sf::Keyboard::Enter) //pressing Enter on the game brings you to the 'memo state'
				{
					this->gameState = 3;
				}
				else if (this->ev.key.code == sf::Keyboard::Tab) //pressing Tab will return to the title screen
				{
					this->gameState = 1;
				}
			}
			else if (this->gameState == 3)
			{
				if (this->ev.key.code == sf::Keyboard::RShift) //pressing RShift in the 'memo state' brings you to back to the game
				{
					this->gameState = 2;
				}
			}

		//Replace above temporary code with this when proper buttons are added
		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (this->gameState == 1)
				{
					if (this->lvl1button.getGlobalBounds().contains(this->mousePosView)) //Check if if mouse is over lvl 1 button when clicked
					{
						this->gameState = 2;
					}
				}
			}
		}
	}
}

void Game::update()
{
	//Event Polling
	this->pollEvents();
	this->updateMousePosition();
}

void Game::renderScreen()
{
	this->window->draw(this->mainbg);

	if (this->gameState == 1) //game is at main menu
	{
		//display title logo 
		//display buttons to select the mode (via mouse, can maybe include using the keyboard arrow keys as well)
		//should we have a backdrop image?

		sf::Text gameTitle;
		gameTitle.setString("Voltorb Flip V2");
		gameTitle.setFont(font);
		gameTitle.setCharacterSize(80);
		gameTitle.setFillColor(sf::Color::Blue);
		gameTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
		gameTitle.setPosition(250.f, 50.f);

		lvl1button.setPosition(200.f, 200.f);

		this->window->draw(gameTitle);
		this->window->draw(lvl1button);
	}

	else if (this->gameState == 2)
	{
		sf::Text title; //title should show current level (and current total accumulated score if in marathon mode)
		title.setFont(font);
		title.setCharacterSize(60);
		title.setFillColor(sf::Color::Blue);
		title.setStyle(sf::Text::Bold);
		title.setString("Level"); //stringstream
		title.setPosition(200.f, 100.f);
		this->window->draw(title);



		/*
		On the left we should have:
		- display score for the current level being played
		- memo where player can mark cards

		on the unused square on grid, put a quit button?

		*/


		this->window->draw(playGrid);

		//may need a separate state for when memo is being used
	}

	else if (this->gameState == 3)
	{
		sf::Text title; //title should show current level (and current total accumulated score if in marathon mode)
		title.setFont(font);
		title.setCharacterSize(70);
		title.setFillColor(sf::Color::Magenta);
		title.setStyle(sf::Text::Bold);
		title.setString("Memo State"); //stringstream
		title.setPosition(300, 100);
		this->window->draw(title);

		/*
		On the left we should have:
		- display score for the current level being played
		- memo where player can mark cards
		- consider tile class that can store values and textures, memo marks can be a variable in tile class

		on the unused square on grid, put a quit button?

		*/


		this->window->draw(playGrid);

		//may need a separate state for when memo is being used
	}
}

void Game::render()
{
	//Render game objects(window, tiles, scoreboard, etc.)
	this->window->clear(sf::Color::White); 

	this->renderScreen();

	this->window->display();
}
