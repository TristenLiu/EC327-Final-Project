#include <iostream>
#include "Game.h"

//Private Functions
void Game::initVar()
{
	this->window = nullptr;
	this->current_state = 1; //1 = main menu, 2 = game board
	this->select_instructions = 0;
	this->select_Quit = 0;
	this->lv_or_marathon = 0; //0 = individual level mode, 1 = marathon mode
	this->current_lv = 1;
	this->current_lv_points = 1;
	this->current_marathon_total = 0;
	this->isGameOver = false;
	this->isClearLevel = false;
	this->startLevel = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			lv_grid[i][j] = 1;
			is_flipped_grid[i][j] = 0;
		}
	}
	this->bomb_texture.loadFromFile("images/bomb_small.png");
	this->bomb_sprite.setTexture(bomb_texture);
}

/*
void Game::initTexture()
{
	//Load Textures from image folder
	this->lvl1Texture.loadFromFile("images/Level1.png");
	this->lvl2Texture.loadFromFile("images/Level2.png");
	this->lvl3Texture.loadFromFile("images/Level3.png");
	this->lvl4Texture.loadFromFile("images/Level4.png");
	this->lvl5Texture.loadFromFile("images/Level5.png");
	this->lvl6Texture.loadFromFile("images/Level6.png");
	this->lvl7Texture.loadFromFile("images/Level7.png");
	this->lvl8Texture.loadFromFile("images/Level8.png");
	this->marathonTexture.loadFromFile("images/Marathon.png");
}

void Game::initSprite()
{
	//Set textures to usable Sprites
	//Each checkerboard square is 150px

	//button sprites are 256x128 px
	this->lvl1Sprite.setTexture(lvl1Texture);			this->lvl1Sprite.setScale(.50f, .50f);
	this->lvl2Sprite.setTexture(lvl2Texture);			this->lvl2Sprite.setScale(.50f, .50f);
	this->lvl3Sprite.setTexture(lvl3Texture);			this->lvl3Sprite.setScale(.50f, .50f);
	this->lvl4Sprite.setTexture(lvl4Texture);			this->lvl4Sprite.setScale(.50f, .50f);
	this->lvl5Sprite.setTexture(lvl5Texture);			this->lvl5Sprite.setScale(.50f, .50f);
	this->lvl6Sprite.setTexture(lvl6Texture);			this->lvl6Sprite.setScale(.50f, .50f);
	this->lvl7Sprite.setTexture(lvl7Texture);			this->lvl7Sprite.setScale(.50f, .50f);
	this->lvl8Sprite.setTexture(lvl8Texture);			this->lvl8Sprite.setScale(.50f, .50f);
	this->marathonSprite.setTexture(marathonTexture);	this->marathonSprite.setScale(0.50f, 0.50f);
}
*/
void Game::initFont()
{
	this->Roboto.loadFromFile("fonts/Roboto.ttf");
	this->Candaraz.loadFromFile("fonts/Candaraz.ttf");
}

