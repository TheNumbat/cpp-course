// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

int strlen(const char* str);
int strcpy(char* dest, const char* src);
char* getNewStr(int size);

int main() {

	// Declaring an array on the stack vs. on the heap
	char stackStr[50];
	char* heapStr = new char[50];

	// Both arrays can be used in the same ways
	for(int i = 0; i < 50; i++) {
		stackStr[i] = 'a';
		heapStr[i] = 'a';
	}

	// However, the string on the heap must be deleted when
	// you are done with it--if you never deleted it is considered
	// leaked memory.
	delete[] heapStr;
	heapStr = NULL;

	// Here, you can see how important is to delete your memory
	// before you lose access to it, or else this loop would
	// leak a ton of memory.
	for(int i = 0; i < 50; i++) {
		heapStr = new char[100];

		// If the memory was not deleted, a new set of memory
		// would be assigned to "heapStr," and the previous
		// memory would be leaked.
		delete[] heapStr;
		heapStr = NULL;
	}

	// Input a buffered string
	char buffer[100];
	cout << endl << "Enter a string: ";
	cin >> buffer;

	// Allocate the exact number of characters necessary.
	heapStr = new char[strlen(buffer) + 1];

	// Copy the string
	strcpy(heapStr,buffer);

	cout << endl << "Exactly sized word: " << heapStr << endl << endl;

	// Delete the string
	delete[] heapStr;
	heapStr = NULL;

	// Finally, here is a function that will return dynamic memory.
	char* newStr = getNewStr(10);

	// the memory originally created in the function can be deleted
	// here, at the end of main
	delete[] newStr;


	system("pause");
	return 0;
}

char* getNewStr(int size) {

	// Create a new dynamically allocated character array and return it.
	// The calling function will still have access to the memory, so it
	// does not need to be deleted here.
	return new char[size];
}

int strlen(const char* str) {
	int counter = 0;

	// Loop until you find a value that equals 0, the null char
	// (which marks the end of the string)
	while(str[counter])
		counter++;

	return counter;
}

int strcpy(char* dest, const char* src) {

	int counter;

	// Loop along the length of the source string,
	// and copy each character
	for(counter = 0; counter < strlen(src); counter++)
		dest[counter] = src[counter];

	// Remember to add a null character at the end
	// of the destination string
	dest[counter] = '\0';
}
