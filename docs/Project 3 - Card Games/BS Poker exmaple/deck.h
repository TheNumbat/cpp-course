
#pragma once

#include "card.h"
#include <iostream>

using namespace std;

class deck {
public:
	//Default/parameterized constructor
	deck(int = 52);
	//Destructor
	~deck();
	
	//Fiele input. istream must be passed by reference
	bool input(istream&);
	//Suffle the deck
	void shuffle();
	//Deal the next card from the deck
	card deal() const;
	//Print the deck
	void print() const;

private:
	//Private data members
	int size;
	card* cards;
};


