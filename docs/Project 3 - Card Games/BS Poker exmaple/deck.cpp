
#include "deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Default/parameterized constructor -- "s" is defaulted to 52
deck::deck(int s) {
	//Seed random number generator
	srand(time(NULL));
	
	//Allocate card memory
	size = s;
	cards = new card[size];
}

//Destructor
deck::~deck() {
	//Free memory
	delete[] cards;
}

//Input from file function
bool deck::input(istream& fin) {
	//Allocate buffer
	char* buffer = new char[20];
	int v;
	
	//Input cards from file
	for(int i = 0; i < size; i++) {
		fin >> buffer;
		cards[i].setRank(buffer);
		fin >> buffer;
		cards[i].setSuit(buffer);
		fin >> v;
		cards[i].setValue(v,false);
	}	
	
	//Free buffer
	delete[] buffer;
	
	//Return sucess or failure
	return fin.good();
}

//Shuffle the deck
void deck::shuffle() {
	//Allocate bool array to hold cards that we have already chosen
	bool* done = new bool[size]();
	//Allocate a copy of our card array so we can push cards into it
	//without overriting data
	card* shuffle = new card[size];
	
	int r;
	for(int i = 0; i < size; i++) {
		do {
			//Pick a random card until you find one that we haven't already chosen
			r = rand() % size;	
		} while(done[r]);
		
		//Mark the card as chosen
		done[r] = true;
		
		//Copy the random card into the "shuffle" array
		cards[r].copyTo(shuffle[i]);
	}
	
	//Copy the "shuffle" array into our actual card array
	for(int i = 0; i < size; i++)
		shuffle[i].copyTo(cards[i]);
	
	//Free temporrary "shuffle" and "done" arrays
	delete[] done;
	delete[] shuffle;
}

//Returns the next card in the deck
card deck::deal() const {
	//"static" means i will persist between funciton calls -- it's like a global variable that
	//can only be accessed within this function
	static int i = -1;
	//Increment the card index (i), and roll it over if it has reached the end of the deck
	++i %= size;
	//Return the card at the index
	return cards[i];
}

//Output deck
void deck::print() const {
	//Loop though and output each card
	for(int i = 0; i < size; i++) {
		cout << cards[i].rank << " " << cards[i].suit
			 << " " << cards[i].value << endl;
	}
}











