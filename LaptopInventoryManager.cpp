#include <iostream>
using namespace std;

class Laptop
{
private:
    string brand;
    string model;
    string color;
    float price;
    float processorSpeed;
    int ram;
    float screenSize;

public:
    void setBrand(string brand)
    {
        this->brand = brand;
    }
    string getBrand()
    {
        return brand;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    string getModel()
    {
        return model;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    string getColor()
    {
        return color;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    float getprice()
    {
        return price;
    }
    void setspeed(float processSpeed)
    {
        this->processorSpeed = processorSpeed;
    }
    float getSpeed()
    {
        return processorSpeed;
    }
    void setram(int ram)
    {
        this->ram = ram;
    }
    int getram()
    {
        return ram;
    }
    void setScreen(float screenSize)
    {
        this->screenSize = screenSize;
    }
    float getscreen()
    {
        return screenSize;
    }

    void setData(string brand, string model, string color, float price, float processorSpeed, int ram, float screenSize)
    {
        setBrand(brand);
        setModel(model);
        setColor(color);
        setPrice(price);
        setspeed(processorSpeed);
        setram(ram);
        setScreen(screenSize);
    }

    void Display(); // Display Function Member
    // {
    //     cout << "Brand :" << getBrand() << endl;
    //     cout << "Model :" << getModel() << endl;
    //     cout << "Color :" << getColor() << endl;
    //     cout << "Price :" << getprice() << endl;
    //     cout << "Processor Speed :" << getSpeed() << endl;
    //     cout << "Ram :" << getram() << endl;
    //     cout << "Screen Size :" << getscreen() << endl;
    // }

    void updateRam(int update)
    {
        if (update >= 4)
        {
            ram += update;
            cout << "Sucessfully Upgraded :" << ram << " GB";
        }
        else
        {
            cout << "Too less to install for laptop,Minimum 4GB updgrade Required" << endl;
        }
    }
};

void Laptop :: Display()

{
        cout << "Brand :" << getBrand() << endl;
        cout << "Model :" << getModel() << endl;
        cout << "Color :" << getColor() << endl;
        cout << "Price :" << getprice() << endl;
        cout << "Processor Speed :" << getSpeed() << endl;
        cout << "Ram :" << getram() << endl;
        cout << "Screen Size :" << getscreen() << endl;
}



int main()
{
    int update;
    Laptop c1;
    c1.setData("HP", "840G5", "Silver", 49999.99, 3.7, 4, 14.6);

    c1.Display();

    cout << "Want to upgrade your Laptop Ram :";
    cin >> update;

    c1.updateRam(update);
}