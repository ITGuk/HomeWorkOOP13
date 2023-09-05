#include <iostream>

using namespace std;

class List
{
public:
	List();
	~List();
	void Add_to_begin(int data);
	void Add_to_end(int data);
	void matching_check(int data);
	void Swap();
	void Display();

private:
	class Node
	{
	public:
		Node* pNext;
		Node* prev;
		int data;
		Node(int data = NULL, Node* pNext = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->prev = prev;
		}
};
	int Size;
	Node* head = new Node();
};

List::List()//initializations.
{
	Size = 0;
	head = nullptr;
}

List::~List()//Destructor.
{
	Node* temp = head;
	while (head != nullptr)
	{
		head = head->pNext;
		delete temp;
		Size--;
	}
}

void List::Add_to_end(int data)//Add element to beck.
{
	if (head == nullptr)
	{
		return Add_to_begin(data);
	}
	else
	{
		Node* lst = this->head;
		while (lst->pNext != nullptr)
		{
			lst = lst->pNext;
		}
		lst->pNext = new Node(data);
	}
	Size++;
}

void List::Add_to_begin(int data)//Add element to begin.
{
	head = new Node(data, head);
	Size++;
}

void List::Display()//Show all elements.
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->pNext;
	}
	cout << endl;
}

void List::Swap()//Swap elements.
{
	Node* a = head->pNext;
	Node* b = a->pNext;
	head->pNext = b;
	a->pNext = b->pNext;
	b->pNext = a;
}

void List::matching_check(int data)//Check matching.
{
	int temp = data;
	while (head->pNext != nullptr)
	{
		if (temp == head->data)
		{
			cout << "Num is in the list." << endl;
		}
		head = head->pNext;
	}
}

int main()
{
	List list;
	list.Add_to_end(6);
	list.Add_to_end(9);
	list.Add_to_end(12);
	list.Add_to_begin(3);
	list.Display();
	list.Swap();
	cout << "After swap: " << endl;
	list.Display();
	list.matching_check(9);
	list.~List();
}