void Game::initText()
{
	this->gameTitle.setFont(Candaraz);
	this->gameTitle.setCharacterSize(70);
	this->gameTitle.setFillColor(sf::Color::Yellow);
	this->gameTitle.setStyle(sf::Text::Bold | sf::Text::Underlined);
	this->gameTitle.setString("Voltorb Flip V2");

	this->menuPrompt.setFont(Candaraz);
	this->menuPrompt.setCharacterSize(50);
	this->menuPrompt.setFillColor(sf::Color::White);
	this->menuPrompt.setString("Press a number to choose a difficulty level:\n1 - Easy\n2 - Medium\n3 - Hard\n\nPress 9 to view instructions");

	this->text_current_lv_score.setFont(Roboto);
	this->text_current_lv_score.setCharacterSize(40);
	this->text_current_lv_score.setFillColor(sf::Color::White);
	this->text_current_lv_score.setString("NONE");

	this->instructions.setFont(Roboto);
	this->instructions.setCharacterSize(24);
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setString("WRITE INSTRUCTIONS HERE, should also note to hit Backspace to return to main menu");

	this->quit_instructions.setFont(Roboto);
	this->quit_instructions.setCharacterSize(30);
	this->quit_instructions.setFillColor(sf::Color::White);
	this->quit_instructions.setString("Press ESCAPE to quit the game\nand return to the main menu");

	this->messages.setFont(Roboto);
	this->messages.setCharacterSize(30);
	this->messages.setFillColor(sf::Color::White);
	this->messages.setString("NONE");

	this->bombs_r1.setFont(Roboto);
	this->bombs_r1.setCharacterSize(36);
	this->bombs_r1.setFillColor(sf::Color::Black);
	this->bombs_r1.setString("NONE");

	this->card_total_r1.setFont(Roboto);
	this->card_total_r1.setCharacterSize(36);
	this->card_total_r1.setFillColor(sf::Color::Black);
	this->card_total_r1.setString("NONE");

	this->bombs_c1.setFont(Roboto);
	this->bombs_c1.setCharacterSize(36);
	this->bombs_c1.setFillColor(sf::Color::Black);
	this->bombs_c1.setString("NONE");

	this->card_total_c1.setFont(Roboto);
	this->card_total_c1.setCharacterSize(36);
	this->card_total_c1.setFillColor(sf::Color::Black);
	this->card_total_c1.setString("NONE");

	//temporary substitute for panels
	this->number_1.setFont(Roboto);
	this->number_1.setCharacterSize(45);
	this->number_1.setFillColor(sf::Color::White);
	this->number_1.setString("1");

	this->number_bomb.setFont(Roboto);
	this->number_bomb.setCharacterSize(45);
	this->number_bomb.setFillColor(sf::Color::White);
	this->number_bomb.setString("O");

	this->ques_mark.setFont(Roboto);
	this->ques_mark.setCharacterSize(45);
	this->ques_mark.setFillColor(sf::Color::White);
	this->ques_mark.setString("?");
}

