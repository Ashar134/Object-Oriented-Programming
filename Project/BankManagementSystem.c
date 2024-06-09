#include <iostream>
using namespace std;
int account_num = 1;
int employee_num = 1;

class BankAccount // Bank Account Class
{
protected:
    int accountNumber; // Holder info
    string holderName;
    double balance;

public:
    // Constructor
    BankAccount(string holderName = "N/A", int accountNumber = 0, double balance = 0.0)
    {
        this->holderName = holderName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void depositMoney(double) = 0;
    virtual void withdrawMoney(int) = 0;
    virtual void monthlyStatement() = 0;
};

class SavingAccount : public BankAccount // Saving Account Class
{
protected:
    double interestRate;

public:
    SavingAccount(string holderName, int accountNumber, double balance)
        : BankAccount(holderName, accountNumber, balance)
    {
        this->interestRate = 10.0;
    }

    // Methods
    void depositMoney(double amount) // Deposit Override Function
    {
        balance += amount;

        cout << "Balance :" << balance << endl;
    }
    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 1000 && balance > amount) // Saving Account minimum balance 1000
        {
            balance = balance - amount;
            cout << "WithDraw Amount :" << amount << endl;
            cout << "Current Balance :" << balance << endl;
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
        cout << "Interest Amount on Current Balance :" << (balance * interestRate) / 100 << endl;
    }
};
class CurrentAccount : public BankAccount // Saving Account Class
{

public:
    CurrentAccount(string holderName, int accountNumber, double balance)
        : BankAccount(holderName, accountNumber, balance) {}

