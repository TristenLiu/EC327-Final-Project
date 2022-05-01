#include <iostream>
#include "Game.h"

//Private Functions
void Game::initVar()
{
	this->window = nullptr;
	this->current_state = 1; //1 = main menu, 2 = game board
	this->select_instructions = 0;
	this->select_Quit = false;
	this->lv_or_marathon = 0; //0 = individual level mode, 1 = marathon mode
	this->current_lv = 0;
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

}

void Game::initTexture()
{
	//Load Textures from image folder
	this->lvl1Texture.loadFromFile("images/level1.png");
	this->lvl2Texture.loadFromFile("images/level2.png");
	this->lvl3Texture.loadFromFile("images/level3.png");
	this->lvl4Texture.loadFromFile("images/level4.png");
	this->lvl5Texture.loadFromFile("images/level5.png");
	this->lvl6Texture.loadFromFile("images/level6.png");
	this->lvl7Texture.loadFromFile("images/level7.png");
	this->lvl8Texture.loadFromFile("images/level8.png");
	this->marathonTexture.loadFromFile("images/Marathon.png");
	this->quitSTexture.loadFromFile("images/QUITSMALL.png");
	this->quitLTexture.loadFromFile("images/QUITLARGE.png");
	this->quitCTexture.loadFromFile("images/quitConfirm.png");
	this->yesTexture.loadFromFile("images/YES.png");
	this->noTexture.loadFromFile("images/NO.png");
	this->instTexture.loadFromFile("images/INSTRUCTIONS.png");
	this->bomb_texture.loadFromFile("images/bomb_small.png");
	this->lossTexture.loadFromFile("images/gameOver.png");
	this->winTexture.loadFromFile("images/gameWin.png");
	this->contTexture.loadFromFile("images/continue.png");
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
	this->quitSSprite.setTexture(quitSTexture);			this->quitSSprite.setScale(.75f, .75f);
	this->quitLSprite.setTexture(quitLTexture);			this->quitLSprite.setScale(.50f, .50f);
	this->quitCSprite.setTexture(quitCTexture);	
	this->yesSprite.setTexture(yesTexture);				this->yesSprite.setScale(.50f, .50f);			
	this->noSprite.setTexture(noTexture);				this->noSprite.setScale(.50f, .50f);
	this->instSprite.setTexture(instTexture);			this->instSprite.setScale(.50f, .50f);
	this->bomb_sprite.setTexture(bomb_texture);
	this->lossSprite.setTexture(lossTexture);			this->lossSprite.setScale(1.5f, 1.5f);
	this->winSprite.setTexture(winTexture);				this->winSprite.setScale(1.5f, 1.5f);
	this->contSprite.setTexture(contTexture);			this->contSprite.setScale(1.5f, 1.5f);
}

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

	this->text_current_lv_score.setFont(Roboto);
	this->text_current_lv_score.setCharacterSize(30);
	this->text_current_lv_score.setFillColor(sf::Color::White);
	this->text_current_lv_score.setString("NONE");

	this->instructions.setFont(Roboto);
	this->instructions.setCharacterSize(24);
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setString("You are given a 5x5 grid of panels. Click on a panel to flip it. Each panel holds either a 0, 1, 2 or 3.\nWhen you flip a panel, your current level score is mulitplied by the number you flipped.\nIf you flip a 0, it's game over. The goal of the game is to find all of the 2x and 3x panels.\n\nThe game features 8 individual levels (1 being the easiest and 8 being the hardest) and a marathon mode.\nHarder levels have more multiplier cards but also more 0's. \nIn marathon mode, you will play through each level successively until you lose a level.\nWhen you win a level in marathon mode, your total score in the level is added to the marathon score.");

	this->instructions_in_game.setFont(Roboto);
	this->instructions_in_game.setCharacterSize(24);
	this->instructions_in_game.setFillColor(sf::Color::White);
	this->instructions_in_game.setString("Click on a panel to flip it!\nIf you flip a '0', it's game over!\nFind all the 2x and 3x cards to win!");

	this->panel_explain.setFont(Roboto);
	this->panel_explain.setCharacterSize(24);
	this->panel_explain.setFillColor(sf::Color::White);
	this->panel_explain.setString("<- sum of the 1x/2x/3x cards\nin row/column\n<- number of 0's in row/column");

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
	this->initTexture();
	this->initSprite();
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
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
				{
					if (current_state == 1)
					{
						if (!this->select_instructions && !this->select_Quit)
						{
							//Check which button the mouse is over if the mouse is left-clicked
							if (this->lvl1Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 1;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl2Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 2;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl3Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 3;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl4Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 4;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl5Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 5;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl6Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 6;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl7Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 7;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->lvl8Sprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 8;
								this->lv_or_marathon = 0;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->marathonSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_lv = 0;
								this->current_marathon_total = 0; //starting a new marathon run from menu resets score
								this->lv_or_marathon = 1;
								this->current_state = 2;
								this->startLevel = 1;
								this->select_Quit = false;
							}
							else if (this->instSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_instructions = 1;
								this->select_Quit = false;
							}
							else if (this->quitLSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_Quit = true;
							}
						}
						else if (this->select_instructions) //if currently viewing instructions
						{
							if (this->quitSSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_instructions = 0;
							}
						}
						else if (this->select_Quit)
						{
							if (this->yesSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->window->close();
							}
							else if (this->noSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_Quit = false;
							}
						}
					}
					else if (this->current_state == 2)
					{
						if (!this->select_Quit && !this->isGameOver && !this->isClearLevel)
						{
							int colNum = (this->mousePosView.x - 100) / 99;
							int rowNum = (this->mousePosView.y - 100) / 99;

							if (colNum < 5 && rowNum < 5)
							{
								if (rowNum == 0)		chosen_panel_row_index = 0;
								else if (rowNum == 1)	chosen_panel_row_index = 1;
								else if (rowNum == 2)	chosen_panel_row_index = 2;
								else if (rowNum == 3)	chosen_panel_row_index = 3;
								else if (rowNum == 4)	chosen_panel_row_index = 4;

								if (colNum == 0)		chosen_panel_col_index = 0;
								else if (colNum == 1)	chosen_panel_col_index = 1;
								else if (colNum == 2)	chosen_panel_col_index = 2;
								else if (colNum == 3)	chosen_panel_col_index = 3;
								else if (colNum == 4)	chosen_panel_col_index = 4;
							}
							else if (this->quitSSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_Quit = true; 
							}
						}
						else if (this->select_Quit)
						{
							if (this->yesSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_state = 1;
								this->select_Quit = false;
							}
							else if (this->noSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->select_Quit = false;
							}
						}
						else if (this->isGameOver)
						{
							if (this->yesSprite.getGlobalBounds().contains(this->mousePosView))
							{
								if (lv_or_marathon == 1)
								{
									//if you click on continue in marathon mode after a marathon game over, reset score and marathon total and start next level
									if (isClearLevel == 0 && isGameOver == 1)
									{
										current_lv = 0;
										current_marathon_total = 0;
									}
								}
								this->startLevel = 1;
								this->isGameOver = false;
							}
							else if (this->noSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_state = 1;
								this->isGameOver = false;
							}
						}
						else if (this->isClearLevel)
						{
							if (this->yesSprite.getGlobalBounds().contains(this->mousePosView))
							{
								//if you click on continue in marathon mode after you clear a level, start next level like usual, createGrid function handles the rest
								this->startLevel = 1;
							}
							else if (this->noSprite.getGlobalBounds().contains(this->mousePosView))
							{
								this->current_state = 1;
							}
						}
	
					}
				}
				break;
			default: 
				break;
		}
	}
}

