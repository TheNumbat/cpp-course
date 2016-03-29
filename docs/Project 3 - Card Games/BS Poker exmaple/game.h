
#pragma once

#include "deck.h"
#include "player.h"
#include "hand.h"

//Game class -- manages the actual progression and logic of the game
class game {
public:
	//Parameterized constructor
	game(int numPlayers);
	//Destructor
	~game();
	
	//Intialize game
	void init();
	//Run the game loop -- contains the actual game logic
	void gameLoop();
	
private:
	//Deal player hands
	void dealHands();
	//Check if the highest call is actually there or not
	bool checkHighest();
	//Check for a valid suit
	bool checkSuit(char*);
	//Ending sequence
	void endGame(int);

	//Private data members
	hand highest;	//Highest call
	deck cards;		//The deck
	player* players;//The players
	int numP;		//Number of players
};

