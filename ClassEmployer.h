#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class EmployerOne
{   
    public:
        char *Employer1;
        string e1 = "Sales";
        
};

class EmployerTwo
{
    public:
        char *Employer2;
        string e2 = "Service";
};

class EmployerThree
{
    public:
        char *Employer3;
        string e3 = "Manufactuing";

};


class Employer: public EmployerOne, public EmployerTwo, public EmployerThree
{
    public:
        string Employers = "1. Sales | 2. Service | 3. Manufacturing";
};
