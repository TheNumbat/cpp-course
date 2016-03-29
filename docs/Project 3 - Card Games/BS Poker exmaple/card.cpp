
#include "card.h"
#include <cstring>

//Default constructor
card::card() {
	//Set the data members to default values
	rank = new char[5];
	suit = new char[5];
	
	strcpy(rank,"rank");
	strcpy(suit,"suit");
	value = 0;
}

//Parameterized constructor
card::card(const char* r, const char* s, int v) {
	//Set the data members to specified values
	rank = new char[strlen(r) + 1];
	suit = new char[strlen(s) + 1];
	
	strcpy(rank,r);
	strcpy(suit,s);
	value = v;
}

//Copy constructor
card::card(const card& src) {
	//Copy data members from source card
	rank = new char[strlen(src.rank) + 1];
	suit = new char[strlen(src.suit) + 1];
	
	strcpy(rank,src.rank);
	strcpy(suit,src.suit);
	value = src.value;
}

//Destructor
card::~card() {
	//Free memory
	delete[] rank;
	delete[] suit;	
}

//A copy function so that you can copy values from one card to another if they already exist
//(because they already exist, you cannot use the copy constructor)
void card::copyTo(card& dest) const {
	//Free memory -- the card already exists, so it will have memory
	delete[] dest.rank;
	delete[] dest.suit;
	
	//Copy data members
	dest.rank = new char[strlen(rank) + 1];
	dest.suit = new char[strlen(suit) + 1];
	
	strcpy(dest.rank,rank);
	strcpy(dest.suit,suit);
	dest.value = value;
}

void card::print() const {
	//Output values
	cout << rank << " " << suit << " " << value << " ";
}

void card::setRank(const char* r) {
	//Copy to rank
	delete[] rank;
	rank = new char[strlen(r) + 1];
	strcpy(rank,r);
}

char* card::getRank() const {
	//Return rank
	return rank;
}

void card::setSuit(const char* s) {
	//Copy to suit
	delete[] suit;	
	suit = new char[strlen(s) + 1];
	strcpy(suit,s);
}

char* card::getSuit() const {
	//Return suit
	return suit;
}

void card::setValue(int v, bool resetRank) {
	//Set value
	value = v;
	//If specified, set the rank to the correct string based on the value
	if(resetRank) {
		switch(v) {
			case 1:
				setRank("ace");
				break;
			case 2:
				setRank("two");
				break;
			case 3:
				setRank("three");
				break;
			case 4:
				setRank("four");
				break;
			case 5:
				setRank("five");
				break;
			case 6:
				setRank("six");
				break;
			case 7:
				setRank("seven");
				break;
			case 8:
				setRank("eight");
				break;
			case 9:
				setRank("nine");
				break;
			case 10:
				setRank("ten");
				break;
			case 11:
				setRank("jack");
				break;
			case 12:
				setRank("queen");
				break;
			case 13:
				setRank("king");
				break;
			default:
				setRank("rank");
				break;
		}
	}
}

int card::getValue() const {
	//Return the value
	return value;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
