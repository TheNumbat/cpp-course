//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

// A diamond inheritance pattern is demonstrated here using virtual inheritance
// All the functions are implemented in the class definitions for conciseness

// our base class
class animal {
public:
	animal() {cout << "animal constructor" << endl;};
	// You're usually going to want to make your destructor virtual so the specific one will be called before the general one
	virtual ~animal() {cout << "animal destructor" << endl;};

	// Speak is pure virtual so "animal" is an abstract class
	virtual void speak() const = 0;

protected:
	// other data
};

// specific type of "animal," inherited
class mammal : public virtual animal {
public:
	mammal() {cout << "mammal constructor" << endl;};
	// the destructor here is also virtual, as this will be a base class
	virtual ~mammal() {cout << "mammal destructor" << endl;};

	// we do not implement "speak", so "mammal" is also abstract

protected:
	// other data
};

// specific type of "animal," inherited
class flying : public virtual animal {
public:
	flying() {cout << "flying constructor" << endl;};
	// the destructor here is also virtual, as this will be a base class
	virtual ~flying() {cout << "flying destructor" << endl;};

	// we do not implement "speak", so "flying" is also abstract

protected:
	// other data
};

// specific class that inherits from both "mammal" and "flying"
class bat: public mammal, public flying {
public:
	bat() {cout << "bat constructor" << endl;};
	// not virtual, this ends the chain
	~bat() {cout << "bat destructor" << endl;};

	// here we implement "speak," making bat a non-abstract class
	void speak() const {cout << "squeak!" << endl;};

private:
	// other data
};

int main() {
	// we can't create any of these, as they are abstract
	// animal a;
	// mammal m;
	// flying f;

	cout << endl << "constructing bat" << endl << endl;
	
	bat b;

	cout << endl << "calling speak on general animal pointer" << endl << endl;

	animal* someAnimal = &b;
	someAnimal->speak();

	cout << endl << "calling speak on general mammal pointer" << endl << endl;

	mammal* someMammal = &b;
	someMammal->speak();

	cout << endl << "calling speak on general flying pointer" << endl << endl;

	animal* someFlying = &b;
	someFlying->speak();

	cout << endl << "destructing bat" << endl << endl;
	return 0;
}
