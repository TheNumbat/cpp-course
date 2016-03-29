
#include "player.h"

//Default constructor
player::player() {
	//Set data members to default values
	hand = NULL;
	cards = 0;
}

//Intialize data mebers
void player::init(int hSize) {
	//Setup data members, allocate hand memory
	maxH = hSize;
	hand = new card[hSize];
	cards = 1;
	playing = true;
}

//Output cards
void player::printHand() const {
	//Loop through cards
	for(int i = 0; i < cards; i++) {
		//If not a face card output the numberic value
		if(hand[i].value != 1 && hand[i].value <= 10)
			cout << "      " << hand[i].value;
		//If a face card output the rank string
		else
			cout << "      " << hand[i].rank;
		//Output the suit
		cout << " of " << hand[i].suit << endl;
	}
}

//Destructor
player::~player() {
	//Free memory
	delete[] hand;
}

