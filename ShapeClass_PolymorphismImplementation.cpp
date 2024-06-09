#include <iostream>
using namespace std;

class Shape         // Shape Class
{
public:
    virtual void area() = 0;
  
};

class Shape2D : public Shape    // 2D shape
{
};

class Shape3D : public Shape       // 3D shape
{
public:
    virtual void volume() = 0;
};

class Circle : public Shape2D
{
private:
    int radius;
    float pi;

public:
Circle(){}
    Circle(int radius)         // Constructor of Circle Class
    {
        this->radius = radius;
        this->pi = 3.14;
    }

    void area()
    {
        cout << "Area of Circle: " << radius * pi << endl;
    }

    ~Circle()
    {
    }
};

class Square : public Shape2D
{
private:
    int side;

public:
    Square(int side = 0) // Constructor of Square
    {
        this->side = side;
    }

    void area()
    {
        cout << "Area of Square: " << side * side << endl;
    }

    
};

class Cube : public Shape3D
{
private:
    float length;
    float breath;
    float height;

public:
    Cube(float length = 0.00, float breath = 0.00, float height = 0.00)
    {
        this->length = length;
        this->breath = breath;
        this->height = height;
    }

    void area()
    {
        cout << "Area of cube: " << length * breath * height << endl;
    }

    void volume()
    {
        cout << "Volume of cube: " << length * length * length << endl;
    }

    ~Cube()
    {
    }
};

class Pyramid : public Shape3D
{
private:
    float base;
    float height;

public:
    Pyramid(float base = 0.00, float height = 0.00)
    {
        this->base = base;
        this->height = height;
    }

    void area()
    {
        cout << "Area of Pyramid: " << (float) 1/2 * (base * height) + base << endl;
    }

    void volume()
    {
        cout << "Volume of Pyramid: " <<(float) 1/3 * (base * height) << endl;
    }

    ~Pyramid()
    {
    }
};

int main ()
{
    Shape *ptr1[4];

    Circle c1(2),c2(5);
    Square s1(5),s2(7);
    ptr1[0]=&c1;
    ptr1[1]=&c2;
    ptr1[2]=&s1;
    ptr1[3]=&s2;

    for (int i = 0; i < 4; i++)
    {
        ptr1[i]->area();
    }
    
}

// int main()
// {
//     Shape2D *ptr1[4];        //pointer of 2d Shape
//     Shape3D *ptr2[4];        //pointer of 2d Shape


// //Initializing the values 
//     ptr1[0] = new Circle(2);
//     ptr1[1] = new Circle(5);
//     ptr1[2] = new Square(5);
//     ptr1[3] = new Square(7);

// //Initializing the values 
//     ptr2[0] = new Cube(4.4, 5.6, 3.6);
//     ptr2[1] = new Cube(6.6, 4.7, 4.8);
//     ptr2[2] = new Pyramid(3.4, 6.7);
//     ptr2[3] = new Pyramid(3.1, 6.3);

// //printing the output
//     for (int i = 0; i < 4; i++)
//     {
//         ptr1[i]->area();
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         ptr2[i]->area();
//         ptr2[i]->volume();
//     }

//     for (int i = 0; i < 4; i++)         //To avoid memory leakage
//     {
//         delete ptr1[i];
//         delete ptr2[i];
//     }

//     return 0;
// }


