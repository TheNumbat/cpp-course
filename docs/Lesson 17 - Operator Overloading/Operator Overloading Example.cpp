//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

// Example class implementing several overloaded operators
class Vector2 
{
public:
	// Default constructor
	Vector2();
	// Paramterized constructor
	Vector2(int _x, int _y);
	// Copy constructor
	Vector2(const Vector2& src);

	// Destructor
	~Vector2();

	// Assignment operator
	Vector2& operator=(const Vector2& src);

	// Example math operators
	Vector2 operator+(const Vector2& src); // Note that this is not returned by reference, 
										   // as we are returning a new object
	Vector2& operator+=(const Vector2& src); // Note that this is returned by reference, 
											 // as we are returning an object that already exists

	// Example comparison operators
	bool operator==(const Vector2& comp);
	bool operator<(const Vector2& comp);

	// Input/output operators
	friend ostream& operator<<(ostream& out, const Vector2& src);
	friend istream& operator>>(istream& in, Vector2& src); // Note that src is not constant, 
														   // as its values will be changed

private:
	// Data members
	int x, y;
};

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2& src)
{
	// Don't have to do any checking here, as we know we are creating a new object
	x = src.x;
	y = src.y;
}

Vector2::~Vector2()
{

}

Vector2& Vector2::operator=(const Vector2& src)
{
	// Check that you're not assigning the object to itself
	if(this != &src)
	{
		x = src.x;
		y = src.y;
	}
	// Return for chaining
	return *this;
}

Vector2 Vector2::operator+(const Vector2& src)
{
	// Use the paramterized constructor to return a new Vector2
	// with the added data
	return Vector2(x + src.x, y + src.y);
}

Vector2& Vector2::operator+=(const Vector2& src)
{
	// Here you want to modify the calling object
	x += src.x;
	y += src.y;
	return *this;
}

bool Vector2::operator==(const Vector2& comp)
{
	// Compare data members
	return x == comp.x && y == comp.y;
}

bool Vector2::operator<(const Vector2& comp)
{
	// Compare data members
	return x < comp.x && y < comp.y;
}

ostream& operator<<(ostream& out, const Vector2& src)
{
	// Output values. Note that there is no calling object
	out << "x: " << src.x << " y: " << src.y;
	// Return for chaining
	return out;
}

istream& operator>>(istream& in, Vector2& src)
{
	// Input values
	in >> src.x >> src.y;
	// Return for chaining
	return in;
}

int main() 
{
	Vector2 v1;
	Vector2 v2(1,5);
	Vector2 v3(v2);

	cout << "v1: " << v1 << endl
		 << "v2: " << v2 << endl
		 << "v3: " << v3 << endl << endl;

	Vector2 v4 = v2 + v3;
	Vector2 v5;
	v5 += v4;

	bool test1 = v4 == v5;
	bool test2 = v1 < v4;

	cout << "v4: " << v4 << endl
		 << "v5: " << v5 << endl
		 << "test1: " << test1 << endl
		 << "test2: " << test2 << endl << endl;

	// THIS WILL CALL THE COPY CONSTRUCTOR
	Vector2 v6 = v3;
	// THIS WILL CALL THE ASSIGNMENT OPERATOR
	Vector2 v7;
	v7 = v3;

	cout << "v6: " << v6 << endl
		 << "v7: " << v7 << endl << endl;

	system("pause");

	return 0;
}
