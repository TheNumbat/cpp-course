#pragma once

#include <iostream>
#include <string>
using namespace std;

//Card class
class card {
//Default access modifier is private, so you don't have to specify "private"
//if you want everything to be private.

	//Constructors/destructor these are private, so only friend classes will 
	//be able to create cards
	//Default constructor
	card();
	//Parameterized constructor
	card(const char*, const char*, int);
	//Copy constructor
	card(const card&);
	//Destructor
	~card();
	
	//Copies data to another card that already exists. Because the card already exists,
	//you cannot use the copy constructor
	void copyTo(card&) const;
	//Outputs data to console
	void print() const;

	//Geters/setters	
	void setRank(const char*);
	char* getRank() const;
	void setSuit(const char*);
	char* getSuit() const;
	//THe second data member here is defaulted to false
	void setValue(int,bool = false);
	int getValue() const;
	
	//Data members
	char* rank;
	char* suit;
	int value;
	
	//Only these classes can use "card"s
	friend class deck;
	friend class player;
	friend class game;
	friend class hand;
};

