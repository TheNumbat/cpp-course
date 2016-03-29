//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

/*
This program prompts the user for each of the fundamental data types
(except boolean), and displays them in an orgranized way.
*/

#include <iostream>

using namespace std;

int main() {
   
   int intInput;
   char charInput;
   double dblInput;
    
   cout << endl << "Enter an integer: ";
   cin >> intInput;
   
   cout << "Enter a decimal value: ";
   cin >> dblInput;
   
   cout << "Enter a character: ";
   cin >> charInput;
   
   cout << endl << endl << "The user entered the following data: " << endl
        << "   Integer: " << intInput << endl << "   Double: " << dblInput
        << endl << "   Character: " << charInput << endl << endl;
        
   system("pause");
   
   return 0;
}
