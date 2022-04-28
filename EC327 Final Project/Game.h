#pragma once

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
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

	//Event polling
	sf::Event ev;

	//Text and fonts
	sf::Text gameTitle;
	sf::Text text_current_lv_num;
	sf::Text text_current_lv_score;
	sf::Text messages;
	sf::Text instructions;
	sf::Text bombs_r1, bombs_r2, bombs_r3, bombs_r4, bombs_r5, bombs_c1, bombs_c2, bombs_c3, bombs_c4, bombs_c5,
		card_total_r1, card_total_r2, card_total_r3, card_total_r4, card_total_r5,
		card_total_c1, card_total_c2, card_total_c3, card_total_c4, card_total_c5;

	sf::Font Roboto;

	sf::Texture mainbgTexture, lvl1Texture, lvl2Texture, lvl3Texture, lvl4Texture, lvl5Texture, lvl6Texture, lvl7Texture, lvl8Texture, lvl9Texture, lvl10Texture, marathonTexture;
	sf::Sprite mainbgSprite, lvl1Sprite, lvl2Sprite, lvl3Sprite, lvl4Sprite, lvl5Sprite, lvl6Sprite, lvl7Sprite, lvl8Sprite, lvl9Sprite, lvl10Sprite, marathonSprite;
	sf::Texture gridTexture;
	sf::Sprite gridSprite;

	//Mouse positions
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;

	//Game Logic
	unsigned current_state; //1 = main menu, 2 = game board
	bool select_instructions; //1 if instructions needs to be shown
	bool select_Quit; //1 if player chooses quit while playing game
	bool lv_or_marathon; //0 = individual level mode, 1 = marathon mode
	int current_lv;
	unsigned current_lv_points;
	unsigned current_marathon_total;
	bool isGameOver; //1 if game over
	bool isQuitGame; //1 if game is quit (mainly used for marathon mode; the points collected so far will be added to total score)
	bool isClearLevel; // 1 if level is cleared
	bool startLevel; //flag to generate a new grid, this is so the grid doean't get re-initiated every frame


	int lv_grid[5][5];
	int is_flipped_grid[5][5]; // 0 = unflipped, used to keep track of flipped panels while in the middle of a game
	int chosen_panel_value;
	int chosen_panel_row_index;
	int chosen_panel_col_index;
	int current_num_bombs; //total number of bombs for the level
	int current_num_2x;
	int current_num_3x;
	int current_num_2x_found;
	int current_num_3x_found;
	//int memo_array[4]; used to keep track of active memo stamps while in memo mode

	//Private Functions
	void initVar();
	void initTexture();
	void initSprite();
	void initFont();
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
	

	void pollEvents();
	void updateText();
	void createGrid();
	//void updateGrid();

	void update();

	void renderButtons();
	void renderText();
	//void renderGrid();

	void render();
};
