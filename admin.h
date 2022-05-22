#pragma once
#include<iostream>
#include"user.h"
#include"Data.h"
using namespace std;
class admin
{

public:
	void viewRecords(string nId, LinkedList User);             /// function to view user record by id 
	void deleteRecords(string id, LinkedList User);           /// function  to delete user record by id

};

