#pragma once
#pragma once
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\user.h"


//template <class T>
class Node
{
public:
	Node* next;
	user value;
	Node();
	Node(user val);
};

//template <class T>
class LinkedList
{
	int count;
	Node* head;
	Node* tail;
public:
	LinkedList();
	int Length();
	user At(int);
	void InsertAt(int, user);
	void Append(user);
	void DeleteAt(int);
	bool find(string nationalId);

	~LinkedList(void);
};

