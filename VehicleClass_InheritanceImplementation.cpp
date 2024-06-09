#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int mileage;
    double price;

public:
    Vehicle(int mileage = 0, double price = 0.00) // constructor
    {
        this->mileage = mileage;
        this->price = price;
    }
};

class Car : public Vehicle
{
protected:
    int ownershipCost; 
    int warranty;      
    int seatingCapacity;
    string fuel;

public:
    Car(int mileage = 0, double price = 0.00, int ownershipCost = 0, int warranty = 0, int seatingCapacity = 0, string fuel = "N/A")
        : Vehicle(mileage, price)        //Constructor
    {
        this->ownershipCost = ownershipCost;
        this->warranty = warranty;
        this->seatingCapacity = seatingCapacity;
        this->fuel = fuel;
    }

    void Display() // Displaying method
    {
        cout << "Mileage: " << mileage << endl;
        cout << "Price: " << price << endl;
        cout << "Ownership Cost: " << ownershipCost << endl;
        cout << "Warranty: " << warranty << " years" << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Fuel Type: " << fuel << endl;
        
    }
};

class Bike : public Vehicle
{
protected:
    int numCylinders; // Number of cylinders
    int numGears;     // Number of gears
    string coolingType;
    string wheelType;
    double fuelTankSize;

public:
    Bike(int mileage = 0, double price = 0.00, int numCylinders = 0, int numGears = 0, string coolingType = "N/A", string wheelType = "N/A", double fuelTankSize = 0)
        : Vehicle(mileage, price)
    {
        this->numCylinders = numCylinders;
        this->numGears = numGears;
        this->coolingType = coolingType;
        this->wheelType = wheelType;
        this->fuelTankSize = fuelTankSize;
    }

    void Display() // Displaying bike info
    {
        cout << "Mileage: " << mileage << endl;
        cout << "Price: " << price << endl;
        cout << "Number of Cylinders: " << numCylinders << endl;
        cout << "Number of Gears: " << numGears << endl;
        cout << "Cooling Type: " << coolingType << endl;
        cout << "Wheel Type: " << wheelType << endl;
        cout << "Fuel Tank Size: " << fuelTankSize << endl;
      
    }
};

class Audi : public Car
{
protected:
    string model;

public:
    Audi(int mileage = 0, double price = 0.00, int ownershipCost = 0, int warranty = 0, int seatingCapacity = 0, string fuel = "N/A", string model = "N/A")
        : Car(mileage, price, ownershipCost, warranty, seatingCapacity, fuel)
    {
        this->model = model;
    }
    void showDetail()        //Displaying car info
    {
        cout << "Audi Model: " << model << endl;
        Car ::Display();
    }
};

class Ford : public Car
{
protected:
    string model;

public:
    Ford(int mileage = 0, double price = 0.00, int ownershipCost = 0, int warranty = 0, int seatingCapacity = 0, string fuel = "N/A", string model = "N/A")
        : Car(mileage, price, ownershipCost, warranty, seatingCapacity, fuel)
    {
        this->model = model;
    }

    void showDetail()    //Displaying car info
    {
        cout << "Ford Model: " << model << endl;
        Car ::Display();
    }
};

class Bajaj : public Bike
{
protected:
    string makeType;

public:
    Bajaj(int mileage = 0, double price = 0.00, int numCylinders = 0, int numGears = 0, string coolingType = "N/A", string wheelType = "N/A", double fuelTankSize = 0, string makeType = "N/A")
        : Bike(mileage, price, numCylinders, numGears, coolingType, wheelType, fuelTankSize)
    {
        this->makeType = makeType;
    }

    void showDetails() // Displaying the details of Bajaj
    {
        cout << "Make Type: " << makeType << endl;
        Bike::Display();
    }
};

class TVS : public Bike
{
protected:
    string makeType;

public:
    TVS(int mileage = 0, double price = 0.00, int numCylinders = 0, int numGears = 0, string coolingType = "N/A", string wheelType = "N/A", double fuelTankSize = 0, string makeType = "N/A")
        : Bike(mileage, price, numCylinders, numGears, coolingType, wheelType, fuelTankSize)
    {
        this->makeType = makeType;
    }

    void showDetails() // Displaying the details of TVS
    {
        cout << "Make Type: " << makeType << endl;
        Bike::Display();
    }
};

int main()
{
    Audi audi(25670, 55670, 345567, 6, 5, "Petrol", "Audi Etron");
    Ford ford(145, 456000, 4346000, 2, 4, "Diesel", "Ford Mustang");
    Bajaj bajaj(450, 254500, 2, 5, "Air", "Alloys", 12.5, "Pulsar 220");
    TVS tvs(343, 304560, 1, 4, "Liquid", "Spokes", 10.0, "Apache RT 160");

  
    audi.showDetail();                        //Displaying all vehicle information
    cout << "--------------------" << endl;

    ford.showDetail();
    cout << "--------------------" << endl;

    bajaj.showDetails();
    cout << "--------------------" << endl;

    tvs.showDetails();

    return 0;
}
