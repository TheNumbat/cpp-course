
#pragma once

#include "card.h"

//Player class -- contains player data such as their hand, if
//they are still in the game, how many cards they have, etc
class player {
//Again all private, so only friends will be able to create players

	//Default constructor
	player();
	//Destructor
	~player();
	
	//Intialize with a hand size
	void init(int hSize);
	//Output cards
	void printHand() const;
	
	//Data members
	card* hand;
	int cards;
	int maxH;
	bool playing;
	
	//Only the game class can use players
	friend class game;
};

