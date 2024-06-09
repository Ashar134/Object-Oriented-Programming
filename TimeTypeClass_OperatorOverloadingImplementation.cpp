#include <iostream>
using namespace std;

class timeType
{
private:
    int hour;
    int min;
    int sec;

public:
    timeType() : hour(0), min(0), sec(0) {} // Default constructor

    timeType(int hour, int min, int sec) // Parameterize constructor
    {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    void Display() // Display
    {
        cout << " " << hour << " : " << min << " : " << sec << endl;
    }

    timeType operator+(timeType &obj) // + operator
    {
        timeType temp;

        temp.hour = hour + obj.hour;
        temp.min = min + obj.min;
        temp.sec = sec + obj.sec;

        return temp;
    }

    timeType operator++() // Prefix Operator
    {
        timeType temp;
        temp.hour = ++hour;
        temp.min = ++min;
        temp.sec = ++sec;

        return temp;
    }

    timeType operator++(int) // Postfix Operator
    {
        timeType temp;
        temp.hour = hour++;
        temp.min = min++;
        temp.sec = sec++;

        return temp;
    }

    timeType addingTime(timeType &t1, timeType &t2); // Adding the Object of the Class
};

timeType timeType::addingTime(timeType &t1, timeType &t2)
{
    timeType obj, t3;
    int result = 0;

    t3 = t1 + t2;
    obj.sec = t3.sec % 60;
    result = t3.sec / 60;

    obj.min = (t3.min + result) % 60;
    result = (t3.min + result) / 60;

    obj.hour = t3.hour + result;

    return obj;
}
int main()
{

    timeType t1, t2, t3;

    t1 = {1, 20, 40};
    t2 = {2, 50, 40};

    cout<<"T1 Value"<<endl;
    t1.Display(); 
    cout<<"T2 Value"<<endl;            
    t2.Display();                      
    t3 = t3.addingTime(t1, t2);
    t3.Display();                // Displaying the time after addding the t1 and t2

    ++t1;                       // incrementing the value  (Prefix)
    ++t2;
    cout << "Time value After Prefix Operator" << endl;
    t1.Display();
    t2.Display();
    t3 = t3.addingTime(t1, t2); // Adding them
    cout<<"New value"<<endl;
    t3.Display();

    t1++;                      // Postfix
    t2++;
    cout << "Time value After Postfix Operator" << endl;
    t1.Display();
    t2.Display();
    t3 = t3.addingTime(t1, t2);
    cout<<"New value"<<endl;
    t3.Display();

    return 0;
}
