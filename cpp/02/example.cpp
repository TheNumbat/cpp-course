// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

// Remember to include iostream when using console IO
#include <iostream>

// Also remember to include this line (or type std:: each time)
using namespace std;

int main() {

   int input;
   
   // This line outputs the text "Basic IO Examples" to the screen,
   // and creates an empty line below it. Note that there are two
   // "endl" statements: one ends the line that includes the text,
   // and the other creates an empty line below it.
   cout << "Basic IO Examples" << endl << endl;
   
   // This line outputs a prompt for the user to enter an integer.
   // Note that there are no endlines at all, so that the user will
   // enter the number on the same line as the prompt.
   cout << "Enter an integer: ";
   
   // This line allows the user to input a value, and once they press
   // enter, it puts the value into the variable "input." Note that
   // this automatically ends the line.
   cin >> input;
   
   // Finally, this line outputs another empty line, and then text
   // describing the output, and then input variable, which
   // holds the user's input. It them ends the line and outputs
   // one more empty line.
   cout << endl << "User input: " << input << endl << endl;
   
   // As seen previously, this line holds the screen for the user.
   // once they press a key, the program will end.
   system("pause");
   
   return 0;
}
