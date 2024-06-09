#include <iostream>
using namespace std;

class BankAccount // Bank Account Class
{
protected:
    string accountNumber; // Holder info
    string holderName;
    double balance;

public:
    // Constructor
   
    BankAccount(string holderName = "N/A", string accountNumber ="N/A", double balance = 0.0)
    {
        this->holderName = holderName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void depositMoney(int ) = 0;
    virtual void withdrawMoney(int ) = 0;
    virtual void monthlyStatement() = 0;
};

class CheckingAccount : public BankAccount // Checking Account class inherit BankAccount publically
{
public:
    CheckingAccount() : BankAccount("N/A","N/A",0.0){}
    CheckingAccount(string holderName  , string accountNumber , double balance )
    : BankAccount(holderName,accountNumber,balance)
    {}

    virtual void checks(int ) = 0;
};
// ServiceChargeChecking Class inherit CheckingAccount publically
class ServiceChargeChecking : public CheckingAccount
{
protected:
    const int checksLimit = 3;
    int totalChecks;

public:
    // Constructor

    ServiceChargeChecking(string holderName ,string accountNumber, double balance)
        : CheckingAccount(holderName, accountNumber, balance)
    {
        totalChecks = 0;
    }

    // Methods
    void checks(int checkAmount) // If user pay check to withdraw the money
    {
        if (totalChecks < checksLimit) // Maximum limit of check is 3
        {

            if (balance > 0 && balance > checkAmount)
            {
                balance = balance - checkAmount;
                totalChecks++;
            }
            else
            {
                cout << "Exceed Checks Limit" << endl;
            }
        }
    }
    void depositMoney(int amount) // Deposit Override Function
    {
        balance += amount;
    }

    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Funds" << endl;
        }
    }

    void monthlyStatement()
    {
        cout << "-------MONTHLY STATEMENT-------" << endl;
        cout << "Account Holder Name :" << holderName << endl;
        cout << "Account Number :" << accountNumber << endl;
        cout << "Balance :" << balance << endl;
        cout << "Monthly Checks Limit :" << checksLimit << endl;
        cout << "Check Limit left :"<<checksLimit-totalChecks<<endl;
    }

  
};

class NoServiceCharge : public CheckingAccount // NoServiceCharge Class
{

protected:
    double interestRate;
    double minimumBalance;
    const int checksLimit = 3;
    int totalChecks;

public:
    NoServiceCharge(string holderName, string accountNumber , double balance)
        : CheckingAccount(holderName, accountNumber, balance)
    {
        this->interestRate = 1.5;
        // minimum balance must be 1000 not zero that already in the account when a user create
        this->minimumBalance = 1000.00;
        this->balance = minimumBalance;
        totalChecks = 0; // When a new user create account checklimit again zero
    }

    // Methods
    void checks(int checkAmount) // If user pay check to withdraw the money
    {
        if (totalChecks < checksLimit) // Maximum limit of check is 3
        {

            if (balance > 0 && balance > checkAmount)
            {

                balance = balance - checkAmount;
                totalChecks++;
            }
            else
            {
                cout << "Exceed Checks Limit" << endl;
            }
        }
    }
    void depositMoney(int amount) // Deposit Override Function
    {
        balance += amount;
    }

    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Funds" << endl;
        }
    }

    void monthlyStatement()
    {
        cout << "-------MONTHLY STATEMENT-------" << endl;
        cout << "Account Holder Name :" << holderName << endl;
        cout << "Account Number :" << accountNumber << endl;
        cout << "Balance :" << balance << endl;
        cout << "Monthly Checks Limit :" << checksLimit << endl;
        cout << "Interest Rate Amount :" << balance * interestRate << endl; // Calculating rate of interest
    }

};

class HighInterestChecking : public NoServiceCharge // HighInterest Class
{

public:
    HighInterestChecking(string holderName , string accountNumber , double balance )
        : NoServiceCharge(holderName, accountNumber, balance)
    {
        this->interestRate = 2.5; // High interest rate
        this->minimumBalance = 2000.00;
    }

