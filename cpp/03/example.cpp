// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

int main() {
   
   // These will all work as you expect
   int int1 = 5 + 7;
   int int2 = 5 - 7;
   int int3 = 5 * 7;
   
   // This will evaluate to 0, as 5 / 7 is between 0 and 1
   int int4 = 5 / 7;

   // This will evaluate to 2, as that is the remainder of
   // 7 / 5
   int mod1 = 7 % 5;
   
   // This will evaluate to 5, as 5 does not go into 7 at all,
   // so the remainder is just the entire number.
   int mod2 = 5 % 7;

   // This will evaluate to 30, as the multiplication is evaluated
   // before the subtraction.
   int order1 = 5 * 7 - 5;

   // This will evaluate to 3, as first the parenthesis is evaluated,
   // giving 2, which is then multiplied by 5, giving 10, and finally
   // modded with 7, giving a remainder of 3.
   int order2 = (7 - 5) * 5 % 7;
   
   // After these two lines, the variable will hold the value 12, as it
   // starts with 5, and 7 is added to itself.
   int combine1 = 5;
   combine1 += 7;
   
   // After these two lines, the variable will hold 14, as it starts with
   // 7, and is multiplied by 7 - 5, or two.
   int combine2 = 7;
   combine2 *= 7 - 5;
   
   // After these two lines, the character will have been transformed to
   // a 'g', as it was moved down 5 places.
   char char1 = 'b';
   char1 += 5;
   
   // After these two lines, the character will have been transformed from
   // a lowercase e to an uppercase E, as mentioned in the notes.
   char char2 = 'e';
   char2 = char2 - 'a' + 'A';
   
   
   
   // Output results
   cout << endl << "Integers:" << endl;
   cout << "5 + 7 = " << int1 << endl;
   cout << "5 - 7 = " << int2 << endl;
   cout << "5 * 7 = " << int3 << endl;
   cout << "5 / 7 = " << int4 << endl;

   cout << endl << "Modulo:" << endl;
   cout << "7 % 5 = " << mod1 << endl;
   cout << "5 % 7 = " << mod2 << endl;
   
   cout << endl << "Order of operations:" << endl;
   cout << "5 * 7 - 5 = " << order1 << endl;
   cout << "(7 - 5) * 5 % 7 = " << order2 << endl;
   
   cout << endl << "Combined assignment:" << endl;
   cout << "5 += 7 = " << combine1 << endl;
   cout << "5 *= 7 - 5 = " << combine2 << endl;
   
   cout << endl << "Character math:" << endl;
   cout << "b + 5 = " << char1 << endl;
   cout << "e - a + A = " << char2 << endl;
   
   // Hold the screen for the user
   cout << endl;
   system("pause");
   
   return 0;
}
