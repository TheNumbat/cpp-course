

MyClass::MyClass(MyClass source) {
	
}


void myFunc(int, int = 5);

void myFunc(int value) {
	cout << value << endl;
}

myFunc(10,5);
myFunc(10);


void main() {
	MyClass a;
	
	MyClass b(a);
	
	int x;
	myFunc(x);
	cout << x << endl;
}








struct object {
	function();
	
	int x;
};



object o;
o.function();
o.x = 5;





object.function(); //Member

function(object); //Friend


object::function() {
	
	object* o;
	
	(*o).x;
	o->x;
	
	
}

function(object c) {
	//do stuff
}










int x;

int* y = &x;

int** z = &y;

**z = 5;

int* a = y;














int* arr = new int[50];

arr[0] = 5;










int x;

int* y = &x;

x = 346345;
*y = 2346345;






















int* function() {
	return new int[10];
}

int* mem = function();
















void function(int& x) {
	x = 10;
}

function(num);
//num = 10 now

void function(int* x) {
	*x = 10;
}

function(&num);
//num = 10 now

//These do the same thing, but with different types of parameters













cout << rand() << endl;
//or
int number = rand();

cout << number << endl;











