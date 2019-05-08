// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

// This is totally unrestricted - we can edit the pointed-to data and reassign 'value,'
// which will actually change where the passed-in pointer is pointing to at the call site.
void func1(char*& value);

// Here, we can still edit the pointed-to data and reassign 'value,' but this cannot
// effect its caller.
void func2(char* value);

// Here, we can reassign value within func3, but we cannot edit the pointed-to data.
void func3(const char* value);

// Here, we can edit the pointed-to data, but we cannot reassign 'value' within func4.
void func4(char* const value);

// Finally, we can neither reassign 'value' nor edit its data.
void func5(const char* const value);


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


// See Prototypes

void func1(char*& value) {
	value = "a";
	// It may not make sense why we might want to change the pointer in main 
	// right now, but it will when we talk about dynamic memory next week.
}

void func2(char* value) {

	// Sets the values in the c-string pointed to by value
	for(int i = 0; *value; i++) {
		*value = 'a' + i;
		value++;
	}
	value = NULL;
}

void func3(const char* value) {
	
	// Can't edit the pointed-to values

	value = NULL;
}

void func4(char* const value) {

	// Sets the values in the c-string pointed to by value
	for(int i = 0; *value; i++) {
		value[i] = 'a' + i;
	}

	// value = NULL; can't do this
}

void func5(const char* const value) {

	// Can't edit anything
}
