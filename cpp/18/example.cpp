// If you are not sure what some lines of code do, try looking back at
// previous example programs, notes, or ask a question.

#include <iostream>
#include <vector>

using namespace std;

// Base class
class animal {
public:
	animal();
	// You're usually going to want to make destructors virtual so the specific one will be called before the general one
	virtual ~animal();

	// Speak is virtual so subclasses can override it
	virtual void speak() const;

// Inherited classes will have access to this data
protected:
	char name[10]; // Example data

// Inherited classes will NOT have access to private data
private:
	int ID; // Example data
};

// 1st inherited class
class dog : public animal {
public:
	// Normal constructor/destructor
	dog();
	// This should not be a base class, so we don't make this virtual
	~dog();

	void speak() const;

// Dog can have its own private data
private:
	char color;
};

// 2nd inherited class
class cat : public animal {
public:
	// Normal constructor/destructor
	cat();
	// This should not be a base class, so we don't make this virtual
	~cat();	

	void speak() const;

// Cat can have its own private data
private:
	// Some data
};

animal::animal()  {
	cout << "animal constructor" << endl;
}

animal::~animal() {
	cout << "animal destructor" << endl;
}

void animal::speak() const {
	cout << "some animal sound" << endl;
}

dog::dog() {
	cout << "dog constructor" << endl;
}

dog::~dog() {
	cout << "dog destructor" << endl;
}

void dog::speak() const {
	cout << "bark!" << endl;
}

cat::cat() {
	cout << "cat constructor" << endl;
}

cat::~cat() {
	cout << "cat destructor" << endl;
}

void cat::speak() const {
	cout << "meow!" << endl;
}


int main() {
	// Polymorphism won't work here
	vector<animal> animals;
	// Polymorphism will work here
	vector<animal*> kennel;

	cout << endl << "Constructing a dog:" << endl;
	dog d; 
	cout << endl << "Constructing a cat:" << endl;
	cat c; 
	cout << endl << "Constructing an animal:" << endl;
	animal a;
	// Add animals to animals vector. Here, everything gets turned into just an "animal," making polymorphism useless
	cout << endl << "Pass-by-value copies will be destructed as animals:" << endl;
	animals.push_back(d);
	animals.push_back(c);
	animals.push_back(a);

	// Add animals to kennel vector. Here, each animal retains its real type of dog or cat
	for(int index = 0; index < 3; index++) {
		cout << endl << "Dynamically constructing a dog:" << endl;
		kennel.push_back(new dog);
		cout << endl << "Dynamically constructing a cat:" << endl;
		kennel.push_back(new cat);
	}

	// Here, all the animals will output the basic "some animal sound"
	cout << endl << endl << "NON-POLYMORPHIC VECTOR: SPEAK" << endl;
	for(int index = 0; index < animals.size(); index++) {
		animals[index].speak();
	}
	cout << endl;;

	// Here, all the animals will output their real "bark" or "meow"
	cout << endl << "POLYMORPHIC VECTOR: SPEAK" << endl;
	for(int index = 0; index < kennel.size(); index++) {
		kennel[index]->speak();
	}
	cout << endl;

	// Delete polymorphic animals
	for(int index = 0; index < kennel.size(); index++) {
		cout << endl << "Destructing some polymorphic animal:" << endl;
		delete kennel[index];
	}
	
	cout << endl << "Destructing static dog, cat, animal, and then non-polymorphic animal vector:" << endl;
	return 0;
}
