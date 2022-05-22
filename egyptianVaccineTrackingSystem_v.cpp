// ConsoleApplication10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include<string>
#include<conio.h>
#include"stdlib.h"
#include<list>
#include<fstream>
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\Data.h"
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\admin.h"
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\linkedList.h"
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\user.h"
#define MAX_LEN  60
#define gender_size 1


///////////////////////////////// function‘s difinitions  //////////////////////////////////
void displayScreen(LinkedList  &linkedList, user& User, Data& systemData, admin& Admin);          ////// function to display start menu  
void login(LinkedList& linkedList, user& User, Data& systemData, admin& Admin);                  ////// function to login 
void backToStart();                                                                             ////// function to back to start menu
void userFunctions();																           ////// function has user function inside
void choose();																	              ////// function to back to last  menu or main menu
void addInFile(LinkedList& linkedList);					 						             ////// function to add user infromation from linked list to file
void addInProgram(LinkedList& linkedList);											        ////// function to add from file to console when we run our programm
void addForStat(LinkedList& linkedList);												   ////// function to calc statistics when we work with windows form

///////////////////////////////// global variables ////////////////////////////////////
user User;
LinkedList linkedList;
Data systemData;
admin Admin;
int logged_in_user = 0;                                                                 ///// the linked list index of the user who is login so we don't go back to work with for loop


using namespace std;
int main()
{
	addInProgram(linkedList);                                                       ///// to recall users from our file that we already saved it
	displayScreen(linkedList, User, systemData, Admin);
}

void displayScreen(LinkedList& linkedList, user& User, Data& systemData, admin& Admin) 
{

	int i;
	char choice[1];

	do {
		cout << "--------------------- Welcome To Vaccine Tracking System ---------------------" << endl;
		cout << "1- signup             " << endl;
		cout << "2- login              " << endl;
		cout << "3- exit               " << endl;
		cout << "4- display statistics " << endl;
		cin >> choice;
		system("cls");
		i = atoi(choice);
		if (i == 1)
		{
			////////////////////////////////////////// sign up /////////////////////////////////////////
			cin.ignore();
			User.addInformation();
			//check if the id is unique
			if (!linkedList.find(User.nationalId)) {
				linkedList.Append(User);
				cout << endl << "Thank you for signing up ^-^" << endl << endl;
				system("pause");
				backToStart();
			}
			else if (linkedList.find(User.nationalId)) {
				cout << "National id is used !" << endl;
				cout << "please sign up again " << endl;
				system("pause");
				backToStart();
			}

		}

		if (i == 2)
			/////////////////////////////////////// login ////////////////////////////////////////
			login(linkedList, User, systemData, Admin);
		if (i == 3) {
			addInFile(linkedList);
			addForStat(linkedList);
			/////////////////////////////////////// exit ////////////////////////////////////////
			exit(0);
		}
		if (i == 4)
		{
			//////////////////////////////// display statistics ///////////////////////////////
			systemData.displayStatistics(linkedList);
			cout << endl << endl;
			system("pause");
			backToStart();
		}

	} while (i > 4 || i < 1);
}

void login(LinkedList& linkedList, user& User, Data& systemData, admin& Admin)
{
	int choiceLogin = 0;
	int choiceInLogin = 0;
	string adminName;
	string adminPassword;
	string nationalId;
	string userPassword;
	do {
		cout << "1 - login as admin " << endl;
		cout << "2-  login as user  " << endl;
		cin >> choiceLogin;
		system("cls");
		switch (choiceLogin)
		{
			///////////////////////////////////////   login as an admin   //////////////////////////////////////////////////////
		case 1:
			cout << "Enter admin name     : "; cin >> adminName;
			cout << "Enter admin password : "; cin >> adminPassword;
			system("cls");
			if (adminName == "admin" && adminPassword == "admin")
			{
				do {
					cout << "1-View Records by ID    " << endl;
					cout << "2-Delete Records by ID  " << endl;
					string id;
					cin >> choiceInLogin;
					system("cls");
					switch (choiceInLogin)
					{
					case 1:
						//////////////// admin : view records ////////////////
						cout << "Please Enter ID : "; cin >> id;
						Admin.viewRecords(id, linkedList);
						cout << "To delete this user press 1, to back to start menu press any other number" << endl;
						char choice;
						cin >> choice;
						if (choice == '1')
							Admin.deleteRecords(id, linkedList);
						else
							backToStart();
						break;
					case 2:
						//////////////// admin : delete records ////////////////
						cout << "Please Enter ID : "; cin >> id;
						Admin.deleteRecords(id, linkedList);
						break;
					default:
						cout << "Enter Valid Value : " << endl;
					}
					break;
				} while (choiceInLogin > 2 || choiceInLogin < 1);
				system("pause");
				backToStart();
				break;
			}
			//////////////////////////////////////// login as an user /////////////////////////////////////////
		case 2:
			cout << "Enter national id     : "; cin >> nationalId;
			cout << "Enter password        : "; cin >> userPassword;
			bool x = true;
			for (int i = 0; i < linkedList.Length(); i++)
			{

				if (nationalId == linkedList.At(i).nationalId && userPassword == linkedList.At(i).password)
				{

					logged_in_user = i;                    //global variable to save the index of the logged in user
					userFunctions();
					break;
					x = false;
				}
			}
			if (x)
			{
				cout << "USER NOT FOUND !" << endl;
				system("pause");
				backToStart();
			}
			break;
		}
		break;
	} while (choiceLogin > 2 || choiceLogin < 1);

}

