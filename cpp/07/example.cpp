//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

//The function prototype of a function with a reference parameter. To specify the
//reference paramter, simply type and ampersand after the data type.
//Note that it does not return anything, as the data will be passed back through
//the reference parameter.
void addNumber(int&,int);

//This function prototype includes an array, which automatically acts as a reference
//parameter -- changes to the array within the funciton will also effect MAIN.
//Note that you do not need to specify the array size.
void setArray(int[],int,int);

int main() {
	
	int result = 5;

	cout << "Number before function: " << result << endl;

	//Passes the result value as a reference parameter, so that its value will
	//be changed within MAIN.
	addNumber(result, 10);

	cout << "Number after function: " << result << endl;

	//This declares an array of integers with a size of ten.
	int array[10];

	cout << endl;

	//This will output a garbage value, as the values in the array have not been
	//initialized. Note the use of array[0] to denote the first element.
	cout << "Garbage first value in array: " << array[0] << endl;

	//For loops are particularly useful in looping through arrays. This loop sets
	//the first value in the array to 1, the second to 2, and so on.
	for(int i = 0; i < 10; i++) {
		array[i] = i + 1;
	}

	//Output the fourth and sixth values in the array, which will now be 4. Note the 
	//use of array[3] and array[5] to denote the fourth and sixth elements.
	cout << "After the loop, the fourth value in the array is: " << array[3] << endl;
	cout << "After the loop, the sixth value in the array is: " << array[5] << endl;
	
	cout << endl;
	
	//This calls the setArray function, which will set the first 10 values in the
	//array "array" to 25. This will effect the "array" variable in MAIN.
	setArray(array, 10, 25);

	//Again, loop through the array, outputting each value. This shows that all the
	//elements in the array have indeed been set to 25.
	for(int i = 0; i < 10; i++) {
		cout << "Array element " << i << ": " << array[i] << endl;
	}

	cout << endl;

	//Declares a c-string that can hold 50 characters, or 49 characters if you don't
	//count the null character.
	char testString[50];

	//Input the string "in the agreegate," so that the word from the console will be
	//automatically copied to the array, with a null terminator at the end.
	cout << "Enter string: ";
	cin >> testString;

	//Loop though the array until you get to the null character, and output each
	//character in the string on a new line
	for(int i = 0; testString[i]; i++)
 		cout << testString[i] << endl;

	cout << endl;
	system("pause");
	
	return 0;
}

//This is the implemenation of the funciton with a reference parameter. As with the
//prototype, the reference parameter is specified with an ampersand. The function
//simply plus-equals the value into the result, but the important pard is that this
//code will change the value of the "result" variable in MAIN
void addNumber(int &addTo, int value) {
	addTo += value;
}

//This funciton loops through the elements in "arrayParam," setting each one to the
//value specified by the parameter "setValue." Note that this will change the values
//in the "array" variable in MAIN.
void setArray(int arrayParam[], int arraySize, int setValue) {
	for(int i = 0; i < arraySize; i++) {
		arrayParam[i] = setValue;
	}
}