void Game::updateText()
{
	//creating and updating text for current score and level during game

	//if in individual level mode, only display current level and level score
	if (current_state == 2 && lv_or_marathon == 0)
	{
		std::stringstream ss;
		ss << "Current Level: " << current_lv << "\n" << "Current Level Points: " << this->current_lv_points;
		this->text_current_lv_score.setString(ss.str());
	}
	//if in marathon mode, display marathon mode and current marathon total
	else if (current_state == 2 && lv_or_marathon == 1)
	{
		std::stringstream ss;
		ss << "Marathon Mode" << "\n" << "Current Level : " << current_lv << "\n" << "Current Level Points : " << this->current_lv_points << "\n" << "Total Marathon Points : " << this->current_marathon_total;
		this->text_current_lv_score.setString(ss.str());
	}

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

}

void Game::createGrid()
{
	// if in game mode and just starting a level
	if (current_state == 2 && startLevel == 1)
	{
		//reset flags and variables to 0
		this->isGameOver = false;
		this->select_Quit = false;
		this->isClearLevel = false;
		this->chosen_panel_row_index = 99;
		this->chosen_panel_col_index = 99;
		this->current_lv_points = 1;
		this->current_num_2x_found = 0;
		this->current_num_3x_found = 0;

		if (lv_or_marathon == 1)
		{
			if (current_lv != 8)
			{
				current_lv++;
			}
			
		}

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
		int combo_choice = rand() % 5;

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
				a = rand() % 5; 
				b = rand() % 5; 
			} while (lv_grid[a][b] == 0); //randomly choose a location for each bomb; while loop to check that the panel isn't already taken

			lv_grid[a][b] = 0; //set the panel equal to bomb (0)
		}

		for (int j = 0; j < current_num_2x; j++) //set 2x cards
		{
			do
			{
				a = rand() % 5;
				b = rand() % 5;
			} while (lv_grid[a][b] == 0 || lv_grid[a][b] == 2);

			lv_grid[a][b] = 2;
		}

		for (int k = 0; k < current_num_3x; k++) //set 3x cards
		{
			do
			{
				a = rand() % 5;
				b = rand() % 5;
			} while (lv_grid[a][b] == 0 || lv_grid[a][b] == 2 || lv_grid[a][b] == 3);

			lv_grid[a][b] = 3;
		}

		this->startLevel = 0;
	}
}

