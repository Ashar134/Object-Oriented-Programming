#include <iostream>
using namespace std;

class Engine
{
public:
    void start() // Methods
    {
        cout << "Engine Started" << endl;
    }

    void reverse()
    {
        cout << "Car is Reversing" << endl;
    }

    void stop()
    {
        cout << "Car Stop!" << endl;
    }
};

class Wheel
{
    static int count;

public:
    void inflate() //Method
    {

        cout << "Tyre " << count << " Pressure is Verified " << endl;
        count++;
    }
};
int Wheel ::count = 1;
class Window
{
public:
    void rollup()   //Method
    {
        cout << "Window rollup" << endl;
    }

    void rolldown()
    {
        cout << "Window rolldown" << endl;
    }
};

class Door
{
private:
    Window windowOne[4];

public:
    void open()   //Methods
    {
        cout << "Door Opened" << endl;
    }

    void close()
    {
        cout << "Door Closed" << endl;
    }

    Window *getwindow()
    {
        return windowOne;
    }
};

class Car
{
private:
    string model;
    Engine engine;
    Wheel wheels[4];
    Door doors[4];

public:
    Car(string model)    //Constructor
    {
        this->model = model;
    }

    void display() const     //Method
    {
        cout << "Car Model: " << model << endl;
    }

    Engine &getEngine()
    {
        return engine;
    }

    Wheel *getWheels() 
    {
        return wheels;
    }

    Door *getDoors()
    {
        return doors;
    }
};

int main()
{
    Car c("Honda Rebirth");

    c.display();
    c.getDoors()[0].open();  // Door Open
    c.getDoors()[0].close(); // Door Close
    c.getEngine().start();   // start the engine

    for (int i = 0; i < 4; i++)
    {
        c.getWheels()[i].inflate(); // Show all tires air
    }

    c.getDoors()[0].getwindow()[0].rolldown(); // Roll down the window

    c.getEngine().reverse(); // Reverse
    c.getEngine().stop();    // Car Stop
    return 0;
}
