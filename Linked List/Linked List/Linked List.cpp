#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

class linkedlist
{
private:
	node *head, *tail;
public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	void insert_end(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void insert_start(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value)
	{
		node *pre = new node;
		node *cur = new node;
		node *temp = new node;
		cur = head;
		for (int i = 1; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data = value;
		pre->next = temp;
		temp->next = cur;
	}
	void delete_first()
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last()
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_position(int pos)
	{
		node *current = new node;
		node *previous = new node;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
};
int main()
{
	linkedlist myLinkedList;
	myLinkedList.insert_end(1);
	myLinkedList.insert_end(2);
	myLinkedList.insert_end(3);
	myLinkedList.insert_end(5);
	cout << "Linked linkedlist\n";
	myLinkedList.display();
	cout << "\n\nInsert at End\n";
	myLinkedList.insert_end(6);
	myLinkedList.display();
	cout << "\n\nInsert at Start\n";
	myLinkedList.insert_start(0);
	myLinkedList.display();
	cout << "\n\nInsert at Position\n";
	myLinkedList.insert_position(5, 4);
	myLinkedList.display();
	cout << "\n\nDelete at Start\n";
	myLinkedList.delete_first();
	myLinkedList.display();
	cout << "\n\nDelete at End\n";
	myLinkedList.delete_last();
	myLinkedList.display();
	cout << "\n\nDelete at Position\n";
	myLinkedList.delete_position(4);
	myLinkedList.display();
	cout << "\n\n";
	system("pause");
	return 0;
}