//If you are not sure what some lines of code do, try looking back at
//previous example programs, notes, or ask a question.

#include <iostream>

using namespace std;

// Forward declare the LinkedList class for the node to use
class LinkedList;

// Example node class for linked lists
class node {
	// Paramterized constructor
	node(int v, node* n = NULL);
	// Destructor
	~node();

	// Data members. Note that one part is the data held in the node,
	// and one part is a pointer (or link) to the next node in the list
	int value;
	node* next;

	// We only want our list class to use nodes, so we can make the node
	// constructor private, and have the list class as a friend
	friend class LinkedList;

	// We also need the list insertion operator to be a friend of the node
	// class so it can retrieve values from nodes in the list.
	friend ostream& operator<<(ostream& out, const LinkedList& src);
};

// Example singly-circularly linked list class
// values will be added and removed at the "head" of the list, 
// making this technically a stack. We'll learn more about those later
class LinkedList {
public:
	// Default constructor
	LinkedList();
	// Desctructor
	~LinkedList();

	// Example manipulation functions
	void addValue(int value);
	int removeValue();

	// You'd usually have several more functions here, but for the purposes
	// of this example only the essential few have been shown

	// Output operator
	friend ostream& operator<<(ostream& out, const LinkedList& src);

private:
	node* head;
};

node::node(int v, node* n) {
	value = v;
	next = n;
}

node::~node() {

}

LinkedList::LinkedList() {
	// Start with no nodes
	head = NULL;
}

// Clear all nodes (delete memory)
LinkedList::~LinkedList() {
	// While we still have nodes in the list
	while(head) {
		// Store a pointer to the next node 
		node* temp = head->next;
		// Delete the current head node
		delete head;
		// Set the head node to the next node.
		// Note that when we get to the end of the list, this will
		// make head NULL, stopping this loop.
		head = temp;
	}
}

void LinkedList::addValue(int value) {
	// Here we create a new node with the new value and "head" as the next node
	// and set head to point to it. This inserts the new node at the start of the list,
	// as it will be the new head, and point to the previous head node. Note that if
	// head was NULL, the new node will have NULL as the next node, signifying that it's
	// the last node in the list.
	head = new node(value,head);
}

int LinkedList::removeValue() {
	int result = 0;
	// Check that we have at least one node
	if(head) {
		// Get result
		result = head->value;
		// Store a pointer to the next node
		node* temp = head->next;
		// Delete the head node
		delete head;
		// Set the head to the next node. If we just removed the last node, head will
		// be set to NULL, signifying that the list is empty.
		head = temp;
	}
	return result;
}

// Operator to output the list graphically
ostream& operator<<(ostream& out, const LinkedList& src) {
	// Declare temp pointer to iterate through the list
	node* temp = src.head;
	// Iterate through the list
	while(temp) {
		out << temp->value;
		// Write an arrow if there is another node
		if(temp->next) {
			out << " -> ";
		}

		// Move the next node
		temp = temp->next;
	}

	// Return out for chaining
	return out;
}

int main() {
	// Test our list class
	
	LinkedList l1;
	cout << "List 1: " << l1 << endl;

	for(int index = 0; index < 10; index++) {
		l1.addValue(index);
	}

	cout << "List 1: " << l1 << endl;

	l1.removeValue();
	l1.removeValue();
	l1.removeValue();

	cout << "List 1: " << l1 << endl;

	system("pause");
	return 0;	
}
