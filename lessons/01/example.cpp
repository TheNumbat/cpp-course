//If you are not sure what some lines of code do, try looking back at
//previous example programs, or email a question.

// This heatder file allows the use of the string data type.
#include <string>

using namespace std;

int main() {
   
   // This declares an integer variable with the indentifier "userAge"
   int userAge;
   
   // This line sets userAge to contain the integer value 34
   userAge = 34;
   
   // This line sets userAge to contain the interger value 23, overwritting 
   // the previous value, 34
   userAge = 23;
   
   // This line declares a character value with the identifier letterInput
   // and intializes it to hold the value 'c'
   char letterInput = 'c';
   
   // Finally, this line decalres a string value with the identifier address.
   // Note that "string" is not highlighted. Only the fundamental data types
   // are highlighted in your editor. Additionally, the value is intialized
   // with a string literal.
   string address = "1234 Nowhere St. Reno, NV";
   
	return 0;
}