void backToStart() {

	system("cls");
	displayScreen(linkedList, User, systemData, Admin);
}

void userFunctions() {
	int ch;
	do {
		system("cls");
		cout << "1 - view my records        " << endl;
		cout << "2 - update my informations " << endl;
		cout << "3 - delte my records       " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			//////////////// user : view records ///////////////////
			linkedList.At(logged_in_user).displayRecords();
			break;
		case 2:
			//////////////// user : update informations ////////////
			systemData.updateInformation(linkedList, logged_in_user);
			choose();
			break;
		case 3: {
			//////////////// user : delete records ////////////

			linkedList.DeleteAt(logged_in_user);
			system("pause");
			backToStart();
			break;
		}
		default:
			cout << "Enter Valid Value " << endl;
			break;
		}
		break;
	} while (ch > 1 || ch < 3);
	choose();
}

void choose() {
	cout << "To back to the last menu press 1\n" << "To back to start menu press 2" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
		userFunctions();
	if (choice == 2)
		backToStart();
	else
		backToStart();
}

void addInFile(LinkedList& linkedList) {
	ofstream tofile;
	tofile.open("list");
	if (tofile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	tofile << linkedList.Length() << endl;
	for (int i = 0; i < linkedList.Length(); i++)
	{
		tofile << linkedList.At(i).fullName << endl << linkedList.At(i).password << endl << linkedList.At(i).country << endl << linkedList.At(i).governorate << endl;
		tofile << linkedList.At(i).age << endl << linkedList.At(i).nationalId << endl << linkedList.At(i).fullyVaccined << endl << linkedList.At(i).isVaccined << endl;
		tofile << linkedList.At(i).onWaiting << endl << linkedList.At(i).gender << endl << linkedList.At(i).lives_in_egypt << endl;

	}
	tofile.close();
	cout << "success" << endl;
}

void addInProgram(LinkedList& linkedList) {
	ifstream fromfile;
	fromfile.open("list");
	if (fromfile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	int numuser = 0, i = 0;
	fromfile >> numuser;
	fromfile.ignore();

	while (i < numuser)
	{
		i++;
		user u1;
		fromfile.getline(u1.fullName, MAX_LEN);
		fromfile.getline(u1.password, MAX_LEN);
		fromfile.getline(u1.country, MAX_LEN);
		fromfile.getline(u1.governorate, MAX_LEN);
		fromfile >> u1.age;
		fromfile.ignore();

		fromfile >> u1.nationalId;
		fromfile.ignore();
		fromfile >> u1.fullyVaccined;
		fromfile.ignore();
		fromfile >> u1.isVaccined;
		fromfile.ignore();

		fromfile >> u1.onWaiting;
		fromfile.ignore();

		fromfile >> u1.gender;
		fromfile.ignore();

		fromfile >> u1.lives_in_egypt;
		fromfile.ignore();
		linkedList.Append(u1);

	}
	fromfile.close();
}

void addForStat(LinkedList& linkedList) {
	ofstream tofile;
	tofile.open("stat.txt");
	if (tofile.fail())
	{
		cerr << "failed in openning file" << endl;
		exit(1);
	}
	systemData.caLc_Statistics(linkedList);

	tofile <<  systemData.nOfWaitingList << endl;
	tofile <<  systemData.nOfDose1 << endl;
	tofile << systemData.nOfFVaccined << endl;

	tofile << systemData.nOfMen << endl;
	tofile << systemData.nOfWomen << endl;
	tofile << systemData.nOfEgyptians << endl;
	tofile << systemData.nOfforigners << endl;

	tofile << systemData.nOfcairo << endl;
	tofile << systemData.nOfalex << endl;
	tofile << systemData.nOfmansora << endl;
	tofile << systemData.nOfsinai << endl;

	tofile.close();


}