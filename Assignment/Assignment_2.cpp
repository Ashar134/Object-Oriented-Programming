#include <iostream>
using namespace std;
int account_num = 0;
class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accountNumber, string accountHolder, double balance);

    ~BankAccount();

    int Deposit(double depositAmount) // Deposit Function
    {
        balance = depositAmount;

        return balance;
    }

    void Withdraw(int amount) // Withdraw
    {
        if (balance < 500)
        {
            cout << "You have insufficient Balance" << endl;
        }
        else if (amount <= 0)
        {
            cout << "You have Entered Wrong Amount .....Re-Enter your Amount" << endl;
        }
        else if (balance >= 500)
        {
            balance -= amount;
        }
    }

    void setaccountNumber(int accountNumber) // Setter Function
    {
        this->accountNumber = accountNumber;
    }
    void setaccountHolder(string accountHolder)
    {
        this->accountHolder = accountHolder;
    }
    void setbalance(int balance)
    {
        this->balance = balance;
    }

    int getaccountNumber() // Getter Function
    {
        return accountNumber;
    }
    string getaccountHolder()
    {
        return accountHolder;
    }
    double getbalance()
    {
        return balance;
    }
};

BankAccount::BankAccount(int accountNumber = 0, string accountHolder = "N/A", double balance = 0.0) // Constructor
{
    this->setaccountNumber(accountNumber);
    this->setaccountHolder(accountHolder);
    this->setbalance(balance);
}

BankAccount::~BankAccount()
{
    cout << "Destructor Called" << endl;
}

class BankManager // Manager Class
{
private:
    BankAccount *account;
    int totalAccounts;

public:
    BankManager(int totalAccounts) // Constructor
    {
        this->totalAccounts = totalAccounts;
        this->account = new BankAccount[totalAccounts];
    }
    ~BankManager();

    void createAccount(string accountHolder, double balance) // Creating Account
    {

        account[account_num].setaccountNumber(account_num);
        account[account_num].setaccountHolder(accountHolder);
        account[account_num].setbalance(balance);

        cout << "Account Created Successfully" << endl;
        cout << "----------------------------" << endl;
        account_num++;
    }

    void deleteAccount(int ID) // Delete Account
    {
        for (int i = 0; i < account_num; i++)
        {
            if (ID == account[i].getaccountNumber())
            {
                account[i] = BankAccount();
                cout << "Account Deleted Successfully " << endl;
                cout << "----------------------------" << endl;
            }
        }
    }

    BankAccount *findAccount(int ID) // Find account
    {
        for (int i = 0; i < account_num; i++)
        {
            if (ID == account[i].getaccountNumber())
            {
                return &account[i];
            }
        }

        return nullptr;
    }

    void allAccountDetails() // All Account Details
    {

        cout << "ALL RECORDS " << endl;
        cout << "------------" << endl;
        for (int i = 0; i < account_num; i++)
        {
            cout << "Account Number :" << account[i].getaccountNumber() << endl;
            cout << "Account Holder :" << account[i].getaccountHolder() << endl;
            cout << "Current Balance :" << account[i].getbalance() << endl;
            cout << "------------------------" << endl;
        }

        cout << "Total Accounts Created : " << account_num << endl;
    }
};

BankManager ::~BankManager() // Destructor
{
    delete[] account;
    cout << "Destructor Called" << endl;
}
int main()
{
    int choice;
    string holderName;
    double balance;
    BankAccount *findAccount = nullptr;
    int ID;
    BankManager Manager(5);

    cout << "Welcome to Bank Managemen System" << endl;
    do
    {

        cout << "Press 1 | Create Acount" << endl;
        cout << "Press 2 | Find Acount" << endl;
        cout << "Press 3 | Delete Acount" << endl;
        cout << "Press 4 | All Records Acount" << endl;
        cout << "Press 5 | Existing the System" << endl;
        cout << "--PRESS--> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Account Holder Name :";
            cin >> holderName;
            cout << "Enter the Account Holder Balance :";
            cin >> balance;
            Manager.createAccount(holderName, balance);

            break;

        case 2:

            cout << "Enter the Accont Holder ID :";
            cin >> ID;
            findAccount = Manager.findAccount(ID);

            if (findAccount != nullptr)
            {
                cout << "Account Number: " << findAccount->getaccountNumber() << endl;
                cout << "Account Holder: " << findAccount->getaccountHolder() << endl;
                cout << "Current Balance: " << findAccount->getbalance() << endl;
            }
            else
            {
                cout << "Account Not found" << endl;
            }

            break;

        case 3:

            cout << "Enter the Accont Holder ID :";
            cin >> ID;
            Manager.deleteAccount(ID);

            break;

        case 4:

            Manager.allAccountDetails();
            break;

        default:
            cout << "Thanks for using the System" << endl;
            break;
        }

    } while (choice != 5);
}