void Game::initShapes()
{
	panel_facedown.setSize(sf::Vector2f(90, 90));
	panel_facedown.setFillColor(sf::Color(0, 157, 38));
	panel_facedown.setOutlineThickness(10);

	panel_number.setSize(sf::Vector2f(90, 90));
	panel_number.setFillColor(sf::Color(150, 50, 250));
	panel_number.setOutlineThickness(10);

	panel_bomb.setSize(sf::Vector2f(90, 90));
	panel_bomb.setFillColor(sf::Color::Red);
	panel_bomb.setOutlineThickness(10);

	panel_totals.setSize(sf::Vector2f(90, 45));
	panel_totals.setFillColor(sf::Color(230,218,191));
	panel_totals.setOutlineThickness(10);
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
	//this->initTexture();
	//this->initSprite();
	this->initFont();
	this->initText();
	this->initShapes();
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
/*
void Game::updateMousePosition() 
{
	//update the mouse position relative to window
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}
*/

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

				//temporary keyboard inputs for window changing and panel selection
				if (this->current_state == 2 && isGameOver == 0 && isClearLevel == 0 && select_Quit == 0)
				{
					if (this->ev.key.code == sf::Keyboard::Tab) //pressing Tab will return to the title screen
					{
						this->current_state = 1;
						startLevel = 0;
						isGameOver = 0;
					}

					else if (this->ev.key.code == sf::Keyboard::A)
					{
						chosen_panel_row_index = 0;
						chosen_panel_col_index = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::B)
					{
						chosen_panel_row_index = 0;
						chosen_panel_col_index = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::C)
					{
						chosen_panel_row_index = 0;
						chosen_panel_col_index = 2;
					}
					else if (this->ev.key.code == sf::Keyboard::D)
					{
						chosen_panel_row_index = 0;
						chosen_panel_col_index = 3;
					}
					else if (this->ev.key.code == sf::Keyboard::E)
					{
						chosen_panel_row_index = 0;
						chosen_panel_col_index = 4;
					}
					else if (this->ev.key.code == sf::Keyboard::F)
					{
						chosen_panel_row_index = 1;
						chosen_panel_col_index = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::G)
					{
						chosen_panel_row_index = 1;
						chosen_panel_col_index = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::H)
					{
						chosen_panel_row_index = 1;
						chosen_panel_col_index = 2;
					}
					else if (this->ev.key.code == sf::Keyboard::I)
					{
						chosen_panel_row_index = 1;
						chosen_panel_col_index = 3;
					}
					else if (this->ev.key.code == sf::Keyboard::J)
					{
						chosen_panel_row_index = 1;
						chosen_panel_col_index = 4;
					}
					else if (this->ev.key.code == sf::Keyboard::K)
					{
						chosen_panel_row_index = 2;
						chosen_panel_col_index = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::L)
					{
						chosen_panel_row_index = 2;
						chosen_panel_col_index = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::M)
					{
						chosen_panel_row_index = 2;
						chosen_panel_col_index = 2;
					}
					else if (this->ev.key.code == sf::Keyboard::N)
					{
						chosen_panel_row_index = 2;
						chosen_panel_col_index = 3;
					}
					else if (this->ev.key.code == sf::Keyboard::O)
					{
						chosen_panel_row_index = 2;
						chosen_panel_col_index = 4;
					}
					else if (this->ev.key.code == sf::Keyboard::P)
					{
						chosen_panel_row_index = 3;
						chosen_panel_col_index = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::Q)
					{
						chosen_panel_row_index = 3;
						chosen_panel_col_index = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::R)
					{
						chosen_panel_row_index = 3;
						chosen_panel_col_index = 2;
					}
					else if (this->ev.key.code == sf::Keyboard::S)
					{
						chosen_panel_row_index = 3;
						chosen_panel_col_index = 3;
					}
					else if (this->ev.key.code == sf::Keyboard::T)
					{
						chosen_panel_row_index = 3;
						chosen_panel_col_index = 4;
					}
					else if (this->ev.key.code == sf::Keyboard::U)
					{
					chosen_panel_row_index = 4;
					chosen_panel_col_index = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::V)
					{
					chosen_panel_row_index = 4;
					chosen_panel_col_index = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::W)
					{
					chosen_panel_row_index = 4;
					chosen_panel_col_index = 2;
					}
					else if (this->ev.key.code == sf::Keyboard::X)
					{
					chosen_panel_row_index = 4;
					chosen_panel_col_index = 3;
					}
					else if (this->ev.key.code == sf::Keyboard::Y)
					{
					chosen_panel_row_index = 4;
					chosen_panel_col_index = 4;
					}
					else if (this->ev.key.code == sf::Keyboard::Escape)
					{
					select_Quit = 1;
					}
				}

				else if (this->current_state == 1 && select_instructions == 0)
				{
					if (this->ev.key.code == sf::Keyboard::Num1) 
					{
						this->current_lv = 1;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}

					else if (this->ev.key.code == sf::Keyboard::Num2)
					{
						this->current_lv = 2;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num2)
					{
						this->current_lv = 2;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num3)
					{
						this->current_lv = 3;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num4)
					{
						this->current_lv = 4;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num5)
					{
						this->current_lv = 5;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num6)
					{
						this->current_lv = 6;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num7)
					{
						this->current_lv = 7;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num8)
					{
						this->current_lv = 8;
						this->lv_or_marathon = 0;
						this->current_state = 2;
						this->startLevel = 1;
					}
					else if (this->ev.key.code == sf::Keyboard::Num9)
					{
						select_instructions = 1;
					}
				}

				else if (this->current_state == 1 && select_instructions == 1)
				{
					if (this->ev.key.code == sf::Keyboard::Backspace) //pressing Backspace on instructions will return to the title screen
					{
						select_instructions = 0;
					}
				}

				else if (current_state == 2 && isGameOver == 1)
				{
					if (this->ev.key.code == sf::Keyboard::Backspace) //return to menu after game over
					{
						current_state = 1;
						isGameOver = 0;
						startLevel = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::Space) //start new game
					{
						isGameOver = 0;
						startLevel = 1;
					}
				}

				else if (current_state == 2 && isClearLevel == 1)
				{
					if (this->ev.key.code == sf::Keyboard::Backspace) //return to menu after clearing level
					{
						current_state = 1;
						isClearLevel = 0;
						startLevel = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::Space) //start new game
					{
						isClearLevel = 0;
						startLevel = 1;
					}
				}

				else if (current_state == 2 && select_Quit == 1)
				{
					if (this->ev.key.code == sf::Keyboard::Space) //go back to game
					{
						select_Quit = 0;
					}
					else if (this->ev.key.code == sf::Keyboard::Backspace) //return to menu
					{
						current_state = 1;
						select_Quit = 0;
					}
				}


		/*
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
				{
					if (current_state == 1 && select_instructions == 0)
					{
						//Check which button the mouse is over if the mouse is left-clicked
						if (this->lvl1Sprite.getGlobalBounds().contains(this->mousePosView)) { 
							this->current_lv = 1;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl2Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 2;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl3Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 3;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl4Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 4;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl5Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 5;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl6Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 6;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl7Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 7;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->lvl8Sprite.getGlobalBounds().contains(this->mousePosView)) {
							this->current_lv = 8;
							this->lv_or_marathon = 0;
							this->current_state = 2;
							this->startLevel = 1;
						}
						else if (this->marathonSprite.getGlobalBounds().contains(this->mousePosView)) {
							//once marathom mode is implemented
							//this->current_lv = 1;
							//this->lv_or_marathon = 1;
							//this->current_state = 2;
							//this->startLevel = 1;

							//for now, use to trigger instructions
							this->select_instructions = 1;
						}
					}

					
					* need to make a button to return to menu, clicking anywhere on page doesn't work
					if (current_state == 1 && select_instructions == 1) //if currently viewing instructions
					{		
						click on return button  to return to main menu
					}
					
				}*/
		}
	}
}

