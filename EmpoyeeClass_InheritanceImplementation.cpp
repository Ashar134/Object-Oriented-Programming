#include <iostream>
using namespace std;

class Employee
{
private:
    string empName;
    int empNumber;

public:
    Employee(string empName, int empNumber)
    {
        this->empName = empName;
        this->empNumber = empNumber;
    }

    void putData()
    {
        cout << "Enter employee Name :";
        cin >> empName;
        cout << "Enter employee Number :";
        cin >> empNumber;
    }

    void getData()
    {
        cout << "Employee Name :" << empName << endl;
        cout << "Employee Number :" << empNumber << endl;
    }
};

class Scientist : public Employee // Scientist Class inherit Employee Class
{
private:
    int publication;

public:
    Scientist(string empName, int empNumber, int publication) : Employee(empName, empNumber) // Constructor
    {
        this->publication = publication;
    }

    void putData()      //override 
    { 
        Employee::putData();   
        cout << "Enter the Publication :";
        cin >> publication;
    }
    void getData() //override of Employee Class
    {
        Employee::getData();
        cout << "Publication: " << publication << endl;
    }
};
class Manager : public Employee // Manager Class
{
private:
    char title;
    double club_due;

public:
    Manager(string empName, int empNumber, char title, double club_due) : Employee(empName, empNumber) // Constructor
    {
        this->title = title;
        this->club_due = club_due;
    }

    void putData()   //override method of Employee Class
    {
        Employee::putData();   
        cout << "Enter your title :";
        cin >> title;
        cout << "Enter the Club Dues :";
        cin >> club_due;
    }

    void getData()     //override method of Employee Class
    {
        Employee ::getData();    
        cout << "Title :" << title << endl;
        cout << "Club Dues :" << club_due << endl;
    }
};

class Programmer : public Employee // Porgrammer Class
{
private:
    double salary;
    string expertise;

public:
    Programmer(string empName, int empNumber, double salary, string expertise) : Employee(empName, empNumber) // Constructor
    {
        this->salary = salary;
        this->expertise = expertise;
    }

    void putData()
    {
        Employee ::putData();
        cout << "Enter your Salary :";
        cin >> salary;
        cout << "Enter your Expertise :";
        cin >> expertise;
    }

    void getData()
    {
        Employee ::getData();
        cout << "Salary :" << salary << endl;
        cout << "Expertise :" << expertise << endl;
    }
};

int main()
{
    Scientist s("Ali", 033156765, 5);     //Object of Scientist class
    s.getData();

    Manager m("Ahmed", 031456765, 'M', 4566.78); //Object of Manager class
    m.getData();

    Programmer p("N/A", 0, 0.00, "N/A");    //Assigning default value to Programmer constructor
    p.putData();                            //set data by putData Function
    p.getData();
}