// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or email a question.

#include <iostream>

using namespace std;

// A function that will return an integer, and takes an integer and a double as parameters
int calc(int one, double two);

// A function that will not return anything, and takes two doubles as parameters
void displayDbls(double disp1, double disp2);

int main() {	
	int value_one = 60;
	double value_two = 0.89;
	
	int result;
	
	// Call the function calc. Note that the actual parameters do not need
	// to have the same names as the formal parameters.
	result = calc(value_one, value_two);
	
	// Display the result
	cout << "calc result: " << result << endl << endl;
	
	// Call the function displayDbls using literal values. Note that no return value
	// is captured, as displayDbls returns void.
	displayDbls(5.67, 10.436);
	
	return 0;
}

// Implementation of calc
int calc(int one, double two) {
	// Do some sort of calculation
	int result = -(one / two) * (one - two) / (-5648 / (one += two));
	
	// Return the result
	return result;
}

// Implementation of displayDbls
void displayDbls(double disp1, double disp2) {
	// Output the two parameters to the console
	cout << "Double value 1: " << disp1 << endl
		 << "Double value 2: " << disp2 << endl;
	
}