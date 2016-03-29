
#include <iostream>

using namespace std;

class LinkedList;

class node
{
	node(int v, node* p = NULL, node* n = NULL);
	~node();

	int value;
	node* next;
	node* prev;

	friend class LinkedList;

	friend ostream& operator<<(ostream& out, const LinkedList& src);
};

node::node(int v, node* p, node* n)
{
	value = v;
	prev = p;
	next = n;
}

node::~node()
{
	
}

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	
	void forward();
	void back();
	
	int get();
	
	void insert(int value);
	void remove();
	
	friend ostream& operator<<(ostream& out, const LinkedList& src);
	
private:
	node* head;
	node* cursor;	
};

LinkedList::LinkedList()
{
	head = NULL;
	cursor = NULL;
}

LinkedList::~LinkedList()
{
	cursor = head;
	while(cursor->next)
	{
		remove();
	}
	delete cursor;
	cursor = head = NULL;
}

void LinkedList::forward()
{
	if(cursor && cursor->next)
	{
		cursor = cursor->next;
	}
}

void LinkedList::back()
{
	if(cursor && cursor->prev)
	{
		cursor = cursor->prev;
	}
}

int LinkedList::get()
{
	if(cursor)
	{
		return cursor->value;
	}
	return 0;
}

void LinkedList::insert(int value)
{
	if(cursor)
	{
		node* newNode = new node(value,cursor,cursor->next);
		cursor->next = newNode;
		if(newNode->next)
		{
			newNode->next->prev = newNode;	
		}
	}
	else
	{
		cursor = new node(value);
		head = cursor;
	}
}

void LinkedList::remove()
{
	if(cursor && cursor->next)
	{
		node* temp1 = cursor->next->next;
		node* temp2 = cursor->next;
		
		cursor->next = temp1;
		if(temp1)
		{
			temp1->prev = cursor;
		}

		delete temp2;
	}
}

ostream& operator<<(ostream& out, const LinkedList& src)
{
	node* temp = src.head;
	while(temp)
	{
		int value = temp->value;
		
		if(temp == src.cursor)
		{
			out << "[" << value << "]";	
		}
		else
		{
			out << value;
		}
		
		if(temp->next)
		{
			out << " -> ";
		}
		
		temp = temp->next;
	}
	
	return out;
}

int main()
{
	LinkedList list;
	
	cout << "list: " << list << endl;
	
	for(int index = 0; index < 10; index++)
	{
		list.insert(index);
		list.forward();
	}
	
	cout << "list: " << list << endl;
	
	list.back();
	list.back();
	
	cout << "list: " << list << endl;
	
	list.remove();
	
	cout << "list: " << list << endl;
	
	list.forward(); 
	list.back();
	list.back();
	list.back();
	list.back();
	list.back();
	
	cout << "list: " << list << endl;
	
	return 0;
}























