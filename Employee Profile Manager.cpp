#include <iostream>
#include <string>
using namespace std;
#define Max 5
struct Name
{
    string firstName;
    string lastName;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Address
{
    string street;
    string city;
    string state;
    string zipcode;
};

struct History
{
    Date HireDate;
    string JobTitle;
    string Dept;
};

struct Employee
{
    int Id;
    Name fulName;
    Date dob;
    Address Add;
    History H1;
    string skill[5];
    float salary;

    void Display() // Displaying Function
    {
        
        cout << "ID :" << Id << endl;
        cout << "First Name :" << fulName.firstName << endl;
        cout << "Last Name :" << fulName.lastName << endl;
        cout << "Date of Birth :" << dob.day << "-" << dob.month << "-" << dob.year << endl
             << endl;
        cout << "Address " << endl;
        cout << "Street " << Add.street << " City " << Add.city << " State " << Add.state << " Zipcode " << Add.zipcode << endl
             << endl;
        cout << "History of Employee :" << endl;
        cout << "Hire Date :" << H1.HireDate.day << "-" << H1.HireDate.month << "-" << H1.HireDate.year << endl;
        cout << "Job Title :" << H1.JobTitle << endl;
        cout << "Department :" << H1.Dept << endl;
        cout << "Skills " << endl;

        for (int i = 0; i < 5; i++)
        {
            cout << " " << i + 1 << " " << skill[i] << endl;
        }
        cout << "Your Salary :" << salary << endl;
    }

    void SearchEmpolyee(Employee e[], int search) // Searching Employee
    {
        bool found = false;
        for (int i = 0; i < Max; i++)
        {

            if (search == e[i].Id)
            {
                e[i].Display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not record found" << endl;
        }
    }

    void EmployeeInfo(Employee E[], int i)
    {

        cout << "Enter the Employee ID :"; // Employee Info
        cin >> E[i].Id;
        cout << "Enter the First Name :";
        cin >> E[i].fulName.firstName;
        cout << "Enter the last Name :";
        cin >> E[i].fulName.lastName;
    }

    void DOB(Employee E[], int i)
    {
        cout << "Enter Date of Birth " << endl; // Date of Birth
        cout << "Date ";
        cin >> E[i].dob.day;
        cout << "Month ";
        cin >> E[i].dob.month;
        cout << "Year ";
        cin >> E[i].dob.year;
    }

    void Address(Employee E[], int i)
    {

        cout << "Enter your Complete Address" << endl; // Address info
        cout << "Street :";
        cin >> E[i].Add.street;
        cout << "City :";
        cin >> E[i].Add.city;
        cout << "State :";
        cin >> E[i].Add.state;
        cout << "ZipCode :";
        cin >> E[i].Add.zipcode;
    }

    void EmployeeHistory(Employee E[], int i)
    {

        cout << "Enter your Previous History " << endl; // Previous History
        cout << "Date of Joining : ";
        cout << "Date :";
        cin >> E[i].H1.HireDate.day;
        cout << "Month :";
        cin >> E[i].H1.HireDate.month;
        cout << "Year :";
        cin >> E[i].H1.HireDate.year;

        cout << "Enter your Job Tile :";
        cin >> E[i].H1.JobTitle;
        cout << "Enter your Department:";
        cin >> E[i].H1.Dept;

        for (int j = 0; j < 5; j++) // Empolyee Skills
        {
            cout << "Enter your " << j + 1 << " Skill ";
            cin >> E[i].skill[j];
        }

        cout << "Enter your Salary :";
        cin >> E[i].salary;
    }
};

int main()
{
    int search;
    Employee E[Max];

    for (int i = 0; i < Max; i++)
    {
        E[i].EmployeeInfo(E, i);    // Employee info
        E[i].DOB(E, i);             // Date of Birth Fucnction Call
        E[i].Address(E, i);         // Address Function call
        E[i].EmployeeHistory(E, i); // Employee History or Job info
    }

    cout << "Enter the Empolyee Id you want to search :";
    cin >> search;
    E->SearchEmpolyee(E, search);
}