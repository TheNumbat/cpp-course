//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

/*
This program inputs two integers from the user, and outputs the results of adding,
subtracting, multiplying, and dividing them.
*/


#include <iostream>

using namespace std;

int main() {
   
   int one, two;
   int add, sub, mult, div;
   
   cout << endl << "Enter first integer: ";
   cin >> one;
   cout << "Enter second integer: ";
   cin >> two;
   
   add = one + two;
   sub = one - two;
   mult = one * two;
   div = one / two;
   
   cout << endl << one << " + " << two << " = " << add << endl;
   cout << one << " - " << two << " = " << sub << endl;
   cout << one << " * " << two << " = " << mult << endl;
   cout << one << " / " << two << " = " << div << endl;

   cout << endl;
   system("pause");
   
   return 0;
}
