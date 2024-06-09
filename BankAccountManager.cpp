#include <iostream>
using namespace std;
class Account
{
private:
    string name;
    double balance;

public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    double getBalance()
    {
        return balance;
    }

    void setData(string name, double balance)
    {
        setName(name);
        setBalance(balance);
    }
    void Display()
    {
        cout << "Name :" << getName() << endl;
        cout << "Balance Avaible :" << getBalance() << endl;
    }

    void DepositMoney()
    {
        float deposit;
        cout << "Enter the Amount you want to Deposit :";
        cin >> deposit;

        balance += deposit;
    }

    void WithdrawMoney()
    {
        int withdraw;

        cout << "Enter the Withdraw Amount :";
        cin >> withdraw;

        if (withdraw > balance)
        {
            cout << "Insufficient Amount,Low Balance" << endl;
        }
        else if (withdraw < 0)
        {
            cout << "Amount cannot be Negative" << endl;
        }
        else
        {
            balance -= withdraw;
            cout << "Thanks for Withdraw the Money" << endl;
        }
    }
};

int main()
{
    Account c1;
    int withdraw;
    int deposit;
    int choice;

    c1.setData("Ali Akram", 5000);

    cout << "Welcome to Bank Managment System" << endl
         << endl;
    do
    {

        cout << "Press 1 for Deposit Money " << endl;
        cout << "Press 2 for Withdraw Money" << endl;
        cout << "Press 3 for Check Balance" << endl;
        cout << "Press 4 for Logout" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            c1.DepositMoney();
            break;

        case 2:

            c1.WithdrawMoney();
            break;

        case 3:

            c1.Display();
            break;
        }
    } while (choice != 4);
}