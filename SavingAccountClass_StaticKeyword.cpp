#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    SavingsAccount(double savingsBalance = 0) // constructor
    {
        this->savingsBalance = savingsBalance;
    }

    void calculateMonthlyInterest() // Member Function
    {
        double monthlyInterest;

        monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    void displayBalance() const
    {
        cout << "Current Balance: $" << savingsBalance << endl;
    }

    static void modifyInterestRate(double InterestRate)
    {
        annualInterestRate = InterestRate;
    }
};

double SavingsAccount::annualInterestRate = 0.03;

int main()
{
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    cout << "Initial Balances" << endl;
    saver1.displayBalance();
    saver2.displayBalance();

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout<<"-----------------------------"<<endl;
    cout << "Balances after interest at 3%" << endl;
    saver1.displayBalance();
    saver2.displayBalance();

    saver1.modifyInterestRate(0.04); // modify interest rate

    cout<<"-----------------------------"<<endl;
    cout << "Balances after interest at 4%" << endl;
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    saver1.displayBalance();
    saver2.displayBalance();

    return 0;
}
