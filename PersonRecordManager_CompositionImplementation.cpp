#include <iostream>
using namespace std;

struct Name
{
    string firstName = "N/A";
    string lastName = "N/A";
};

class Date // Date Class
{
private:
    int day;
    int month;
    int year;

public:
    Date(int days = 1, int months = 1, int years = 2022)
    {

        if (months < 1 || months > 12)
        {
            this->month = 1;
        }
        else
        {
            this->month = months;
        }

        if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
        {
            if (days < 1 || days > 31)
            {
                this->day = 1;
            }
            else
            {
                this->day = days;
            }
        }
        else
        {
            if (days < 1 || days > 30)
            {
                this->day = 1;
            }
            else
            {
                this->day = days;
            }
        }

        if (years < 1900 || years > 2022)
        {
            this->year = 2022;
        }
        else
        {
            this->year = years;
        }
    }

    void Print();
};

void Date ::Print() // Print Date Function
{
    cout << " " << day << "/" << month << "/" << year << endl;
}
class Person // Person Class
{
private:
    Name name;
    char gender;
    Date dateOfBirth;

public:
    Person(string firstName = "N/A", string lastName = "N/A", char gender = 'N', Date dob = Date() )
    {
        name.firstName = firstName;
        name.lastName = lastName;
        this->gender = gender;
        dateOfBirth = dob;
    }

    void printAllRecord() // Print All Record
    {
        cout << "First Name: " << name.firstName << endl;
        cout << "Last Name: " << name.lastName << endl;
        cout << "Gender: " << gender << endl;
        cout << "Date of Birth: ";
        dateOfBirth.Print();
    }
};

int main()
{
    Date dob1(5, 12, 2015);
    Person p1("Ali", "Khan", 'M', dob1);
    p1.printAllRecord();

    Date dob2(-1, 24, 1899);
    Person p2("Ahmed", "Khan", 'M', dob2);
    p2.printAllRecord();

    return 0;
}
