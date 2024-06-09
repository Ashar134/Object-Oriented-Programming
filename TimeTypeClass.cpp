#include <iostream>
using namespace std;

class timeType 
{
private:
    int hours;
    int min;
    int sec;

public:

    timeType();                           // Constructor
    timeType(int hours, int min, int sec);
    void Display();                      // Member function
    timeType addTime(timeType t1, timeType t2);

    void sethours(int hours) 
    {
        this->hours = hours;
    }
    void setmin(int min) 
    {
        this->min = min;
    }
    void setsec(int sec) 
    {
        this->sec = sec;
    }
    int gethours() 
    {
        return this->hours;
    }
    int getmin() 
    {
        return this->min;
    }
    int getsec() 
    {
        return this->sec;
    }
};

timeType::timeType() 
{
    this->hours = 0;
    this->min = 0;
    this->sec = 0;
}
timeType::timeType(int hours, int min, int sec)
{
    this->hours = hours;
    this->min = min;
    this->sec = sec;
}
void timeType::Display() 
{
    cout << " " << hours << ":" << min << ":" << sec << endl;
}

timeType timeType::addTime(timeType t1, timeType t2)
{
    timeType t3;
    int reuslt = 0;

    t3.sec = (t1.sec + t2.sec) % 60;
    reuslt = (t1.sec + t2.sec) / 60;

    t3.min = (t1.min + t2.min + reuslt) % 60;
    reuslt = (t1.min + t2.min + reuslt) / 60;

    t3.hours = t1.hours + t2.hours + reuslt;

    return t3;
}

int main() 
{
    // timeType t1(1,20,40);
    timeType t1, t2;
    t1.sethours(1);
    t1.setmin(20);
    t1.setsec(40);

    

    t2.sethours(2);
    t2.setmin(50);
    t2.setsec(40);

    cout << "Time 1:";
    t1.Display();

    cout << "Time 2:";
    t2.Display();

    timeType t3 = t3.addTime(t1, t2);
    cout << "Time 3 :";
    t3.Display();

    return 0;
}
