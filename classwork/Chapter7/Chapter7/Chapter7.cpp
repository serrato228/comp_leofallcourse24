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

int main()
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