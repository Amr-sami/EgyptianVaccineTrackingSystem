#pragma once
#include<iostream>
#include<string>
#include<queue>
#include"stdlib.h"
#include<conio.h>
#include<vector>

#define MAX_LEN  60
#define gender_size 1
using namespace std;

class user
{
public:
	char fullName[MAX_LEN];
	char password[MAX_LEN];
	char country[MAX_LEN];
	bool lives_in_egypt = true;
	char governorate[MAX_LEN];
	char age[3];
	bool isVaccined = false;
	bool fullyVaccined = false;
	bool onWaiting = false;
	string nationalId;
	char gender;
public:
	void displayRecords();               ////// function to display user records
	void addInformation();              ////// function to signup
	bool isEgyptian();                 ////// boolean to check user is egyptian or not

};