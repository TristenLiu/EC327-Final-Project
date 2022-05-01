#EC327 Final Project - Spring 2022
Intro to Software Engineering - Team Clover

##Team Members
Tristen Liu (tristenl@bu.edu), Jane Tsui (janetsui@bu.edu),	Michael Igwe (migwe@bu.edu), Stacia Kolodziejski (skolodz@bu.edu)

##Overview
  This repository creates a game inspired by the minigame "Voltorb Flip" in Pokemon. This game features 8 levels of increasing difficulty, and a marathon mode that progressively gets harder as the player wins each instance. In each level, a 5x5 grid is rendered that consists of bombs, 1x, 2x and 3x tiles. The goal of the game is to flip all of the 2x and 3x tiles, while avoiding the bomb tiles. The score of each level is calculated by the multiplication of each tile that is flipped, and as such only the 2x and 3x tiles will count towards the score. The bomb tiles have a value of 0, and if it is flipped the level will end and the score will drop to 0. Further instructions can be found on the title page of the application.
  This game uses the SFML library to render and create all the windows, game graphics and assets. The library is dynamically present in necessary folders, and as such no further installation is necessary in order to run this game. 
  
##Build Instructions
Windows and Mac: In the terminal, clone the github repository and then run the makefile. Then run the command ./bombflip **CHANGE THIS TO WHATEVER THE RUNFILE IS CALLED**, and play the game. 
