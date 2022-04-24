#include <iostream>
#include "Game.h"

//Private Functions
void Game::initVar()
{
	this->window = nullptr;
	this->font.loadFromFile("fonts/arial.ttf");

	this->gameState = 1; /*First game state is title menu*/
}

void Game::initTexture()
{
	//Load Textures from image folder
	this->mainbgTexture.loadFromFile("images/checkerboard2.png");
	this->lvl1Texture.loadFromFile("images/Level1.png");
	this->lvl2Texture.loadFromFile("images/Level2.png");
	this->lvl3Texture.loadFromFile("images/Level3.png");
	this->lvl4Texture.loadFromFile("images/Level4.png");
	this->lvl5Texture.loadFromFile("images/Level5.png");
	this->lvl6Texture.loadFromFile("images/Level6.png");
	this->lvl7Texture.loadFromFile("images/Level7.png");
	this->lvl8Texture.loadFromFile("images/Level8.png");
	this->lvl9Texture.loadFromFile("images/Level9.png");
	this->lvl10Texture.loadFromFile("images/Level10.png");
	this->marathonTexture.loadFromFile("images/Marathon.png");
	this->gridTexture.loadFromFile("images/grid_6.png");
}

void Game::initSprite()
{
	//Set textures to usable Sprites
	//Each checkerboard square is 150px
	this->mainbgSprite.setTexture(mainbgTexture);

	//button sprites are 256x128 px
	this->lvl1Sprite.setTexture(lvl1Texture);			this->lvl1Sprite.setScale(.50f, .50f);
	this->lvl2Sprite.setTexture(lvl2Texture);			this->lvl2Sprite.setScale(.50f, .50f);
	this->lvl3Sprite.setTexture(lvl3Texture);			this->lvl3Sprite.setScale(.50f, .50f);
	this->lvl4Sprite.setTexture(lvl4Texture);			this->lvl4Sprite.setScale(.50f, .50f);
	this->lvl5Sprite.setTexture(lvl5Texture);			this->lvl5Sprite.setScale(.50f, .50f);
	this->lvl6Sprite.setTexture(lvl6Texture);			this->lvl6Sprite.setScale(.50f, .50f);
	this->lvl7Sprite.setTexture(lvl7Texture);			this->lvl7Sprite.setScale(.50f, .50f);
	this->lvl8Sprite.setTexture(lvl8Texture);			this->lvl8Sprite.setScale(.50f, .50f);
	this->lvl9Sprite.setTexture(lvl9Texture);			this->lvl9Sprite.setScale(.50f, .50f);
	this->lvl10Sprite.setTexture(lvl10Texture);			this->lvl10Sprite.setScale(.50f, .50f);
	this->marathonSprite.setTexture(marathonTexture);	this->marathonSprite.setScale(0.50f, 0.50f);
	this->gridSprite.setTexture(gridTexture);			this->gridSprite.setScale(.1f, .1f);		this->gridSprite.setPosition(200.f, 200.f);
}

void Game::initText()
{
	this->gameTitle.setString("Voltorb Flip V2");
	this->gameTitle.setFont(font);
	this->gameTitle.setCharacterSize(80);
	this->gameTitle.setFillColor(sf::Color::Blue);
	this->gameTitle.setStyle(sf::Text::Bold);
}

void Game::initWindow()
{
	this->videoMode.height = 750;
	this->videoMode.width = 1200;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor
Game::Game()
{
	this->initVar();
	this->initTexture();
	this->initSprite();
	this->initText();
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
					//Check which button the mouse is over if the mouse is left-clicked
					//ADD LEVEL FUNCTIONALITY / LEVEL GENERATION
					if (this->lvl1Sprite.getGlobalBounds().contains(this->mousePosView)) { 
						this->gameState = 2;
					}
					else if (this->lvl2Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl3Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl4Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl5Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl6Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl7Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl8Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl9Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->lvl10Sprite.getGlobalBounds().contains(this->mousePosView)) {
						this->gameState = 2;
					}
					else if (this->marathonSprite.getGlobalBounds().contains(this->mousePosView)) {
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
	this->window->draw(this->mainbgSprite);

	if (this->gameState == 1)
	{
		//display title logo 
		//display buttons to select the mode (via mouse, can maybe include using the keyboard arrow keys as well)
		//should we have a backdrop image?

		//split the screen into 7 columns and 13 rows
		int colwidth = this->window->getSize().x / 7;
		int rowheight = this->window->getSize().y / 13;


		gameTitle.setPosition(this->window->getSize().x / 2 - gameTitle.getLocalBounds().width / 2, rowheight * 1);
		this->window->draw(gameTitle);

		lvl1Sprite.setPosition(colwidth * 1, rowheight * 3);
		this->window->draw(lvl1Sprite);
		lvl2Sprite.setPosition(colwidth * 3, rowheight * 3);
		this->window->draw(lvl2Sprite);
		lvl3Sprite.setPosition(colwidth * 1, rowheight * 5);
		this->window->draw(lvl3Sprite);
		lvl4Sprite.setPosition(colwidth * 3, rowheight * 5);
		this->window->draw(lvl4Sprite);
		lvl5Sprite.setPosition(colwidth * 1, rowheight * 7);
		this->window->draw(lvl5Sprite);
		lvl6Sprite.setPosition(colwidth * 3, rowheight * 7);
		this->window->draw(lvl6Sprite);
		lvl7Sprite.setPosition(colwidth * 1, rowheight * 9);
		this->window->draw(lvl7Sprite);
		lvl8Sprite.setPosition(colwidth * 3, rowheight * 9);
		this->window->draw(lvl8Sprite);
		lvl9Sprite.setPosition(colwidth * 1, rowheight * 11);
		this->window->draw(lvl9Sprite);
		lvl10Sprite.setPosition(colwidth * 3, rowheight * 11);
		this->window->draw(lvl10Sprite);
		marathonSprite.setPosition(colwidth * 5, rowheight * 9);
		this->window->draw(marathonSprite);

	} else if (this->gameState == 2)
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



		this->window->draw(gridSprite);

		//may need a separate state for when memo is being used
		
	} else if (this->gameState == 3)
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
		


		this->window->draw(gridSprite);

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
