#pragma once

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
	

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
	sf::Text gameTitle, menuPrompt;
	sf::Text text_current_lv_score;
	sf::Text messages;
	sf::Text instructions_in_game;
	sf::Text panel_explain;
	sf::Text instructions;
	sf::Text quit_instructions;
	sf::Text bombs_r1, card_total_r1, bombs_c1, card_total_c1;
	sf::Text number_1, number_2, number_3, number_bomb;

	sf::Font Roboto, Candaraz;

	sf::Texture lvl1Texture, lvl2Texture, lvl3Texture, lvl4Texture, lvl5Texture, lvl6Texture, lvl7Texture, lvl8Texture;
	sf::Sprite lvl1Sprite, lvl2Sprite, lvl3Sprite, lvl4Sprite, lvl5Sprite, lvl6Sprite, lvl7Sprite, lvl8Sprite;
	sf::Texture marathonTexture, quitSTexture, quitLTexture, quitCTexture, memoTexture, yesTexture, noTexture, instTexture, lossTexture, winTexture, contTexture, bombSTexture, bombLTexture;
	sf::Sprite marathonSprite, quitSSprite, quitLSprite, quitCSprite, memoSprite, yesSprite, noSprite, instSprite, lossSprite, winSprite, contSprite, bombSSprite, bombLSprite;

	//Shapes (for panels)
	sf::RectangleShape panel_facedown, panel_number, panel_bomb, panel_totals;

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
	//int current_num_1x;
	//int current_num_1x_found;

	//Private Functions
	void initVar();
	void initTexture();
	void initSprite();
	void initFont();
	void initText();
	void initShapes();
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
	void updateGrid();

	void update();

	void renderButtons();
	void renderText();
	void render_flipped_panel();

	void render();
};