    void depositMoney(int amount) // Deposit Override Function
    {
        balance += amount;
    }

    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Funds" << endl;
        }
    }   

    void monthlyStatement()
    {
        NoServiceCharge ::monthlyStatement();
    }
};

class SavingAccount : public BankAccount // Saving Account Class
{
protected:
    double interestRate;

public:
    SavingAccount(string holderName , string accountNumber, double balance )
        : BankAccount(holderName, accountNumber, balance)
    {
        this->interestRate = 0.5;
    }
     void depositMoney(int amount) // Deposit Override Function
    {
        balance += amount;
    }

    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Funds" << endl;
        }
    }


    void monthlyStatement()
    {
        cout << "-------MONTHLY STATEMENT-------" << endl;
        cout << "Account Holder Name :" << holderName << endl;
        cout << "Account Number :" << accountNumber << endl;
        cout << "Balance :" << balance << endl;

    }
};

class HighInterestRate : public SavingAccount
{
protected:
    double minimumBalance;

public:
    HighInterestRate(string holderName, string accountNumber , double balance)
        : SavingAccount(holderName, accountNumber, balance)
    {
        this->interestRate = 1.5;
        this->minimumBalance = 1500;
        this->balance=minimumBalance;
    }

    void monthlyStatement()
    {
        SavingAccount :: monthlyStatement();
        cout << "Interest Rate Amount :" << balance * interestRate << endl; // Calculating rate of interest
    }
    
};

class CertificateOfDeposit : public BankAccount
{
protected:
    int noCdmonth;
    double interestRate;
    int currentCdmonth;
public:
    CertificateOfDeposit(string holderName , string accountNumber, double balance ,  int noCdmonth, int currentCdmonth)
        : BankAccount(holderName, accountNumber, balance)
        {
            this->noCdmonth=noCdmonth;
            this->interestRate=0.3;
            this->currentCdmonth=currentCdmonth;
        }
    
    void depositMoney(int amount) // Deposit Override Function
    {
        balance += amount;
    }

    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Funds" << endl;
        }
    }

        void monthlyStatement()
    {
        cout << "-------MONTHLY STATEMENT-------" << endl;
        cout << "Account Holder Name :" << holderName << endl;
        cout << "Account Number :" << accountNumber << endl;
        cout << "Balance :" << balance << endl;
        cout << "No of Certificate of Deposit Month :"<<noCdmonth<<endl;
        cout << "Current Certificate of Deposit Month :"<<currentCdmonth<<endl;
         cout << "Interest Rate Amount :" << balance * interestRate << endl; // Calculating rate of interest
    }
};


int main()
{

    CheckingAccount *ptr1 , *ptr2 , *ptr3;

    ServiceChargeChecking c1("Ali","45645-646-56",4464.66);
    ptr1=&c1;
    ptr1->checks(500.00);
    ptr1->withdrawMoney(1000.00);
    ptr1->monthlyStatement();
    cout<<"------------------------"<<endl;

    NoServiceCharge c2("Ahmed","1245-656-01",10000.00);
    ptr2=&c2;
    ptr2->withdrawMoney(5000);
    ptr2->depositMoney(1000);
    ptr2->monthlyStatement();
    cout<<"------------------------"<<endl;

    HighInterestChecking c3("Ashar","5678-626-01",10000.00);
    ptr3=&c3;
    ptr3->depositMoney(5000);
    ptr3->monthlyStatement();
    
    BankAccount *ptr4 ,*ptr5;

    SavingAccount c4("Ubaid","4678-626-02",15000.00);
    ptr4=&c4;
    ptr4->monthlyStatement();
    cout<<"------------------------"<<endl;

    CertificateOfDeposit c5("Adil","4678-634-02",20000.00,12,4);
    ptr5=&c5;
    ptr5->monthlyStatement();


    return 0;
}
