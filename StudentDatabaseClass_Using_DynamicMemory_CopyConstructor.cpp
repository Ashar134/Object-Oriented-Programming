#include <iostream>
using namespace std;

class StudentDatabase
{
private:
    int *studentIDs;
    string *studentNames;
    string *studentProjects;
    int capacity;
    int size;

public:
    StudentDatabase(int capacity = 10) // Constructor
    {
        this->capacity = capacity;
        this->studentIDs = new int[capacity];
        this->studentNames = new string[capacity];
        this->studentProjects = new string[capacity];
        this->size = 0;
    }
    ~StudentDatabase() // Destructor
    {
        delete[] studentIDs;
        delete[] studentNames;
        delete[] studentProjects;

        cout << "Destructor Called" << endl;
    }

    StudentDatabase(const StudentDatabase &otherObject) // Copy Constructor
    {
        capacity = otherObject.capacity;
        size = otherObject.size;

        studentIDs = new int[capacity]; // Deep copy of StudentID

        for (int i = 0; i < size; i++)
        {
            studentIDs[i] = otherObject.studentIDs[i];
        }

        studentNames = new string[capacity]; // Deep copy of StudentName

        for (int i = 0; i < size; i++)
        {
            studentNames[i] = otherObject.studentNames[i];
        }

        studentProjects = new string[capacity]; // Deep copy of StudentProject

        for (int i = 0; i < size; i++)
        {
            studentProjects[i] = otherObject.studentProjects[i];
        }
    }

    void addStudent(int ID, string name, string projectName) // Add Student Function
    {

        studentIDs[size] = ID;
        studentNames[size] = name;
        studentProjects[size] = projectName;
        cout << "Student Add Sucessfully" << endl;

        size++;
    }

    string getStudentinfo(int id) // Searching
    {
        string combine;
        for (int i = 0; i <= size; i++)
        {
            if (id == studentIDs[i])
            {
                combine = studentNames[i] + " " + studentProjects[i];
            }
        }

        return combine;
    }

    void listAllStudents() // All Record
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Student ID : " << studentIDs[i] << endl;
            cout << "Student Name : " << studentNames[i] << endl;
            cout << "Project Name : " << studentProjects[i] << endl;
            cout << "---------------------------------------" << endl;
        }
    }
};

int main()
{
    StudentDatabase database;

    // Adding students

    database.addStudent(101, "Ali", "Project A");
    database.addStudent(102, "Charlie", "Project B");
    database.addStudent(103, "Bob", "Project C");

    // searching students
    cout << "------Searching------" << endl;
    cout << "Student 101 : " << database.getStudentinfo(101) << endl;
    cout << "Student 102 : " << database.getStudentinfo(102) << endl;
    // Printing All Student Data
    cout << "All Student " << endl;
    cout << "------------" << endl;
    database.listAllStudents();

    // Copying
    StudentDatabase copyOfDatabase(database);

    cout << "All student in  Copied Database : " << endl;
    copyOfDatabase.listAllStudents();
}