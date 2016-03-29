//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	//Declare an array of strings, ints, and chars to be inputted from 
	//the file
	string strings[5] = {};
	int ints[5] = {}, numInts;
	char chars[5] = {};

	//Declare variables to be used with our files
	ifstream fin;
	ofstream fout;

	//Open the file in the input stream - note you must include
	//the file extention (".txt").
	fin.open("File IO - Example - In.txt");

	//The actual data begins after a colon character, so ingore all data
	//until after the colon.
	fin.ignore(1000,':');

	//Loop three times, inputting the strings from the file
	for(int i = 0; i < 3; i++)
		fin >> strings[i];

	//Ignore the data until another colon
	fin.ignore(1000,':');

	//Input the number of ints to input, and loop that many times. Note
	//that if this is greater than five, this will try to go off the end
	//of the array and create an error.
	fin >> numInts;
	for(int i = 0; i < numInts; i++)
		fin >> ints[i];

	//Ignore the data until another colon
	fin.ignore(1000,':');

	//Input characters until the file says it cannot input any more data.
	//Again, if this happens more than five times you will get an error,
	//as 5 is the size of the chars array.
	for(int i = 0; fin.good(); i++)
		fin >> chars[i];

	//Close the input file, as we are done with it
	fin.close();


	//Output the data to the console so we can see the input worked 
	//correctly
	for(int i = 0; i < 5; i++)
		cout << strings[i] << " ";
	cout << endl;
	for(int i = 0; i < 5; i++)
		cout << ints[i] << " ";
	cout << endl;
	for(int i = 0; i < 5; i++)
		cout << chars[i] << " ";
	cout << endl;


	//Open the output file - note this will create the file it it does not
	//already exist. If it already exists, it will overwrite it.
	fout.open("File IO - Example - Out.txt");

	//Output the full arrays, one character from each per line. There's no
	//particular reason to do it this way, but this is an example. Note 
	//that this is exactly the same as outputting it to the console, except
	//you are using your variable "fout" rather than "cout."
		//Additionally, since we intialized our arrays to 0, if there is
		//nothing in the value, it operator won't print anything.
	for(int i = 0; i < 5; i++)
		fout << strings[i] << " " << ints[i] << " " << chars[i] << endl;

	//Close the output file, as we are done with it.
	fout.close();

	cout << endl;
	system("pause");
	
	return 0;
}
