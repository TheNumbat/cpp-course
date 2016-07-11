//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;


// SEE THE LAST EXAMPLE FOR COMMENTS ON THE ACTUAL LIST DATA STRUCTURE,
// COMMENTS HERE ARE ONLY ON TEMPLATE FEATURES


// Our forward declaration has to be template
template <typename T> class LinkedList;

// Here our node is templated so each node can hold an arbitrary data type
template <typename T> 
class node {
	// Our value paramter is of our template paramter "T"
	// This is also implemented here, in the class definition
	node(T v, node* n = NULL) {
		value = v;
		next = n;
	}
	// Don't need this to do anything
 	~node() {}

	// The value this node holds should, of course, be of generic type "T"
	T value;
	node* next;

	// Note that we must specify that LinkedList is templated
	friend class LinkedList<T>;

	// We can't implement a friend here, as it's not a member
	// We also have to specify what kind of list we're outputting, so we do LinkedList<type>.
	// Hence, the friend must also be templated. Note that the template declaration goes before
	// "friend," and that we must use U as our argument, as T is already defined.
	template <typename U> friend ostream& operator<<(ostream& out, const LinkedList<U>& src);
};

// Here our actual list is templated to accomodate the templated nodes and arbitrary data input/output
template <typename T> 
class LinkedList {
public:
	LinkedList() {
		head = NULL;
	}
	// We need a copy constructor for later
	LinkedList(const LinkedList& src) {
		head = NULL;
		node<T>* temp = src.head;
		while(temp) {
			addValue(temp->value);
			temp = temp->next;
		}
	}
	// We need an assignment operator for later
	LinkedList& operator=(const LinkedList& src) {
		while(head) {
			node<T>* temp = head->next;
			delete head;
			head = temp;
		}
		node<T>* temp = src.head;
		while(temp) {
			addValue(temp->value);
			temp = temp->next;
		}
	}
	~LinkedList() {
		while(head) {
			node<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}

	// Here we add a value of generic type T
	void addValue(T value) {
		head = new node<T>(value,head);
	}
	// Here we remove a value, returning generic type T
	T removeValue() {
		T result;
		if(head) {
			result = head->value;
			node<T>* temp = head->next;
			delete head;
			head = temp;
		}
		return result;
	}

	// Again, we can't implement a friend here, and we must specify that the LinkedList uses type U
	template <typename U> friend ostream& operator<<(ostream& out, const LinkedList<U>& src);

private:
	// Our node must use generic type T
	node<T>* head;
};

// Here we actually implement our friend, note the use of another template
template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& src) {
	node<T>* temp = src.head;
	while(temp) {
		// Output brackets for list-of-list clarity
		// Later, we create a list of lists, so in that case "out << temp->value"
		// will actually recursively call this function 
		out << "[" << temp->value << "]";
		if(temp->next) {
			out << " -> ";
		}

		temp = temp->next;
	}

	return out;
}

int main() {
	// Declare list using integers
	LinkedList<int> intList;
	// Declare list using floats
	LinkedList<float> floatList;
	// Delcare list using lists that use integers
	// prior to c++11, you have to leave a space between two '>' brackets in a
	// nested template, otherwise the compiler thinks you're using the ">>" operator 
	LinkedList<LinkedList<int> > listList;

	// Output lists
	cout << "Int list: " << intList << endl;
	cout << "Float list: " << floatList << endl;
	cout << "List list: " << listList << endl;

	// Add values to the int list
	for(int index = 0; index < 10; index++) {
		intList.addValue(index);
	}

	// Add values to the float list
	for(float index = 0.5; index < 10; index++) {
		floatList.addValue(index);
	}

	// Add values to list list
	for(int index = 0; index < 10; index++) {
		LinkedList<int> value;
		for(int index = 0; index < 10; index++) {
			value.addValue(index);
		}
		listList.addValue(value);
	}

	// Output lists
	cout << "Int list: " << intList << endl;
	cout << "Float list: " << floatList << endl;
	cout << "List list: " << listList << endl;

	system("pause");
	return 0;	
}
