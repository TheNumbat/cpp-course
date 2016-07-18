// If you are not sure what some lines of code do, try looking back at
// previous example programs, or email a question.

// This header file allows the use of the string data type.
#include <string>

using namespace std;

int main() {
   
   // This declares an integer variable with the identifier "userAge"
   int userAge;
   
   // This line sets userAge to contain the integer value 34
   userAge = 34;
   
   // This line sets userAge to contain the integer value 23, overwriting 
   // the previous value, 34
   userAge = 23;
   
   // This line declares a character value with the identifier letterInput
   // and initializes it to hold the value 'c'
   char letterInput = 'c';
   
   // Finally, this line declares a string value with the identifier address.
   // Note that "string" is not highlighted. Only the fundamental data types
   // are highlighted in your editor. Additionally, the value is initialized
   // with a string literal.
   string address = "1234 Nowhere St. Las Vegas, NV";
   
	return 0;
}
