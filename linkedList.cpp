#include "Linkedlist.h"
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\user.h"

#include <assert.h>

//template <class T>
Node::Node()
{
	value;
	next;
}

//template <class T>
Node::Node(user val)
{
	value = val;
	next = 0;
}

//template <class T>
LinkedList::LinkedList(void)
{
	head = tail = 0;
	count = 0;
}

//template <class T>
int LinkedList::Length()
{
	return count;
}

//template <class T>
void LinkedList::Append(user  val)
{
	Node* newNode = new Node(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

//template <class T>
user LinkedList::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

//template <class T>
void LinkedList::InsertAt(int pos, user val)
{
	assert(pos >= 0 && pos <= count);
	Node* tmp = head;
	Node* newNode = new Node(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

//template <class T>
void LinkedList::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = tmp;
	}
	count--;
}

bool LinkedList::find(string nationalId)
{
	int x = 0;

	for (int i = 0; i < Length(); i++) {
		if (nationalId == At(i).nationalId)
			x++;
	}
	if (x >= 1) {
		return true;
	}
	else
		return false;


}

//template <class T>
LinkedList::~LinkedList(void)
{
	while (count != 0)
		DeleteAt(0);
}