void Game::updateGrid()
{
	
	if (current_state == 2 && !isGameOver && !select_Quit)
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
						isGameOver = true;//trigger game over
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

				if (lv_or_marathon == 1)
				{
					current_marathon_total += current_lv_points;
					current_lv_points = 0;
				}
			}
		}
		
	}
}

void Game::renderText()
{
	int colWidth = this->window->getSize().x / 7;
	int rowHeight = this->window->getSize().y / 13;
	if (current_state == 1 && select_instructions == 0)
	{
		//Display name of game on menu
		gameTitle.setPosition(this->window->getSize().x / 2 - gameTitle.getLocalBounds().width / 2, rowHeight * 1);
		this->window->draw(this->gameTitle);
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

		//Display quick isntructions on screen
		instructions_in_game.setPosition(800.f, 250.f); //set position
		this->window->draw(this->instructions_in_game);

		panel_explain.setPosition(600.f, 600.f);
		this->window->draw(this->panel_explain);
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
				if (isGameOver == true || is_flipped_grid[i][j] == 1 || isClearLevel == 1)
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

				else if (!isGameOver && is_flipped_grid[i][j] == 0)
				{
					panel_facedown.setPosition(100 + (99 * j), 100 + (99 * i));
					this->window->draw(panel_facedown);
				}
				
			}
		}
	}
}


