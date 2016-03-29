#include "hand.h"


//Parameterized constructor
hand::hand(int type, int val1, int val2) {
	//Set data members
	lvl = (hand_type)type;
	v1.value = val1;
	v2.value = val2;
}

//Desctructor
hand::~hand() {
	//Does not need to do anything, as the hand class
	//does not allocate any memory that needs to be deleted
}

//Print function
void hand::print() {
	//Output the type of hand
	cout << hand_names[lvl] << ", ";
	//Switch on the hand type, as different types of output will be
	//needed for different types
	switch(lvl) {
		case HIGH_CARD - 1:
			//Just output the card
			cout << v1.rank << endl;
			break;
		case PAIR - 1:
		case TRIPLE - 1:
		case QUAD - 1:
			//Output the card and make it plural
			cout << v1.rank << "s" << endl;
			break;
		case TWO_PAIR - 1:
			//Output both cards
			cout << v1.rank << "s and " << v2.rank << "s" << endl;
			break;
		case STRAIGHT - 1:
			//Output the low through high card
			cout << v1.rank << " through " << v2.rank << endl;
			break;
		case STRAIGHT_FLUSH - 1:
			//Output the low through high card and suit
			cout << v1.rank << " through " << v2.rank << " of " << suit << endl;
			break;
		case FULL_HOUSE - 1:
			//Output the three of a kind and two of a kind
			cout  << v2.rank << "s over " << v1.rank << "s" << endl;
			break;
	}
}

