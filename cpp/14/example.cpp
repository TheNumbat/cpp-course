// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>
#include <cstring>

using namespace std;

class deck {};
class card {
public:
	card();
	card(const char* r); // Constant char pointer parameter means that the pointer
						 // cannot be moved. Also, it allows you to pass string
						 // literals ("literal")
	card(const card& src); // Copy constructor
	
	char* getRank() const; // Constant because it will not change the rank member
	void setRank(const char* r); // Not constant because it will change the rank member

private:
	// Private data member
	char rank[10];

	// The print function will be able to access the private rank member of a card
	friend void print(const card& c);
	// The deck class will be able to access private members of cards
	friend class deck;
};

card::card() {
	// Clear rank
	strcpy(rank,"");
}

card::card(const char* r) {
	// Copy rank
	strcpy(rank,r);
}

// Passed by const reference in copy constructor to prevent infinite call
// loop
card::card(const card& src) {
	// Copy the rank member from the source card
	strcpy(rank,src.rank);
}

char* card::getRank() const {
	// This function cannot change rank
	return (char*)rank;
}

void card::setRank(const char* r) {
	// Copy rank
	strcpy(rank,r);
}

// Note that if this was a member function (it is NOT), this could also be constant
// because it does not change any data in the card. However, normal functions
// (as in not member functions) cannot be constant.
void print(const card& c) {
	// Output card. This function can access "c.rank" even though it's a private
	// data member because this is a friend function to the card class
	cout << "Card rank: " << c.rank << endl;
}

int main() {

	card c1;
	const card c2("king"); // You must give the rank here, because you cannot call
						   // setRank on a const card

	c1.setRank("queen");
	// c2.setRank("jack"); This would give an error

	card c3(c1); // Create a copy of card one using the copy constructor

	// Note that the print function is not called from an instance of the class,
	// as it is not a member function.
	print(c1);
	print(c2);
	print(c3);

	// getRank is allowed on c2 because it is a constant member
	char* r1 = c1.getRank();
	char* r2 = c2.getRank();
	char* r3 = c3.getRank();

	cout << "rank 1: " << r1 << endl
		 << "rank 2: " << r2 << endl
		 << "rank 3: " << r3 << endl;

	system("pause");
	return 0;
}
