#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course
{
    string name;
    int creditHour;
    double gradePoint;
};

struct Semester
{
    vector<Course> courses;
    double GPA;
    int totalCredits;
};

vector<Semester> semesters;

void addSemester()
{
    Semester sem;

    int n;

    cout << "\nNumber of Courses: ";
    cin >> n;

    sem.totalCredits = 0;

    double totalPoints = 0;

    for(int i=0;i<n;i++)
    {
        Course c;

        cout << "\nCourse " << i+1 << endl;

        cout << "Course Name: ";
        cin >> c.name;

        cout << "Credit Hours: ";
        cin >> c.creditHour;

        cout << "Grade Point (0-4): ";
        cin >> c.gradePoint;

        sem.courses.push_back(c);

        sem.totalCredits += c.creditHour;

        totalPoints += c.gradePoint * c.creditHour;
    }

    sem.GPA = totalPoints / sem.totalCredits;

    semesters.push_back(sem);

    cout << "\nSemester Added Successfully!\n";
    cout << "Semester GPA = "
         << fixed << setprecision(2)
         << sem.GPA << endl;
}

void displaySemesterGPAs()
{
    if(semesters.empty())
    {
        cout << "\nNo Semester Added.\n";
        return;
    }

    cout << "\n===== Semester GPAs =====\n";

    for(int i=0;i<semesters.size();i++)
    {
        cout << "Semester "
             << i+1
             << " GPA = "
             << fixed
             << setprecision(2)
             << semesters[i].GPA
             << endl;
    }
}

double calculateCGPA(int &completedCredits)
{
    double totalPoints = 0;

    completedCredits = 0;

    for(int i = 0; i < semesters.size(); i++)
{
    totalPoints += semesters[i].GPA * semesters[i].totalCredits;
    completedCredits += semesters[i].totalCredits;
}

    if(completedCredits==0)
        return 0;

    return totalPoints/completedCredits;
}

void displayCGPA()
{
    if(semesters.empty())
    {
        cout << "\nNo Data Available.\n";
        return;
    }

    int credits;

    double cgpa = calculateCGPA(credits);

    cout << "\nCompleted Credits = "
         << credits << endl;

    cout << "Current CGPA = "
         << fixed
         << setprecision(2)
         << cgpa
         << endl;
}

void predictGPA()
{
    if(semesters.empty())
    {
        cout << "\nNo Semester Data Found.\n";
        return;
    }

    int completedCredits;

    double currentCGPA = calculateCGPA(completedCredits);

    int remainingCredits;

    double targetCGPA;

    cout << "\nCurrent CGPA = "
         << fixed
         << setprecision(2)
         << currentCGPA
         << endl;

    cout << "Completed Credits = "
         << completedCredits
         << endl;

    cout << "\nEnter Remaining Credits: ";
    cin >> remainingCredits;

    if(remainingCredits<=0)
    {
        cout << "Invalid Credits.\n";
        return;
    }

    cout << "Enter Target CGPA: ";
    cin >> targetCGPA;

    double currentPoints =
            currentCGPA * completedCredits;

    double requiredGPA =
        (targetCGPA *
        (completedCredits + remainingCredits)
        - currentPoints)
        / remainingCredits;

    cout << endl;

    if(requiredGPA>4.0)
    {
        cout << "Target CGPA cannot be achieved.\n";
    }
    else if(requiredGPA<0)
    {
        cout << "Target already achieved.\n";
    }
    else
    {
        cout << "Minimum GPA Required = "
             << fixed
             << setprecision(2)
             << requiredGPA
             << endl;
    }
}

void displayAll()
{
    if(semesters.empty())
    {
        cout << "\nNo Data.\n";
        return;
    }

    cout << "\n========== Student Record ==========\n";

    for(int i=0;i<semesters.size();i++)
    {
        cout << "\nSemester "
             << i+1
             << endl;

        cout << "--------------------------------\n";

        for(int j = 0; j < semesters[i].courses.size(); j++)
{
    cout << setw(12)
         << left
         << semesters[i].courses[j].name
         << " Credits: "
         << semesters[i].courses[j].creditHour
         << " Grade: "
         << semesters[i].courses[j].gradePoint
         << endl;
}

        cout << "Semester GPA = "
             << fixed
             << setprecision(2)
             << semesters[i].GPA
             << endl;
    }

    int credits;

    cout << "\nOverall CGPA = "
         << fixed
         << setprecision(2)
         << calculateCGPA(credits)
         << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n Automated Semester CGPA Planner";
        cout << "\n==============================";

        cout << "\n1. Add Semester";
        cout << "\n2. View Semester GPAs";
        cout << "\n3. View Overall CGPA";
        cout << "\n4. Predict Required GPA";
        cout << "\n5. Display Complete Record";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addSemester();
                break;

            case 2:
                displaySemesterGPAs();
                break;

            case 3:
                displayCGPA();
                break;

            case 4:
                predictGPA();
                break;

            case 5:
                displayAll();
                break;

            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice.\n";
        }

    }while(choice!=6);

    return 0;
}