void Game::updateText()
{
	//creating and updating text for current score and level during game
	std::stringstream ss;
	ss << "Current Level: " << this->current_lv << "\n" << "Current Level Points: " << this->current_lv_points;
	this->text_current_lv_score.setString(ss.str());

	//creating and updating text for number of bombs and total of multiplier cards for each row and column

	if (current_state == 2)
	{
		int num_bombs_row = 0;
		int total_multi_cards_row = 0;
		int num_bombs_col = 0;
		int total_multi_cards_col = 0;
		int i, j;

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				//calculating totals for 1 row
				if (lv_grid[i][j] == 0)
				{
					num_bombs_row++;
				}

				else
				{
					total_multi_cards_row += lv_grid[i][j];
				}

				//calculating totals for 1 column
				if (lv_grid[j][i] == 0)
				{
					num_bombs_col++;
				}

				else
				{
					total_multi_cards_col += lv_grid[j][i];
				}
			}

			//set row totals into text object
			this->bombs_r1.setString(std::to_string(num_bombs_row));
			this->card_total_r1.setString(std::to_string(total_multi_cards_row));

			//set position for totals and draw on window
			card_total_r1.setPosition(650, 100 + 100*i);
			this->window->draw(this->card_total_r1);

			bombs_r1.setPosition(650, 150 + 100 * i);
			this->window->draw(this->bombs_r1);

			bomb_sprite.setPosition(600, 150 + 100 * i);
			this->window->draw(this->bomb_sprite);

			//set column totals into text object
			this->bombs_c1.setString(std::to_string(num_bombs_col));
			this->card_total_c1.setString(std::to_string(total_multi_cards_col));

			//set position for totals and draw on window
			card_total_c1.setPosition(150 + 100*i, 600);
			this->window->draw(this->card_total_c1);

			bombs_c1.setPosition(150 + 100 * i, 650);
			this->window->draw(this->bombs_c1);

			bomb_sprite.setPosition(100 + 100 * i, 650);
			this->window->draw(this->bomb_sprite);

			//reset counts for next row/column
			num_bombs_row = 0;
			total_multi_cards_row = 0;
			num_bombs_col = 0;
			total_multi_cards_col = 0;

		}
	}

	//Setting text for messages - message will be different depending on condition

	if (current_state == 2 && isGameOver == 1)
	{
		this->messages.setString("Game Over!\nWant to play again?\nPress SPACE to continue\nor BACKSPACE to quit");
	}
	else if (current_state == 2 && select_Quit == 1)
	{
		this->messages.setString("Are you sure you want to quit?\nPress SPACE to continue\nor BACKSPACE to quit");
	}
	else if (current_state == 2 && isClearLevel == 1)
	{
		this->messages.setString("You won the game!\nWant to play again?\nPress SPACE to continue\nor BACKSPACE to quit");
	}
}

