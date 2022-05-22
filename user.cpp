#pragma once
#include "user.h"
#include"Data.h"
#include"admin.h"
#include "Linkedlist.h"

void user::addInformation()
{

    int i;
    cout << "Enter Full Name     : ";    cin.getline(fullName, MAX_LEN);
    cout << "Enter password      : ";    cin.getline(password, MAX_LEN);

    //////////////////////////////////////////  entering country ////////////////////////////////////////////
    cout << "Enter Country       : ";    cin.getline(country, MAX_LEN);
    string egy;
    egy = country;
    if (egy == "egypt" || egy == "Egypt") {
        do {
            cout << "press 1 : if you live in egypt " << endl << "press 2 : if you live abroad " << endl;
            cin >> i;
            if (i == 1) {
                lives_in_egypt = true;
                break;
            }
            if (i == 2) {
                lives_in_egypt = false;
                break;
            }


        } while (i < 1 || i > 2);
        cin.ignore();
        // maktob fe el describtion the user can only write egyptian governorates
        cout << "Enter governorate   : ";    cin.getline(governorate, MAX_LEN);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////// entering gender /////////////////////////////////////////
    do
    {
        cout << "Enter gender (M |F) : ";   cin >> gender;

    } while (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F');

    ////////////////////////////////////////////////////////////////////////////////////////////////    


    cout << "Enter age           : ";          cin >> age;
    cin.ignore();
    do {
        cout << "Enter National ID    : ";        cin >> nationalId;
        if (nationalId.length() != 13) {
            cout << "National id should be 13 number " << endl;
        }
    } while (nationalId.length() != 13);
    cout << endl;
    cout << endl;


    system("cls");
    cout << "--------------------------------------------------------------- " << endl;
    cout << "is vaccined Dose 1 ?  select 1  " << endl;;
    cout << "is Fully Vaccined ?   seelct 2  " << endl;
    cout << "not vaccined yet      select 3  " << endl;
    int ch;
    do {
        cin >> ch;
        switch (ch)
        {
        case 1:
            isVaccined = true;
            fullyVaccined = false;
            onWaiting = false;
            break;
        case 2:
            fullyVaccined = true;
            isVaccined = false;
            onWaiting = false;
            break;
        case 3:
            onWaiting = true;
            isVaccined = false;
            fullyVaccined = false;
            break;
        default:
            cout << "Enter valid Number !! " << endl;
        }
    } while (ch > 3 || ch < 1);

}
bool user::isEgyptian()
{
    string s;
    s = country;
    if (s == "egypt" || s == "Egypt" && lives_in_egypt == true) {
        return true;
    }
    else
        return false;
}
void user::displayRecords() {
    cout << "Name        : " << fullName << endl;
    cout << "password    : " << password << endl;
    cout << "National ID : " << nationalId << endl;
    cout << "Country     : " << country << endl;
    if (isEgyptian()) {
        cout << "Governorate : " << governorate << endl;
    }
    cout << "age         : " << age << endl;
    cout << "gender      : " << gender << endl;

    if (fullyVaccined)
    {
        cout << "Fully Vaccined !" << endl;
    }
    else if (isVaccined)
    {
        cout << "DOSE 1 already Taken ! " << endl;
    }
    else
        cout << "On Waiting list !" << endl;
}