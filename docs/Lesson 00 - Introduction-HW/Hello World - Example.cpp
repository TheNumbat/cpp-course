//If you are not sure what some lines of code do, try looking back at
//previous example programs, or ask a question.



/*
This program is the traidtional "Hello World" program that one writes when
trying out a programming language for the first time. It simply outputs the
test "Hello World!" to the screen, and waits for the user to press a key.
*/



//This includes the code from "iostream," which is part of the C++ language
//it is used for console input and output, and allows use of "cout"
#include <iostream>

//This includes the code from "cstdlib," which is aprt of the C++ language
//it is used for the system() function. However, system("pause") can be used
//at any time in dev C++, but it is officially included in cstdlib
#include <cstdlib>

//This specifies which "cout" you are using. without this, you would have to type
//"std::cout" instead of just "cout" later in the program.
using namespace std;

//This is the main function. This is what is called when your program starts,
//and your program ends when it ends. It begins with "int," which means it 
//must return an integer value. More on that later. For now, just be sure to
//have "return 0;" at the very end of the main function;
int main() {
   
   //This is how to output test to the console, which is the window that opens when
   //you run the program. "<<" is the insertion operator, which means that you send
   //whatever is on the left of the operator into what is on the left. Hence, the
   //test "Hello World!" is sent to "cout," which is the onsole. Seding "endl"
   //simulates pressing enter; it ends the line and moves to the next one.
	cout << "Hello World!" << endl << endl;
	
	//This displays the message "Press any key to continue..." and waits for the user
	//to press a key before continuing the program. If this is not included, when the
	//program gets to the line after this one, it will instandly close and in this case,
	//the user won't see the "Hello World!" message.
	system("pause");
	
	//This ends the main funtion.
	return 0;
}