void Game::createGrid()
{
	// if in game mode and just starting a level
	if (current_state == 2 && startLevel == 1)
	{
		//reset flags and variables to 0
		this->isGameOver = 0;
		this->select_Quit = 0;
		this->isClearLevel = 0;
		this->chosen_panel_row_index = 99;
		this->chosen_panel_col_index = 99;
		this->current_lv_points = 1;
		this->current_num_2x_found = 0;
		this->current_num_3x_found = 0;

		//reset lv_grid matrix to all 1's
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				lv_grid[i][j] = 1;
			}
		}

		//reset is_flipped_grid to all 0's
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				is_flipped_grid[i][j] = 0;
			}
		}

		int a, b; //indices to reference elements in grid matrix
		int combo_choice = rand() % 4; //rand() % 4

		//choose an allocation of bombs and multiplier cards for the level
		switch (current_lv) //check current level
		{
			case 1: //if in level 1
			{
				this->current_num_bombs = 6;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
					case 0:
						this->current_num_2x = 3;
						this->current_num_3x = 1;
						break;
					case 1:
						this->current_num_2x = 0;
						this->current_num_3x = 3;
						break;
					case 2:
						this->current_num_2x = 5;
						this->current_num_3x = 0;
						break;
					case 3:
						this->current_num_2x = 2;
						this->current_num_3x = 2;
						break;
					case 4:
						this->current_num_2x = 4;
						this->current_num_3x = 1;
						break;
				}
				break;
			}
			case 2: //level 2
			{
				this->current_num_bombs = 7;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
					case 0:						
						this->current_num_2x = 1;
						this->current_num_3x = 3;
						break;
					case 1:
						this->current_num_2x = 6;
						this->current_num_3x = 0;
						break;
					case 2:
						this->current_num_2x = 3;
						this->current_num_3x = 2;
						break;
					case 3:
						this->current_num_2x = 0;
						this->current_num_3x = 4;
						break;
					case 4:
						this->current_num_2x = 5;
						this->current_num_3x = 1;
						break;
				}
				break;
			}
			case 3: //level 3
			{
				this->current_num_bombs = 8;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
					case 0:
						this->current_num_2x = 2;
						this->current_num_3x = 3;
						break;
					case 1:
						this->current_num_2x = 7;
						this->current_num_3x = 0;
						break;
					case 2:
						this->current_num_2x = 4;
						this->current_num_3x = 2;
						break;
					case 3:
						this->current_num_2x = 1;
						this->current_num_3x = 4;
						break;
					case 4:
						this->current_num_2x = 6;
						this->current_num_3x = 1;
						break;
				}
				break;
			}
			
			case 4: //level 4
			{
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
				case 0:
					this->current_num_bombs = 8;
					this->current_num_2x = 3;
					this->current_num_3x = 3;
					break;
				case 1:
					this->current_num_bombs = 8;
					this->current_num_2x = 0;
					this->current_num_3x = 5;
					break;
				case 2:
					this->current_num_bombs = 10;
					this->current_num_2x = 8;
					this->current_num_3x = 0;
					break;
				case 3:
					this->current_num_bombs = 10;
					this->current_num_2x = 5;
					this->current_num_3x = 2;
					break;
				case 4:
					this->current_num_bombs = 10;
					this->current_num_2x = 2;
					this->current_num_3x = 4;
					break;
				}
				break;
			}
			case 5: //level 5
			{
				this->current_num_bombs = 10;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
				case 0:
					this->current_num_2x = 7;
					this->current_num_3x = 1;
					break;
				case 1:
					this->current_num_2x = 4;
					this->current_num_3x = 3;
					break;
				case 2:
					this->current_num_2x = 1;
					this->current_num_3x = 5;
					break;
				case 3:
					this->current_num_2x = 9;
					this->current_num_3x = 0;
					break;
				case 4:
					this->current_num_2x = 6;
					this->current_num_3x = 2;
					break;
				}
				break;
			}
			case 6: //level 6
			{
				this->current_num_bombs = 10;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
				case 0:
					this->current_num_2x = 3;
					this->current_num_3x = 4;
					break;
				case 1:
					this->current_num_2x = 0;
					this->current_num_3x = 6;
					break;
				case 2:
					this->current_num_2x = 8;
					this->current_num_3x = 1;
					break;
				case 3:
					this->current_num_2x = 5;
					this->current_num_3x = 3;
					break;
				case 4:
					this->current_num_2x = 2;
					this->current_num_3x = 5;
					break;
				}
				break;
			}
			case 7: //level 7
			{
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
				case 0:
					this->current_num_bombs = 10;
					this->current_num_2x = 7;
					this->current_num_3x = 2;
					break;
				case 1:
					this->current_num_bombs = 10;
					this->current_num_2x = 4;
					this->current_num_3x = 4;
					break;
				case 2:
					this->current_num_bombs = 13;
					this->current_num_2x = 1;
					this->current_num_3x = 6;
					break;
				case 3:
					this->current_num_bombs = 13;
					this->current_num_2x = 9;
					this->current_num_3x = 1;
					break;
				case 4:
					this->current_num_bombs = 10;
					this->current_num_2x = 6;
					this->current_num_3x = 3;
					break;
				}
				break;
			}
			case 8: //level 8
			{
				this->current_num_bombs = 10;
				switch (combo_choice) // randomly choose one of 5 possible bomb/2x/3x card allocations for the level
				{
				case 0:
					this->current_num_2x = 0;
					this->current_num_3x = 7;
					break;
				case 1:
					this->current_num_2x = 8;
					this->current_num_3x = 2;
					break;
				case 2:
					this->current_num_2x = 5;
					this->current_num_3x = 4;
					break;
				case 3:
					this->current_num_2x = 2;
					this->current_num_3x = 6;
					break;
				case 4:
					this->current_num_2x = 7;
					this->current_num_3x = 3;
					break;
				}
				break;
			}
		}

		//set bombs and multiplier numbers on matrix
		for (int i = 0; i < current_num_bombs; i++) //set bombs
		{
			do
			{
				a = rand() % 4; 
				b = rand() % 4; 
			} while (lv_grid[a][b] == 0); //randomly choose a location for each bomb; while loop to check that the panel isn't already taken

			lv_grid[a][b] = 0; //set the panel equal to bomb (0)
		}

		for (int j = 0; j < current_num_2x; j++) //set 2x cards
		{
			do
			{
				a = rand() % 4;
				b = rand() % 4;
			} while (lv_grid[a][b] == 0 || lv_grid[a][b] == 2);

			lv_grid[a][b] = 2;
		}

		for (int k = 0; k < current_num_3x; k++) //set 3x cards
		{
			do
			{
				a = rand() % 4;
				b = rand() % 4;
			} while (lv_grid[a][b] == 0 || lv_grid[a][b] == 2 || lv_grid[a][b] == 3);

			lv_grid[a][b] = 3;
		}

		this->startLevel = 0;
	}
}

