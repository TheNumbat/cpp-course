//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

//Used for an if statement
bool isNumGreat(int num);

int main() {
	
	int number;
	char character;
	
	
	
	cout << "Enter your favorite number: ";
	
	cin >> number;
	
	
	//This chain of if/else staements discovers if your number causes the isNumGreat function to return true,
	//or if your number is between 0 and 100, negative, or greather than 100
	if(isNumGreat(number)) {
		
		cout << "Your favorite number is the answer to life, the universe, and everything!" << endl;
		
	} else if (number >= 0 && number <= 100) {
		
		cout << "Your favorite number is between 0 and 100!" << endl;
		
	} else if (number < 0) {
		
		cout << "Your favorite number is negative!" << endl;		
		
	} else {
		
		cout << "Your favorite number is greater than 100!" << endl;
		
	}
	
	
	
	
	
	cout << endl << "Enter a letter a, b, c, d, e, or f: " << endl;
	
	cin >> character;
	
	
	//This switch statement detects if the letter is an a, or a b, c, or d, or an e - note that if you enter an
	//e you will get the result from e and f, or an f. Finally, it can also default to a statement if you did
	//not enter any of those letters.
	switch(character) {
		
		case 'a':
			cout << "The next letter is 'b'" << endl;
			break;
			
		case 'b':
		case 'c':
		case 'd':
			cout << "Your letter is boring." << endl;
			break;
			
		case 'e':
			cout << "eeeeeeeeee" << endl;
			
		case 'f':
			cout << "ffffffffff" << endl;
			break;
			
		default:
			cout << "You didn't enter one of those letters! D:" << endl;
		
	}
	
}


bool isNumGreat(int num) {
	
	//Num == 42 is a boolean statement, so the function can return the result of it.
	return num == 42;
	
}