    //.............Methods
    void depositMoney(double amount) // Deposit Override Function
    {
        balance += amount;
        cout << "Current Balance :" << balance << endl;
    }
    void withdrawMoney(int amount) // Withdraw Override Function
    {
        if (balance > 0 && balance > amount) // Current Account don't require minimum balance
        {
            balance = balance - amount;
            cout << "Withdraw Amount :" << amount << endl;
            cout << "Current Balance :" << balance << endl;
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

class Customer
{
private:
    SavingAccount *save_account;     // Customer has a SavingAccount
    CurrentAccount *current_account; // Customer has a CurrentAccount
    int accountNumber;
    string accountHolder;
    string gender;
    string cnic;
    string mobileNo;
    string accountType;
    double balance;
    string pin;

public:
    Customer()
    {
        accountNumber = 0;
        accountHolder = "N/A";
        gender = "N/A";
        cnic = "N/A";
        mobileNo = "N/A";
        accountType = "N/A";
        balance = 0.0;
        pin = "N/A";
    }
    Customer(int accountNumber, string accountHolder, double balance, string gender, string cnic, string mobileNo, string accountType, string pin);

    ~Customer();

    void setaccountNumber(int accountNumber) // Setter Function
    {
        this->accountNumber = accountNumber;
    }
    void setaccountHolder(string accountHolder)
    {
        this->accountHolder = accountHolder;
    }
    void setbalance(double balance)
    {
        this->balance = balance;
    }
    void setCnic(string cnic)
    {
        this->cnic = cnic;
    }
    void setMobileNo(string mobileNo)
    {
        this->mobileNo = mobileNo;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setAccountType(string accountType)
    {
        this->accountType = accountType;
    }
    void setPin(string pin)
    {
        this->pin = pin;
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
    string getCnic()
    {
        return cnic;
    }
    string getMobileNo()
    {
        return mobileNo;
    }
    string getGender()
    {
        return gender;
    }
    string getAccountType()
    {
        return accountType;
    }
    string getPin()
    {
        return pin;
    }
    void setSavingAccount(SavingAccount *S_account)
    {
        save_account = S_account;
    }
    void setCurrentAccount(CurrentAccount *C_account)
    {
        current_account = C_account;
    }
    SavingAccount *getSavingAccount() // return if the customer has savingAccount
    {
        return save_account;
    }
    CurrentAccount *getCurrentAccount() // return if the customer has CurrentAccount
    {
        return current_account;
    }
};

Customer::Customer(int accountNumber, string accountHolder, double balance, string gender, string cnic, string mobileNo, string accountType, string pin) // Constructor
{
    setaccountNumber(account_num);
    setaccountHolder(accountHolder);
    setGender(gender);
    setCnic(cnic);
    setMobileNo(mobileNo);
    setAccountType(accountType);
    setbalance(balance);
    setPin(pin);
}

Customer::~Customer()
{
    cout << "Destructor Called" << endl;
}

//--------------EMPLOYEE CLASS--------------

class BankEmployee
{
private:
    string employeeName;
    int employeeID;
    string gender;
    string designation;
    string mobileNumber;
    string department;
    string userName;
    string password;

    Customer *account;
    int totalAccounts; // Total Accounts that we can create

public:
    BankEmployee() {}
    BankEmployee(int total) // Constructor
    {
        totalAccounts = total;
        account = new Customer[totalAccounts];
    }
    ~BankEmployee()
    {
        // delete[] account;
    }

    // Setter Function
    void setEmployeeName(string employeeName)
    {
        this->employeeName = employeeName;
    }
    void setEmployeeID(int employeeID)
    {
        this->employeeID = employeeID;
    }
    void setDesignation(string designation)
    {
        this->designation = designation;
    }
    void setMobileNumber(string mobileNumber)
    {
        this->mobileNumber = mobileNumber;
    }
    void setDepartment(string deparment)
    {
        this->department = deparment;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setUsername(string userName)
    {
        this->userName = userName;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    // Getter Function
    string getEmployeeName()
    {
        return employeeName;
    }
    int getEmployeeID()
    {
        return employeeID;
    }
    string getDesination()
    {
        return designation;
    }
    string getMobileNumber()
    {
        return mobileNumber;
    }
    string getDepartment()
    {
        return department;
    }
    string getGender()
    {
        return gender;
    }
    string getUsername()
    {
        return userName;
    }
    string getPassword()
    {
        return password;
    }
    // Customer Account Details in the below methods
    void createAccount(string accountHolder, string gender, string mobileNo, string cnic, string accountType, double balance, string pin = "1234")
    {
        Customer customer(account_num, accountHolder, balance, gender, cnic, mobileNo, accountType, pin);

        if (accountType == "Saving")
        {
            customer.setSavingAccount(new SavingAccount(accountHolder, account_num, balance));
            cout << "Saving Account Created Successfully" << endl;
        }
        else if (accountType == "Current")
        {
            customer.setCurrentAccount(new CurrentAccount(accountHolder, account_num, balance));
            cout << "Current Account Created Successfully" << endl;
        }
        else
        {
            cout << "Invalid account type" << endl;
            return;
        }

        cout << "----------------------------" << endl;
        account[account_num] = customer;
        account_num++;
    }

    void deleteAccount(int ID) // Delete Account
    {
        for (int i = 1; i <= account_num; i++)
        {
            if (ID == account[i].getaccountNumber())
            {
                for (int j = i; j < account_num - 1; j++)
                {
                    account[j] = account[j + 1];
                }
                account_num--;
                cout << "Account Deleted Successfully " << endl;
                cout << "----------------------------" << endl;
            }
        }
    }

    Customer *findAccount(int ID) // Find account
    {
        for (int i = 1; i < account_num; i++)
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
        for (int i = 1; i < account_num; i++)
        {
            cout << "Account Number: " << account[i].getaccountNumber() << endl;
            cout << "Account Holder: " << account[i].getaccountHolder() << endl;
            cout << "Gender: " << account[i].getGender() << endl;
            cout << "Mobile No: " << account[i].getMobileNo() << endl;
            cout << "CNIC: " << account[i].getCnic() << endl;
            cout << "Account Type: " << account[i].getAccountType() << endl;
            cout << "Current Balance: " << account[i].getbalance() << endl;
            cout << "------------------------" << endl;
        }

        cout << "Total Accounts Created : " << account_num - 1 << endl;
    }
};

class BankManager : public BankEmployee // Manager Class
{
private:
    BankEmployee *employee;
    int totalEmployee = 10;

public:
    BankManager() {}
    BankManager(int totalEmployee) // Constructor
    {
        this->totalEmployee = totalEmployee;
        this->employee = new BankEmployee[totalEmployee];
    }
    ~BankManager();

    // Employee Account Details in the below methods
    //.....Adding the Employees
    void addEmployee(string name, string gender, string mobileNumber, string designation, string department)
    {
        employee[employee_num].setEmployeeName(name);
        employee[employee_num].setEmployeeID(employee_num);
        employee[employee_num].setGender(gender);
        employee[employee_num].setMobileNumber(mobileNumber);
        employee[employee_num].setDesignation(designation);
        employee[employee_num].setDepartment(department);
        employee[employee_num].setPassword("employee123");

        employee_num++;
    }

    BankEmployee *employeeInfo(int ID) // Find Employee account
    {
        for (int i = 1; i < employee_num; i++)
        {
            if (ID == employee[i].getEmployeeID())
            {
                return &employee[i];
            }
        }

        return nullptr;
    }

    void allEmployeeDetails() // All Employee Details
    {

        cout << "ALL RECORDS " << endl;
        cout << "------------" << endl;
        for (int i = 1; i < employee_num; i++)
        {
            cout << " Employee Name :" << employee[i].getEmployeeName() << endl;
            cout << "Employee ID : " << employee[i].getEmployeeID() << endl;
            cout << "Gender : " << employee[i].getGender() << endl;
            cout << "Employee Moblie Number: " << employee[i].getMobileNumber() << endl;
            cout << "Employee Designation : " << employee[i].getDesination() << endl;
            cout << "Employee Department : " << employee[i].getDepartment() << endl;
            cout << "------------------------" << endl;
        }
        cout << "Total Employees: " << employee_num - 1 << endl;
    }
};
//------------------------END------------------------

BankManager ::~BankManager() // Destructor
{
    delete[] employee;
}

//...........FUNCTION PROTOTYPE

void ManagerHomePage(BankManager &manager);
void EmpoloyeeHomePage(BankEmployee &employee);
void CustomerHomePage(Customer *customer);
int main()
{

    int id;
    BankEmployee *employeeInfo = nullptr; // Bank Employee Pointer
    BankManager manager(5);
    BankEmployee employee(10);
    int loginChoice;
    // User Name or password variable
    string userName;
    string password;
    string e_password;
    BankEmployee *check_ID = nullptr;
    string pin;
    Customer *findAccount = nullptr;
    int customerID;
    Customer *findID = nullptr;

    cout << "Welcome to Bank Managemen System" << endl;

    do
    {
        cout << "-----------LOGIN PAGE-----------" << endl;
        cout << "Press 1 | Login As a Manager " << endl;
        cout << "Press 2 | Login As a Employee " << endl;
        cout << "Press 3 | Login As a Customer " << endl;
        cout << "Press 4 | Quit the system " << endl;
        cout << "--------------------------------" << endl;
        cin >> loginChoice;

        switch (loginChoice)
        {
        case 1:

            cout << "Enter your UserName: ";
            cin >> userName;

            do
            {
                cout << "Enter the Password: ";
                cin >> password;

                if (password == "admin123")
                {
                    cout << "Reset new password: ";
                    cin >> password;
                    manager.setPassword(password);
                    cout << "Password updated successfully!" << endl;
                }
                else if (password == manager.getPassword())
                {
                    cout << "Login as Manager" << endl;
                    ManagerHomePage(manager); // Manager Home page
                }
                else
                {
                    cout << "Invalid password. Access denied." << endl;
                }

            } while (password != manager.getPassword());
            break;
        case 2: // Employee Login

            do
            {

                cout << "Enter your ID: ";
                cin >> id;
                check_ID = manager.employeeInfo(id); // Getting Employee ID want to login
                cout << "Enter the password: ";
                cin >> e_password;

                if (e_password == "employee123") // New Employee password first time
                {
                    cout << "Reset new password: ";
                    cin >> e_password;
                    check_ID->setPassword(e_password);
                    cout << "Password updated successfully!" << endl;
                }
                else if (check_ID->getPassword() == e_password)
                {

                    if (check_ID->getEmployeeID() == id && check_ID->getPassword() == e_password)
                    {
                        cout << "Login as A Employee" << endl;
                        EmpoloyeeHomePage(employee);
                    }
                }
                else
                {
                    cout << "Invalid Password" << endl;
                }

            } while (e_password != check_ID->getPassword());
            break;

        case 3:
            do
            {
                cout << "Enter your ID :";
                cin >> customerID;
                findID = employee.findAccount(customerID);
                cout << "Enter your PIN :"; // First time default password 1234
                cin >> pin;
                if (findID != nullptr)
                {
                    if (pin == "1234")
                    {
                        /*then every Customer set the new password*/
                        cout << "Reset New PIN " << endl;
                        cout << "Enter your PIN :";
                        cin >> pin;
                        findID->setPin(pin);
                        cout << "PIN update Successfully" << endl;
                    }
                    else if (findID->getPin() == pin)
                    {
                        cout << "Login As a Customer" << endl;
                        CustomerHomePage(findID); // Customer HomePage Function
                    }
                    else
                    {
                        cout << "Invalid Password" << endl;
                    }
                }
                else
                {
                    cout << "No Account Found" << endl;
                }

            } while (pin != findID->getPin());
            break;
        case 4:
            cout << "Thanks for using the Program!" << endl;
            break;
        default:
            cout << "Invalid choice !" << endl;
        }

    } while (loginChoice != 4);
}

void ManagerHomePage(BankManager &manager) // Manager Home Page
{
    string emp_password;
    int managerChoice;
    string name;
    int id;
    string designation;
    string mobileNumber;
    string department;
    BankEmployee *employeeInfo = nullptr; // Bank Employee Pointer
    int empolyeeID;
    string gender;
    int choiceGender;
    do
    {
        cout << "-----------MANAGER HOMEPAGE-----------" << endl;
        cout << "Press 1 | Add the Employee" << endl;
        cout << "Press 2 | Search for the Employee" << endl;
        cout << "Press 3 | All Employee Details" << endl;
        cout << "Press 4 | Existing the System" << endl;
        cout << "--------------------------------------" << endl;
        cout << "--PRESS--> ";
        cin >> managerChoice;

        switch (managerChoice)
        {
        case 1:
            cout << "Employee Name : ";
            cin >> name;
            cout << "Select Gender" << endl; // Selecting Gender
            cout << "Press 1 | Male " << endl;
            cout << "Press 2 | Female " << endl;
            cin >> choiceGender;
            if (choiceGender == 1)
            {
                gender = "Male";
            }
            else
            {
                gender = "Female";
            }
            cout << "Employee Designation : ";
            cin >> designation;
            cout << "Employee Mobile Number : ";
            cin >> mobileNumber;
            cout << "Employee Department : ";
            cin >> department;
            manager.addEmployee(name, gender, designation, mobileNumber, department);

            break;
        case 2:

            cout << "Enter the EmployeeID :";
            cin >> empolyeeID;
            employeeInfo = manager.employeeInfo(empolyeeID);

            if (employeeInfo != nullptr)
            {
                cout << "Employee Name :" << employeeInfo->getEmployeeName() << endl;
                cout << "Employee ID : " << employeeInfo->getEmployeeID() << endl;
                cout << "Employee Moblie Number: " << employeeInfo->getMobileNumber() << endl;
                cout << "Employee Designation : " << employeeInfo->getDesination() << endl;
                cout << "Employee Department : " << employeeInfo->getDepartment() << endl;
            }
            else
            {
                cout << "Employee Not found" << endl;
            }

            break;

        case 3:
            manager.allEmployeeDetails();
            break;

        default:

            cout << "Logout from Manger HomePage" << endl;
            break;
        }
    } while (managerChoice != 4);
}

void EmpoloyeeHomePage(BankEmployee &employee) //......Employee Home Page
{
    string holderName;
    double balance;
    Customer *findAccount = nullptr; // Customer Class Pointer
    int customerID;
    int employeeChoice;
    string gender;
    string mobileNo;
    string cnic;
    string accountType;
    int choiceGender;
    int choiceAccoutType;
    do
    {
        cout << "-----------EMPLOYEE HOMEPAGE-----------" << endl;
        cout << "Press 1 | Create Acount" << endl;
        cout << "Press 2 | Find Customer Acount" << endl;
        cout << "Press 3 | Delete Acount" << endl;
        cout << "Press 4 | All Records Acount" << endl;
        cout << "Press 5 | LogOut From Epmloyee HomePage" << endl;
        cout << "-------------------------------" << endl;
        cout << "--PRESS--> ";
        cin >> employeeChoice;

        switch (employeeChoice)
        {
        case 1:
            cout << "Enter the Account Holder Name :";
            cin >> holderName;
            cout << "Select Gender" << endl; // Selecting Gender
            cout << "Press 1 | Male " << endl;
            cout << "Press 2 | Female " << endl;
            cin >> choiceGender;
            if (choiceGender == 1)
            {
                gender = "Male";
            }
            else
            {
                gender = "Female";
            }
            cout << "Enter the Mobile No :";
            cin >> mobileNo;
            cout << "Enter the CNIC :";
            cin >> cnic;
            cout << "Select Account Type" << endl;
            cout << "Press 1 | Saving " << endl;
            cout << "Press 2 | Current " << endl;
            cin >> choiceAccoutType;
            if (choiceAccoutType == 1)
            {
                accountType = "Saving";
            }
            else
            {
                accountType = "Current";
            }
            cout << "Enter the Account Holder Balance :";
            cin >> balance;
            employee.createAccount(holderName, gender, mobileNo, cnic, accountType, balance);
            break;

        case 2:

            cout << "Enter the Accont Holder ID :";
            cin >> customerID;
            findAccount = employee.findAccount(customerID);

            if (findAccount != nullptr)
            {
                cout << "Account Number: " << findAccount->getaccountNumber() << endl;
                cout << "Account Holder: " << findAccount->getaccountHolder() << endl;
                cout << "Gender: " << findAccount->getGender() << endl;
                cout << "Mobile No: " << findAccount->getMobileNo() << endl;
                cout << "CNIC: " << findAccount->getCnic() << endl;
                cout << "Account Type: " << findAccount->getAccountType() << endl;
                cout << "Current Balance: " << findAccount->getbalance() << endl;
            }
            else
            {
                cout << "Account Not found" << endl;
            }

            break;

        case 3:

            cout << "Enter the Accont Holder ID :";
            cin >> customerID;
            employee.deleteAccount(customerID);

            break;

        case 4:

            employee.allAccountDetails();
            break;

        default:
            cout << "LogOut From Employee HomePage" << endl;
            break;
        }
    } while (employeeChoice != 5);
}

void CustomerHomePage(Customer *customer)
{
    int choiceCustomer;
    double depositAmount;
    int withdrawAmount;

    do
    {
        cout << "-----------CUSTOMER HOMEPAGE-----------" << endl;
        cout << "Press 1 | Deposit Money" << endl;
        cout << "Press 2 | Withdraw Money" << endl;
        cout << "Press 3 | Monthly Statement" << endl;
        cout << "Press 4 | Logout from Customer HomePage" << endl;
        cout << "--------------------------------------" << endl;
        cout << "--PRESS--> ";
        cin >> choiceCustomer;

        switch (choiceCustomer)
        {
        case 1:
            cout << "Enter the Deposit Amount :";
            cin >> depositAmount;
            if (customer->getAccountType() == "Saving")
            {
                customer->getSavingAccount()->depositMoney(depositAmount);
            }
            else if (customer->getAccountType() == "Current")
            {
                customer->getCurrentAccount()->depositMoney(depositAmount);
            }

            break;
        case 2:
            cout << "Enter the Withdraw Amount :";
            cin >> withdrawAmount;
            if (customer->getAccountType() == "Saving")
            {
                customer->getSavingAccount()->withdrawMoney(withdrawAmount);
            }
            else if (customer->getAccountType() == "Current")
            {
                customer->getCurrentAccount()->withdrawMoney(withdrawAmount);
            }

            break;

        case 3:

            if (customer->getAccountType() == "Saving")
            {
                customer->getSavingAccount()->monthlyStatement();
            }
            else if (customer->getAccountType() == "Current")
            {
                customer->getCurrentAccount()->monthlyStatement();
            }

            break;

        default:

            cout << "LogOut From CustomerHome Page" << endl;
        }
    } while (choiceCustomer != 4);
}
