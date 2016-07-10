//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

int addFrom(int);

int main() {
	
	char selection;
	
	//A simple do/while loop, where the loop will continue asking the user
	//to continue until they enter something that is not 'y'
	do {
		cout << "Continue? (y/n): ";
		cin >> selection;
	} while(selection == 'y');
	
	cout << endl << endl;
	
	//A nested for loop, will run the inner loop 10 times. Each time the outer
	//loop is run, i is incremented, and hence the first output number goes up
	//every ten outputs. Within each run of the outer loop, the inner loop sets
	//j to 0, and counts it up to 10, which produces each pair of outpout numbers.
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout << i << "-" << j << " ";
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	//This calls the recursive function
	cout << "Recursion example: " << addFrom(5) << endl << endl;
	
	system("pause");
	
	return 0;
}

//This is a recursive function. See the notes for how it works.
int addFrom(int x) {
	
	if(x == 1)
		return 1;
	else
		return x + addFrom(x - 1);
	
}
