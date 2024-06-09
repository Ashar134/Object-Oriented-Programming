#include <iostream>
using namespace std;
#define totalCourse 4
class Person
{
private:
    string name;

public:
    Person(string name = "N/A") // Constructor
    {
        this->name = name;
    }

    void setname(string name) // Setter Function
    {
        this->name = name;
    }

    string getname() // Getter Function
    {
        return name;
    }
};

class Course
{
private:
    int perCredit;
    string courseName[4];
    string courseNumber[4];
    int creditHour[4];
    char courseGrade[4];
    char feePaid;

public:
    Course(int perCredit = 0) // Constructor
    {
        setPerCredit(perCredit);
    }

    // Setter Function
    void setFeePaid(char feePaid)
    {
        this->feePaid = feePaid;
    }
    void setPerCredit(int perCredit)
    {
        this->perCredit = perCredit;
    }
    void addCourse(int index, string crName, string crNumber, int hour, char grade)
    {
        courseName[index] = crName;
        courseNumber[index] = crNumber;
        creditHour[index] = hour;
        courseGrade[index] = grade;
    }

    // Getter Function
    string getCourseName(int index)
    {
        return courseName[index];
    }

    string getCourseNumber(int index)
    {
        return courseNumber[index];
    }

    int getCreditHour(int index)
    {
        return creditHour[index];
    }

    char getCourseGrade(int index)
    {
        return courseGrade[index];
    }
    char getFeepaid()
    {
        return feePaid;
    }

    // Calculating the CGPA
    void CalculateGrades(char feePaid)
    {
        if (feePaid == 'y' || feePaid == 'Y')
        {

            int totalCredits = 0;
            double totalGradePoints = 0.0;

            for (int i = 0; i < 4; ++i)
            {
                totalCredits += creditHour[i];
                totalGradePoints += creditHour[i] * CheckGrade(courseGrade[i]);
            }

            double gpa = totalGradePoints / totalCredits;

            cout << "Total number of credits: " << totalCredits << endl;
            cout << "GPA: " << gpa << endl;
        }
        else
        {
            cout << "Your fee is not paid , To See your Report Pay the Fee first" << endl;
        }
    }

    // Function to calculate grade point based on the letter grade
    double CheckGrade(char grade)
    {
        switch (grade)
        {
        case 'A':
            return 4.0;
        case 'B':
            return 3.0;
        case 'C':
            return 2.0;

        case 'D':
            return 1.0;

        default:
            return 0.0; // Default value to unknown grades
        }
    }
};

class Student : public Person
{
private:
    int studentId;
    string rollno;

public:
    Course course;

    Student(string name = "N/A", int studentId = 0, string rollno = "N/A")
        : Person(name)
    {
        this->studentId = studentId;
        this->rollno = rollno;
    }

    void studentDetail(string name, int studentId, string rollno)
    {
        setname(name);
        this->studentId = studentId;
        this->rollno = rollno;
    }

    void Display()
    {
        // Display Student Data
        cout << "Student Name:" << getname() << endl;
        cout << "Student Id:" << studentId << endl;
        cout << "Number of Course Enrolled :" << totalCourse << endl;
        if (course.getFeepaid() == 'y' || course.getFeepaid() == 'Y')
        {

            // Displaying All Course details
            cout << "Course Number \t Course Name \t Credits \t  Grades" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << " " << course.getCourseNumber(i) << "\t\t " << course.getCourseName(i)
                     << "\t\t " << course.getCreditHour(i) << "\t\t " << course.getCourseGrade(i) << endl;
            }
        }
    }
};

int main()
{

    Student s1("Lisa Miller", 890238, "22p-9456");

    s1.course.addCourse(0, "Computer", "CSC418", 3, 'B');
    s1.course.addCourse(1, "History", "HIS353", 3, 'A');
    s1.course.addCourse(2, "Mathematics", "MTH325", 4, 'A');
    s1.course.addCourse(3, "Physics", "PHY335", 3, 'B');
    s1.course.setFeePaid('y');
    // Display student details and courses
    s1.Display();
    // Generate and display the grade report
    s1.course.CalculateGrades(s1.course.getFeepaid());

    //.......Student Class second Object
    cout << "------------------------------" << endl;
    Student s2("Ali Khan ", 857238, "22p-9423");
    s2.course.addCourse(0, "Computer", "CSC418", 3, 'B');
    s2.course.addCourse(1, "HCI", "HCI353", 3, 'A');
    s2.course.addCourse(2, "Calculus", "CAL325", 4, 'A');
    s2.course.addCourse(3, "OOP", "OOP335", 3, 'B');
    s2.course.setFeePaid('n');
    // Display student details and courses
    s2.Display();
    // Display the grade report
    s2.course.CalculateGrades(s2.course.getFeepaid());

    return 0;
}
