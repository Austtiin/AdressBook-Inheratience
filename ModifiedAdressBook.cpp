/*

Author: Austin Stephens

Date: 04/30/2022

FileName: ModifiedAdressBook.cpp

Purpous: Module 04 Assigment, Inheratience

Input: Menu Selection Based on Input

Output: Either menu item or concepts of entering in adress information
Exceptiuons: 
 
    
    Rules:

Modify the Vector address book program you created in the previous module by incorporating the following:

Modify the Employer class to serve as a base class.
Create child classes from the Employer class for three types of employers:

Creating a Person Class, an Employer Class and a Personal Info Class. 
Use the Employer and PersonalInfo classes as member variables of a Person class. 
Modify the Vector class to hold People objects instead of Record objects. 
Modify the menu interface and input algorithms to accept data for the Employer and Personal Info classes via functions in the Person class


Sales,
Service, and
Manufacturing.



Modify the program to use each child class based on a choice of employer type during data input.
Ensure that the program will output properly when all three types of child classes are active after input.


*/


//Including librarys
#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <vector>
#include "ClassEmployer.h"






using namespace std;

class Person: public Employer
{
private:
    char *FirstName,*LastName, *Employer;
    long *PhoneNumber;
    int *Age, *RecordNumber;
public:
    Person()
    {
        Employer = new char[20];
        FirstName = new char[20];
        LastName = new char[20];
        PhoneNumber = new long;
        Age = new int;
        RecordNumber = new int;
    }   

        void datafeed();
        void ShowRecords();
        void e1s();
        void e2s();
        void e3s();
};


//----------------------------------------------------

//-----------------------------------------------
void printLines()
{
    cout << "-------------------------" << endl;
}

void Person::e1s()
{
    Employer1[e1.size() + 1];
 
    std::copy(e1.begin(), e1.end(), Employer1);
    Employer1[e1.size()] = '\0';
}

void Person::e2s()
{
    Employer2[e2.size() + 1];
 
    std::copy(e2.begin(), e2.end(), Employer2);
    Employer2[e2.size()] = '\0';
}

void Person::e3s()
{
    Employer3[e3.size() + 1];
 
    std::copy(e3.begin(), e3.end(), Employer3);
    Employer3[e3.size()] = '\0';
}

void Person::datafeed()
{
    cin.ignore();
    cout << "Enter First Name: " << endl;
    cin.getline(FirstName, 20);
    cout << "Enter Last Name; " << endl;
    cin.getline(LastName, 20);
    cout << "Enter Age: " << endl;
    cin >> *Age;
    cout << "Enter Phone Number: " << endl;
    cin >> *PhoneNumber;
    cout << "Enter Record Number: " << endl;
    cin >> *RecordNumber;
    while (1)
    {
        int choice;
        cout << "Choose Employer: " << Employers << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            e1s();
            Employer = Employer1;
            break;
            
        case 2:
            e2s();
            Employer = Employer2;
            break;

        case 3:
            e3s();
            Employer = Employer3;
            break;
        default:
            break;
        }
    break;
    }
    
}



void Person::ShowRecords()
{
        printLines();
        cout << "   First Name: " << FirstName<< endl;
        cout << "    Last Name: " << LastName << endl;
        cout << "          Age: " << *Age << endl;
        cout << " Phone Number: " << *PhoneNumber << endl;
        cout << "Record-Number: " << *RecordNumber << endl;
        cout << "     Employer: " << Employer << endl;
        printLines();
}




//main------------------------------------------
int main()
{
    Person *P[30];
    int Choice, i=0, j=0;
    array<string , 1> line;
   
    //vector
    vector<int> numbers;
    line[1] = {"-------------------------"};


    //Vector added
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    


    while (1)
    {
        printLines();
        //vector implemented
        cout << numbers[0] << ". Input information into an record" << endl;
        cout << numbers[1] << ". Display all information in all records" << endl;
        cout << numbers[2] << ". Exit the program" << endl;
        printLines();
        cin >> Choice;


        switch (Choice)
        {
            //new record creation
        case 1:
            P[i] = new Person;
            P[i]-> datafeed();
            i++;
            break;

        case 2:
            //loop to repeat functions, wont show if no records have been created
            cin.ignore();
            for (int j = 0; j < i; j++)
            {
                P[j]->ShowRecords();
            }
            break;

            
            
            //exit
        case 3:
            exit(0);
        default:

        //exception handling **ADDED
            try
            {
                if (Choice != '1' || '2' || '3')
                {
                    throw 99;
                }
                
            }
            catch(int x)
            {
                cout << "\n Invalid Choice Entered: ERROR: " << x << endl;
                cout << line[1] << endl;
            }
            
        }
    }
    

    return 0;

}