void Game::renderButtons()
{
	//split the screen into 7 columns and 13 rows
	int colWidth = this->window->getSize().x / 7;
	int rowHeight = this->window->getSize().y / 13;

	if (this->current_state == 1)
	{
		this->quitCSprite.setScale(2.f, 2.f);
		if (!this->select_instructions && !this->select_Quit)
		{
			this->lvl1Sprite.setPosition(colWidth * 1, rowHeight * 3.5);
			this->window->draw(lvl1Sprite);
			this->lvl2Sprite.setPosition(colWidth * 3, rowHeight * 3.5);
			this->window->draw(lvl2Sprite);
			this->lvl3Sprite.setPosition(colWidth * 1, rowHeight * 5.5);
			this->window->draw(lvl3Sprite);
			this->lvl4Sprite.setPosition(colWidth * 3, rowHeight * 5.5);
			this->window->draw(lvl4Sprite);
			this->lvl5Sprite.setPosition(colWidth * 1, rowHeight * 7.5);
			this->window->draw(lvl5Sprite);
			this->lvl6Sprite.setPosition(colWidth * 3, rowHeight * 7.5);
			this->window->draw(lvl6Sprite);
			this->lvl7Sprite.setPosition(colWidth * 1, rowHeight * 9.5);
			this->window->draw(lvl7Sprite);
			this->lvl8Sprite.setPosition(colWidth * 3, rowHeight * 9.5);
			this->window->draw(lvl8Sprite);
			this->marathonSprite.setPosition(colWidth * 5, rowHeight * 6.5);
			this->window->draw(marathonSprite);
			this->instSprite.setPosition(colWidth * 5, rowHeight * 3.5);
			this->window->draw(instSprite);
			this->quitLSprite.setPosition(colWidth * 5, rowHeight * 9.5);
			this->window->draw(quitLSprite);
		}
		else if (this->select_instructions)
		{
			this->quitSSprite.setPosition(colWidth * 5.5, rowHeight * 11);
			this->window->draw(quitSSprite);
		}
		else if (this->select_Quit)
		{
			//Display confirm quit message

			this->quitCSprite.setPosition(this->window->getSize().x / 2 - this->quitCSprite.getLocalBounds().width, 
										  this->window->getSize().y / 2 - this->quitCSprite.getLocalBounds().height);
			this->window->draw(quitCSprite);
			this->yesSprite.setPosition(this->window->getSize().x / 2 - 192, this->window->getSize().y / 2 + 25);
			this->window->draw(yesSprite);
			this->noSprite.setPosition(this->window->getSize().x / 2 + 64, this->window->getSize().y / 2 + 25);
			this->window->draw(noSprite);
		}
	}
	else if (this->current_state == 2)
	{
		this->quitCSprite.setScale(1.5f, 1.5f);
		if (!select_Quit && !this->isGameOver && !this->isClearLevel)
		{
			this->quitSSprite.setPosition(colWidth * 5.5, rowHeight * 11);
			this->window->draw(quitSSprite);
		}
		else if (this->select_Quit == 1)
		{
			//Display confirm quit message
			this->quitCSprite.setPosition(colWidth*4.5, rowHeight*6.5);
			this->window->draw(quitCSprite);
			this->yesSprite.setPosition(colWidth * 4.5 + 32, rowHeight * 6.5 + 104);
			this->window->draw(yesSprite);
			this->noSprite.setPosition(colWidth * 4.5 + 228, rowHeight * 6.5 + 104);
			this->window->draw(noSprite);
		}
		else if (this->isGameOver) 
		{
			this->lossSprite.setPosition(colWidth * 4.5, rowHeight * 6.5);
			this->window->draw(lossSprite);
			this->yesSprite.setPosition(colWidth * 4.5 + 32, rowHeight * 6.5 + 104);
			this->window->draw(yesSprite);
			this->noSprite.setPosition(colWidth * 4.5 + 228, rowHeight * 6.5 + 104);
			this->window->draw(noSprite);
		}
		else if (this->isClearLevel && !this->lv_or_marathon)
		{
			this->winSprite.setPosition(colWidth * 4.5, rowHeight * 6.5);
			this->window->draw(winSprite);
			this->yesSprite.setPosition(colWidth * 4.5 + 32, rowHeight * 6.5 + 104);
			this->window->draw(yesSprite);
			this->noSprite.setPosition(colWidth * 4.5 + 228, rowHeight * 6.5 + 104);
			this->window->draw(noSprite);
		}
		else if (this->isClearLevel && this->lv_or_marathon)
		{
			this->contSprite.setPosition(colWidth * 4.5, rowHeight * 6.5);
			this->window->draw(contSprite);
			this->yesSprite.setPosition(colWidth * 4.5 + 32, rowHeight * 6.5 + 104);
			this->window->draw(yesSprite);
			this->noSprite.setPosition(colWidth * 4.5 + 228, rowHeight * 6.5 + 104);
			this->window->draw(noSprite);
		}
	}

}

void Game::update()
{
	//Event Polling
	this->pollEvents();
	this->updateMousePosition();
	updateGrid();
	
}

void Game::render()
{
	//Render game objects(window, tiles, scoreboard, etc.)
	this->window->clear(sf::Color(34, 65, 123, 255));

	render_flipped_panel();
	updateText();
	renderText();
	renderButtons();

	this->window->display();
}