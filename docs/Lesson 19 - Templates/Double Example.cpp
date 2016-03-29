
#include <iostream>

using namespace std;

template <typename T> class LinkedList;

template <typename T>
class node
{
public:
	node(T v, node* p = NULL, node* n = NULL)
	{
		value = v;
		prev = p;
		next = n;
	}
	~node() {};

	T value;
	node* next;
	node* prev;

	friend class LinkedList<T>;

	template <typename U> friend ostream& operator<<(ostream& out, const LinkedList<U>& src);
};

template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		head = NULL;
		cursor = NULL;
	}
	LinkedList(const LinkedList& src)
	{
		head = NULL;
		cursor = NULL;
		node<T>* temp = src.head;
		while(temp)
		{
			insert(temp->value);
			temp = temp->next;
		}
	}
	LinkedList& operator=(const LinkedList& src)
	{
		cursor = head;
		while(cursor && cursor->next)
		{
			remove();
		}
		delete cursor;
		cursor = head = NULL;
		node<T>* temp = src.head;
		while(temp)
		{
			insert(temp->value);
			temp = temp->next;
		}
		return *this;
	}
	~LinkedList()
	{
		cursor = head;
		while(cursor->next)
		{
			remove();
		}
		delete cursor;
		cursor = head = NULL;
	}
	
	void forward()
	{
		if(cursor && cursor->next)
		{
			cursor = cursor->next;
		}
	}
	void back()
	{
		if(cursor && cursor->prev)
		{
			cursor = cursor->prev;
		}
	}
	
	T get()
	{
		if(cursor)
		{
			return cursor->value;
		}
		return 0;	
	}
	
	void insert(const T& value)
	{
		if(cursor)
		{
			node<T>* newNode = new node<T>(value,cursor,cursor->next);
			cursor->next = newNode;
			if(newNode->next)
			{
				newNode->next->prev = newNode;	
			}
		}
		else
		{
			cursor = new node<T>(value);
			head = cursor;
		}
	}
	void remove()
	{
		if(cursor && cursor->next)
		{
			node<T>* temp1 = cursor->next->next;
			node<T>* temp2 = cursor->next;
			
			cursor->next = temp1;
			if(temp1)
			{
				temp1->prev = cursor;
			}

			delete temp2;
		}
	}
	
	template <typename U> friend ostream& operator<<(ostream& out, const LinkedList<U>& src);
	
private:
	node<T>* head;
	node<T>* cursor;	
};

template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& src)
{
	node<T>* temp = src.head;
	while(temp)
	{
		T value = temp->value;
		
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
	LinkedList<LinkedList<int> > list;
	
	cout << "list: " << list << endl;
	
	for(int index = 0; index < 10; index++)
	{
		LinkedList<int> val;
		for(int x = 0; x < 10; x++)
		{
			val.insert(x);
		}
		list.insert(val);
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























