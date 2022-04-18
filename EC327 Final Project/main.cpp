#include <iostream>
#include "Game.h"

int main() 
{
	//initialize Game object
	Game game;

	//keep updating and rendering game as long as its running.
	while (game.isRunning())
	{
		game.update();

		game.render();
	}

	//end of application
	return 0;
}