//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

//RNG (random number generator) includes
#include <cstdlib>
#include <ctime>

using namespace std;

//Defines a function that will have its third parameter defaulted to 2
int defaultFunction(int,int,int = 2);

//NOTE: INDENTATION IS DISPLAYED THROUGHOUT ALL THE EXAMPLES
//NOTE: ALL OF THE EXAMPLE PROGRAMS ARE BASICALLY MICROPROGRAMS

int main() {
	
	//Seed the RNG
	srand(time(NULL));

	cout << "Random number: " << rand() << endl;
	cout << "Random number 0-99: " << rand() % 100 << endl << endl;
	
	int x = 6;
	
	cout << "X: " << x << endl;
	
	//Increment x
	x++;
	
	cout << "X: " << x << endl;
	
	//Decrement x twice
	x--;
	x--;
	
	cout << "X: " << x << endl << endl;
	
	int result1 = defaultFunction(2,6);
	int result2 = defaultFunction(2,6,4);
	
	cout << "Result1: " << result1 << endl;
	cout << "Result2: " << result2 << endl << endl;

	
	system("pause");
	
	return 0;
}

//This function has a default parameter var = 2
int defaultFunction(int x, int y, int var) {
	
	return (x + y) / var;
	
}
