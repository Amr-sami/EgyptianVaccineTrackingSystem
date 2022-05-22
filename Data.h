#pragma once
#include"C:\Users\AMR SAMI\source\repos\egyptianVaccineTrackingSystem_v\egyptianVaccineTrackingSystem_v\linkedList.h"
#include"user.h"
class Data
{
public:
	int nOfUsers = 0;
	int nOfEgyptians = 0;
	int nOfforigners = 0;
	int nOfDose1 = 0;
	int nOfFVaccined = 0;
	int nOfMen = 0;
	int nOfWomen = 0;
	int nOfWaitingList = 0;
	int nOfcairo = 0, nOfalex = 0, nOfmansora = 0, nOfsinai = 0;
	LinkedList users;
	queue<user> waitingList;
public:
	void add_to_waitingList(LinkedList& User);                    //// function to add user that vaccine status on waiting to waiting list 
	void displayStatistics(LinkedList& User);                    //// function to display statisics 
	void caLc_Statistics(LinkedList& linkedList);               //// function that we call it inside "display statistics" to calculate statistics 
	void updateInformation(LinkedList& linkedList, int index); ///// function to update user infromation

};
