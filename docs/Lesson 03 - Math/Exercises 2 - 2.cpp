//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

/*
This proram inputs a character, and displays a coded character ofset from the input,
like with a code wheel.
*/


#include <iostream>

using namespace std;

int main() {
   
   char input, coded;
   
   cout << endl << "Enter character to be coded: ";
   cin >> input;
   
   coded = input + 15;
   
   cout << endl << "Coded character: " << coded << endl;

   cout << endl;
   system("pause");
   
   return 0;
}