void Game::updateGrid()
{
	
	if (current_state == 2 && isGameOver == 0 && select_Quit == 0)
	{	
		//if new level started, initialize grid
		if (startLevel == 1)
		{
			this->createGrid();
		}

		//while in the middle of a level
		else if (startLevel == 0)
		{
			if (chosen_panel_row_index != 99 && chosen_panel_col_index != 99)
			{
				chosen_panel_value = lv_grid[chosen_panel_row_index][chosen_panel_col_index];

				//if the panel you clicked on is not yet flipped
				if (is_flipped_grid[chosen_panel_row_index][chosen_panel_col_index] == 0)
				{
					if (chosen_panel_value == 0)
					{
						current_lv_points *= chosen_panel_value;
						isGameOver = 1;//trigger game over
					}

					else if (chosen_panel_value == 1)
					{
						current_lv_points *= chosen_panel_value;
					}

					else if (chosen_panel_value == 2)
					{
						current_lv_points *= chosen_panel_value;
						current_num_2x_found++;
					}

					else if (chosen_panel_value == 3)
					{
						current_lv_points *= chosen_panel_value;
						current_num_3x_found++;
					}

					is_flipped_grid[chosen_panel_row_index][chosen_panel_col_index] = 1; //mark panel as flipped
				}
			}

			//if all 2x and 3x cards are found, player wins level
			if (this->current_num_2x == current_num_2x_found && this->current_num_3x == current_num_3x_found)
			{
				this->isClearLevel = 1;
			}
		}
		
	}
}

