//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>
#include <fstream>

using namespace std;

//Define a student structure datatype
struct student {
	char* firstName;
	char* lastName;
	char gender;
	float gpa;
};

//Function prototypes that work with students
void inputStudents(const char*,student*);
void displayStudents(student*);

int main() {

	//Dynamically alloacte five stduents
	student* students = new student[5];

	inputStudents("students.txt",students);

	displayStudents(students);

	//Remember to delete allocated memory
	//Remember that this memory was allocated within the
	//students, whithin the input function.
	for(int i = 0; i < 5; i++) {
		delete[] students[i].firstName;
		delete[] students[i].lastName;
	}

	system("pause");
	return 0;
}

void inputStudents(const char* fileName,student* data) {
	ifstream fin(fileName);

	for(int i = 0; i < 5; i++) {
		//Allocate the memory for each name. Note this is not
		//exactly sized, as we specify the max size of 10.
		data[i].firstName = new char[10];
		data[i].lastName = new char[10];

		//Input data
		fin >> data[i].firstName >> data[i].lastName >> data[i].gender >> data[i].gpa;
	}
}

void displayStudents(student* data) {

	for(int i = 0; i < 5; i++) {
		cout << "Student " << i << " : ";

		//Output data for each student
		cout << data[i].firstName << " " << data[i].lastName 
			 << " " << data[i].gender << " " << data[i].gpa
			 << endl;
	}
}
