#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float breath;

public:
    Rectangle();      // constructor
    Rectangle(float length, float breath);
    Rectangle(float value);

    float area(float length ,float breath);       //Functions
    void Display();
    int sameArea(Rectangle r);

    ~ Rectangle()
    {
        cout<<"Destructor called "<<endl;
    }

    void setlength(float length)     // setter
    {
        this->length = length;
    }
    void setbreath(float breath)
    {
        this->breath = breath;
    }
    float getlength()              // getter
    {
        return this->length;
    }
    float getbreath()
    {
        return this->breath;
    }
};

Rectangle::Rectangle()              //constructor
{
    this->length = 0;
    this->breath = 0;
}
Rectangle::Rectangle(float length, float breath)
{
    this->setlength(length);
    this->setbreath(breath);
}
Rectangle::Rectangle(float value)
{
    this->setlength(value);
    this->setbreath(value);
}

float Rectangle :: area (float length , float breath)     //Functions
{
    return this->length*breath;

}

void Rectangle :: Display ()
{
    cout<<"Length of Rectangle :"<<getlength()<<endl;
    cout<<"Breath of Rectangle :"<<getbreath()<<endl;
    cout<<"Area :"<<area(length,breath)<<endl;

}

int Rectangle :: sameArea(Rectangle r)
{
    if (r.area(length,breath) == area(length,breath))
    {
        return 1;
    }else
    {
        return 0;
    }

}

int main()
{
    Rectangle r1,r2;
    bool found=true;
    int result;
    r1.setlength(5.0);
    r1.setbreath(2.5);
    r2.setlength(5.0);
    r2.setbreath(18.9);

    r1.sameArea(r2);      //check same area

    cout<<"First Rectangle"<<endl;
    r1.Display();
    cout<<"Second Rectangle"<<endl;
    r2.Display();

    if (found == result)
    {
        cout<<"Have same Area"<<endl;
    }else
    {
        cout<<"Not Have same Area"<<endl;
    }

}
