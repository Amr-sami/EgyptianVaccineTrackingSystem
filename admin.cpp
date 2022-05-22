#include "admin.h"

void admin::viewRecords(string nId, LinkedList u)
{

	for (int i = 0; i < u.Length(); i++)
	{
		if (nId == u.At(i).nationalId)
		{
			cout << "Name : " << u.At(i).fullName << endl;
			cout << "Country: " << u.At(i).country << endl;
			cout << "Governorate : " << u.At(i).governorate << endl;
			cout << "age: " << u.At(i).age << endl;
			cout << "gender : " << u.At(i).gender << endl;
			if (u.At(i).fullyVaccined)
			{
				cout << "Fully Vaccined !" << endl;
			}
			else if (u.At(i).isVaccined)
			{
				cout << "DOSE 1 already Taken ! " << endl;
			}
			else
				cout << "On Waiting list !" << endl;
			break;

		}
	}

}

void admin::deleteRecords(string id, LinkedList u)
{
	bool x = true;
	for (int i = 0; i < u.Length(); i++) {
		if (id == u.At(i).nationalId)
		{
			u.DeleteAt(i);
			cout << "user deleted" << endl;
			x = false;
			break;
		}
	}
	if (x) {
		cout << "USER NOT FOUND !" << endl;
	}





}