void Game::renderText()
{
	if (current_state == 1 && select_instructions == 0)
	{
		//Display name of game on menu
		int colwidth = this->window->getSize().x / 7;
		int rowheight = this->window->getSize().y / 13;
		gameTitle.setPosition(this->window->getSize().x / 2 - gameTitle.getLocalBounds().width / 2, rowheight * 1);
		this->window->draw(this->gameTitle);

		menuPrompt.setPosition(150, 200);
		this->window->draw(this->menuPrompt);
	}

	else if (current_state == 1 && select_instructions == 1)
	{
		//Display instructions on screen
		instructions.setPosition(100.f, 100.f); //should be centered
		this->window->draw(this->instructions);
	}

	else if (current_state == 2)
	{
		//Display current score and level on game screen
		text_current_lv_score.setPosition(800.f, 50.f); 
		this->window->draw(this->text_current_lv_score);

		quit_instructions.setPosition(800.f, 250.f); 
		this->window->draw(this->quit_instructions);

		if (isGameOver == 1)
		{
			//Display game over message
			messages.setPosition(800.f, 500.f); //set position
			this->window->draw(this->messages);
		}

		if (select_Quit == 1)
		{
			//Display confirm quit message
			messages.setPosition(800.f, 500.f); //set position
			this->window->draw(this->messages);
		}

		if (isClearLevel == 1)
		{
			//Display cleared level message
			messages.setPosition(800.f, 500.f); //set position
			this->window->draw(this->messages);
		}
		//also need to render yes/no buttons for these (in render buttons function)
		//and to change states with yes/no is chosen (in updateGrid function)
	}

}

void Game::render_flipped_panel()
{
	if (current_state == 2)
	{
		//render panels for displaying totals
		for (int i = 0; i < 5; i++)
		{
			panel_totals.setPosition(595, 100 + (99 * i)); //column
			this->window->draw(panel_totals);
			panel_totals.setPosition(595, 150 + (99 * i)); //column
			this->window->draw(panel_totals);

			panel_totals.setPosition(100 + (99 * i), 595);
			this->window->draw(panel_totals);
			panel_totals.setPosition(100 + (99 * i), 650);
			this->window->draw(panel_totals);
		}


		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (isGameOver == 1 || is_flipped_grid[i][j] == 1 || isClearLevel == 1)
				{
					if (lv_grid[i][j] == 0)
					{
						panel_bomb.setPosition(100 + (99 * j), 100 + (99 * i));
						this->window->draw(panel_bomb);

						number_bomb.setPosition(135 + (99 * j), 115 + (99 * i));
						this->window->draw(number_bomb);
					}

					else if (lv_grid[i][j] == 1 || lv_grid[i][j] == 2 || lv_grid[i][j] == 3)
					{
						panel_number.setPosition(100 + (99 * j), 100 + (99 * i));
						this->window->draw(panel_number);

						std::string num = std::to_string(lv_grid[i][j]);
						number_1.setString(num);
						number_1.setPosition(135 + (99 * j), 115 + (99 * i));
						this->window->draw(number_1);
					}
				}

				else if (isGameOver == 0 && is_flipped_grid[i][j] == 0)
				{
					panel_facedown.setPosition(100 + (99 * j), 100 + (99 * i));
					this->window->draw(panel_facedown);

					std::string s(1, ((char)(65 + i * 5 + j)));
					ques_mark.setString(s);
					ques_mark.setPosition(135 + (99 * j), 115 + (99 * i));
					this->window->draw(ques_mark);
				}
				
			}
		}
	}
}

/*
void Game::renderGrid()
{
	if (current_state == 2)
	{
		sf::Texture grid;
		grid.loadFromFile("images/grid_6_cut.png");
		sf::Sprite grid_facedown(grid);
		grid_facedown.setScale(.15, .15);
		grid_facedown.setPosition(98, 98);
		this->window->draw(grid_facedown);
	}
}
*/

/*
void Game::renderButtons()
{
	if (this->current_state == 1 && select_instructions == 0)
	{
		//split the screen into 7 columns and 13 rows
		int colwidth = this->window->getSize().x / 7;
		int rowheight = this->window->getSize().y / 13;

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
	}

}
*/
void Game::update()
{
	//Event Polling
	this->pollEvents();
	//this->updateMousePosition();
	updateGrid();
	
}

void Game::render()
{
	//Render game objects(window, tiles, scoreboard, etc.)
	this->window->clear(sf::Color(34, 65, 123, 255));

	//this->renderButtons();
	//renderGrid();
	
	
	render_flipped_panel();
	updateText();
	renderText();

	this->window->display();
}
