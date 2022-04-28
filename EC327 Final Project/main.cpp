#include "Game.h"

using namespace std;

int main() 
{
	srand(time(0));

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