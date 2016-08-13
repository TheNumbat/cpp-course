// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

// This will take a pointer to a character value (or array), and can change the data in main
void func1(char* value);
// This will also take a char pointer, but WITHIN THE FUCNTION it cannot change where the pointer 
// points, meaning you can't do stuff like value++. It can still change the data in main.
void func2(const char* value);
// This function is just like the first, but not only can it change the data in main, it can
// actually change where the pointer in main is pointing to.
void func3(char*& value);

int main() {

	char cstring[50];
	int integer = 0;

	// Creates an integer pointer and assigns it to the address of "integer"
	int* valuePtr = &integer;

	cout << valuePtr << endl; // This outputs the address of "integer"
	cout << *valuePtr << endl; // This will output the actual value of "integer"
	*valuePtr = 5; // This actually sets the value in "integer" to 5
	cout << integer << endl; // This will output the 5


	// Creates a pointer to a character and points it to the first element in the c-string array
	char* stringPtr = cstring;
	cout << "Enter a string: ";
	cin >> cstring;

	// Iterate through the string using the pointer
	while(*stringPtr) {
		cout << *stringPtr << endl;
		stringPtr++;
	}
	// Now, "stringPtr" will be pointing off the end of the array, so using it would likely result in a seg fault.
	// It's a good idea to set it to NULL so that you program can check if it is valid in the future.
	stringPtr = NULL;


	// Declares a void pointer and sets it to point to "integer"
	void* voidPtr = &integer;
	*(int*)voidPtr = 10; // Sets the value to 10 - note that you must specify that "voidPtr" is pointing to an integer
	cout << endl << *(int*)voidPtr << endl; // Again, you must specify that "voidPtr" is pointing to an integer


	// End program
	cout << endl;
	system("pause");	
	return 0;
}


// SEE PROTOTYPES
void func1(char* value) {
	// Sets the values in the c-string pointed to by value
	for(int i = 0; *value; i++) {
		*value = 'a' + i;
		value++;
	}
}

void func2(const char* value) {
	// This works because offset notation does NOT move the pointer
	// Note that if value held less than 5 values, this would most likely create a seg fault
	for(int i = 0; i < 5; i++) {
		cout << value[i] << endl;
	}
}

void func3(char*& value) {
	// It doesn't make sense to change the pointer in main right now, but it will when
	// we talk about dynamic memory next week.
}
