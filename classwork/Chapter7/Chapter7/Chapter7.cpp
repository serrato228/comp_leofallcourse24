#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    Point topLeft;
    Point bottomRight;
};

void Display(Point point)
{
    cout << "(" << point.x << "," << point.y << ")";
};

void Display(Rectangle rect)
{
    //cout << "(" << rect.topLeft.x << "," << rect.topLeft.y << ")";
    cout << "(";
    Display(rect.topLeft);
    cout << " ";
    Display(rect.bottomRight);
    cout << ")" << endl;
};

void Translate(Rectangle& rect, int offsetX, int offsetY)
{
    rect.topLeft.x += offsetX;
    rect.bottomRight.x += offsetX;

    rect.topLeft.y += offsetY;
    rect.bottomRight.y += offsetY;
};

void TestPassReference()
{
    Rectangle rc;
    rc.topLeft.x = 10;
    rc.topLeft.y = 20;

    rc.bottomRight.x = 100;
    rc.bottomRight.y = 75;

    Translate(rc, 5, 10);
    Display(rc);
}

void GradeArrayDemo()
{
    const int MaxGrades = 20;
    double dummyValue2 = -1;
    int grades[MaxGrades];
    double dummyValue = 0;

    int estimatedMaxArraySize = //Size of array / size of element
        sizeof(grades) / sizeof(int);
    int count = 0;
    for (int index = 0; index < MaxGrades; ++index)//, ++count)
    {
        cout << "Enter a grade: ";
        cin >> grades[index];
        //grades[index] = 100;

        if (grades[index] <= 0)
            break;

        ++count;
    };

    //for (int index = 0; index < MaxGrades; ++index) for entire array
    for (int index = 0; index < count; ++index)                                 //will possibly come in handy for lab 4. take notice of this code as it will come in useful
    {
        cout << grades[index] << endl;
    };

    int indexToChange;
    do
    {
        cout << "Enter the index of the grade to change: ";
        cin >> indexToChange;
    } while (indexToChange < 0 || indexToChange >= MaxGrades);

    int newGrade;
    cout << "Enter the new grade: ";
    cin >> newGrade;

    grades[indexToChange] = newGrade;

}

void InitArrayDemo()
{
    const int MaxRates = 100;
    double payRates[MaxRates] = {0};    //Zero initialize

    //// Zero init
    //for (int index = 0; index < MaxRates; ++index)                    the code in line 101 - 102 can replace this one
    //    payRates[index] = 0;
}

int main()
{
    InitArrayDemo();
}

void NameArrayDemo()
{
    //Array is a set of related data
    /*string student1;
    string student2;
    string student3;
    string student4;
    string student5;*/
    const int MaxStudents = 100;
    string students[MaxStudents];

    //All elements are exact same  type
    /* int grades[10];
    grades[0] = 10;
    grades[1] = (short)10;*/

    //Store roster of students
    //When using for loop use - 0 to < N
    for (int index = 0; index < MaxStudents; ++index)
    {
        string student;
        cout << "Enter student name: ";
        getline(cin, student);
        if (student == "")
            break;

        // student at index 0, first element
        // student sub 0
        // Array access operator
        students[index] = student;
    };

    //Print roster
    for (int index = 0; index < MaxStudents; ++index)
    {
        if (students[index] != "")
            cout << students[index] << endl;
    };
}