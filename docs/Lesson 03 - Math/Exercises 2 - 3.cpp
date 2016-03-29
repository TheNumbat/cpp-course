//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

/*
This program demonstrates how changing operator precedence can have dramtic
effect on the result of your statement.
*/


#include <iostream>

using namespace std;

int main() {
   
   int order1 = 5 * 7 - 5 % (7 / 5 % 5);
   int order2 = 5 * (7 - 5 % 7 / 5) % 5;
   int order3 = ((5 * 7) - 5 % 7) / 5 % 5;
   int order4 = 5 * 7 - 5 % 7 / 5 % 5;

   cout << endl << "5 * 7 - 5 % (5 * 7 % 5) = " << order1 << endl;
   cout << "5 * (7 - 5 % 5 * 7) % 5 = " << order2 << endl;
   cout << "((5 * 7) - 5 % 5) * 7 % 5 = " << order3 << endl;
   cout << "5 * 7 - 5 % 5 * 7 % 5 = " << order4 << endl;

   cout << endl;
   system("pause");
   
   return 0;
}
