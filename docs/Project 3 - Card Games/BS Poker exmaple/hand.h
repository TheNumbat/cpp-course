
#pragma once

#include <string>
#include "card.h"

//An enum holds different types of things, represented by keywords, which also
//equal integers
enum hand_type {
	NONE = 0,
	
	HIGH_CARD, //automatically = 1
	PAIR, //automatically = 2
	TWO_PAIR, // etc
	TRIPLE,
	STRAIGHT,
	FULL_HOUSE,
	QUAD,
	STRAIGHT_FLUSH,
	
	TOTAL_HANDS // = 9, as it is the 9th element. 
				//This means the actual "total hands" is TOTAL_HANDS - 1
};

//A global, constant array of strings that describe the english names of the poker hands
const std::string hand_names[TOTAL_HANDS] = 
	{"High card","Pair","Two Pairs","Three of a kind","Straight",
	 "Full house","Four of a kind","Straight Flush"};


//A hand class -- used to describe the value of a hand
class hand {
//Again all private, so only friends can create a "hand"
	
	//Parameterized constructor
	hand(int type, int val1, int val2);
	//Destructor
	~hand();
	
	//Outputs hand
	void print();

	//The type of hand
	hand_type lvl;
	//Cards that describe the parts of the hand -- for example, if the type
	//is a full house, it's v1's over v2's
	card v1, v2;
	//The suit of the hand, only used for straight flushes
	char suit[20];
	
	//Only the "game" class can use hands
	friend class game;
};

