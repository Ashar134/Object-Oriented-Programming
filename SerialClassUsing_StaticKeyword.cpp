#include <iostream>
using namespace std;
class Serial
{
private:
    string serialNumber = "2202FAST";
    static int serial_count;

public:
    int CountObject() // Member Function
    {
        serial_count += 100;
        return serial_count;
    }
    void Display()
    {
        cout << "I'm Object with Serial Number :" << serialNumber << CountObject() << "P" << endl;
    }
};
int Serial ::serial_count = 0;

int main()
{
    Serial obj[5];

    for (int i = 0; i < 5; i++)
    {
        obj[i].Display();
    }
}