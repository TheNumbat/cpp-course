//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>
#include <cstring>

using namespace std;


//CARD CLASS
class card {
public:
	//Default constructor
	card();
	//Parameterized constructor
	card(const char*, const char*, int);
	//Destructor
	~card();

	//Getters and setters. I realize that right now, some of these
	//are pretty much useless. However, you will often want
	//to use these for more complicated operations, for example
	//how the setRank and setSuit functions reallocate memory
	char* getRank();
	void setRank(const char*);
	char* getSuit();
	void setSuit(const char*);
	int getValue();
	void setValue(int);

	//A member that will print the card's data to the console
	void print();

private:
	char* rank;
	char* suit;
	int value;
};

//Default constructor
card::card() {
	cout << endl << "In default constructor!" << endl;

	//Set data members to default values
	rank = NULL;
	suit = NULL;
	value = 0;
}

//Parameterized constructor
card::card(const char* r, const char* s, int v) {
	cout << endl << "In Parameterized constructor!" << endl;

	//Set data members to the parameters
	rank = new char[strlen(r) + 1];
	suit = new char[strlen(s) + 1];
	strcpy(rank,r);
	strcpy(suit,s);
	value = v;
}

//Destructor
card::~card() {
	cout << endl << "In destructor!" << endl;

	//Delete the data members, if we allocated them
	//(delete will not delete if it is given a null pointer)
	delete[] rank;
	delete[] suit;
}

//Getters and setters
char* card::getRank() {
	return rank;
}

//As you can see, this setter is useful, because it automatically manages
//the dynamic memory
void card::setRank(const char* r) {
	delete[] rank;
	rank = new char[strlen(r) + 1];
	strcpy(rank,r);
}

char* card::getSuit() {
	return suit;
}

void card::setSuit(const char* s) {
	delete[] suit;
	suit = new char[strlen(s) + 1];
	strcpy(suit,s);
}

int card::getValue() {
	return value;
}

void card::setValue(int v) {
	value = v;
}

//This is a normal member function, and will output the card's values
void card::print() {
	//If suit points to null, say we don't have a suit
	if(!rank)
		cout << "no rank ";
	else
		cout << rank << " ";
	if(!suit)
		cout << "no suit ";
	else
		cout << suit << " ";
	cout << value << endl;
}
//END CARD CLASS


int main() {

	cout << endl << "Creating static card" << endl;

	//Create a card and a card pointer
	card card1;
	card* card2 = NULL;

	//Print inital values
	cout << endl << "Initial card:" << endl;
	card1.print();

	//Use setters
	card1.setRank("king");
	card1.setSuit("hearts");
	card1.setValue(13);

	//Print set valeus
	cout << endl << "After setters called:" << endl;
	card1.print();

	//Use getters
	char* rank = card1.getRank();
	char* suit = card1.getSuit();
	int value = card1.getValue();

	//Print gotten values
	cout << endl << "Values from card:" << endl
		 << rank << " " << suit << " " << value << endl;

	//Create dynamic card using the parameterized constructor
	cout << endl << "Creating dynamic card" << endl;
	card2 = new card("two","spades",2);

	//Print the card (note the use of the arrow operator)
	cout << endl << "Dynamic card:" << endl;
	card2->print();

	//Delete dynamic card. Note the destructor will be called here
	cout << endl << "Deleting dynamic card" << endl;
	delete card2;


	cout << endl << "End of program --- ";
	system("pause");
	//Note that the destructor for the statically declared card will
	//be called as main exits.
	return 0;
}
