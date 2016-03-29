//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

//This declares a function that will return an integer, and takes two integer values.
int doSomething(int pepe, double rareVal);

//This declares a function that will not return anything, but output two doubles to 
//the screen
void displayDbls(double disp1, double disp2);

int main() {
	
	int myPepe = 60;
	double rarest = .89;
	
	int result;
	
	//This calles the function doSomething. Note that the actual parameters do not need
	//to be the same as the formal parameters.
	result = doSomething(myPepe, rarest);
	
	//Display the result
	cout << "doSomething result: " << result << endl << endl;
	
	//This calls the function displayDBls using literal values. Note that it is not assigned
	//to anything, as it does not have a return type.
	displayDbls(5.67, 10.436);
	
	return 0;
}

//This begins the implementation of doSomething
int doSomething(int pepe, double rareVal) {
	
	//Do random stuff with the parameters
	int result = -(pepe / rareVal) * (pepe - rareVal) / (-5648 / (pepe += rareVal));
	
	//Return the result
	return result;
}

//This begins the implentaiton of displayDbls
void displayDbls(double disp1, double disp2) {
	
	//Outputs the two parameters to the console
	cout << "Floating point value 1: " << disp1 << endl
		 << "Floating point value 2: " << disp2 << endl;
	
}
