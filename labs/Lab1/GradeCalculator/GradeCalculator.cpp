#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>




using namespace std;

int main()
{
    cout << "Lab 1 --- Leo Serrato --- COSC 1436 Fall 2024" << endl;
    cout << endl;

    //Obtains name
    string name;
    cout << "Please enter your name: ";
    getline(cin, name);

    //Obtains Lab Grades
    int lab1Grade;
    int lab2Grade;
    int lab3Grade;
    int lab4Grade;
    double numberOfLabs = 4; //by dividing ints by a double, I can maintain the desired precision decimals
    cout << "Please enter lab 1: ";
    cin >> lab1Grade;
    cout << "Please enter lab 2: ";
    cin >> lab2Grade;
    cout << "Please enter lab 3: ";
    cin >> lab3Grade;
    cout << "Please enter lab 4: ";
    cin >> lab4Grade;
    double labsAverage = ((lab1Grade + lab2Grade + lab3Grade + lab4Grade) / numberOfLabs); // Finds the mean by adding lab grades and dividing by their amount of grades
    
    //Obtains Exam Grades
    int exam1Grade;
    int exam2Grade;
    int exam3Grade;
    double numberOfExams = 3; //same thing as what I did for labs
    cout << "Please enter exam 1: ";
    cin >> exam1Grade;
    cout << "Please enter exam 2: ";
    cin >> exam2Grade;
    cout << "Please enter exam 3: ";
    cin >> exam3Grade;
    double examsAverage = ((exam1Grade + exam2Grade + exam3Grade) / numberOfExams);

    //Obtains Participation Grade
    int participationGrade;
    cout << "Please enter participation: ";
    cin >> participationGrade;

    //Obtains Final Exam Grade
    int finalExam;
    cout << "Please enter final exam: ";
    cin >> finalExam;
    cout << endl; //this creates a space between my sections, it makes it easier to read and more similar to the sample provided

    // The user's name is displayed alongside his lab grades and his exam grades, after Story 6, the user's participation and final exam grade are also displayed
    cout << (name) << ", your lab grades are: " << endl;
    cout << "Lab 1 = " << (lab1Grade) << endl; //although the parenthesis aren't needed, I decided to use as shown in lines 57-72 as it allowed me to analyze and see my code and variables more clearly, I wont repeat this again, just did it because I didnt want to mess up on my first lab
    cout << "Lab 2 = " << (lab2Grade) << endl;
    cout << "Lab 3 = " << (lab3Grade) << endl;
    cout << "Lab 4 = " << (lab4Grade) << endl;
    cout << endl;

    cout << (name) << ", your exam grades are: " << endl;
    cout << "Exam 1 = " << (exam1Grade) << endl;
    cout << "Exam 2 = " << (exam2Grade) << endl;
    cout << "Exam 3 = " << (exam3Grade) << endl;
    cout << endl;
    
    cout << (name) << ", your other grades are: " << endl;
    cout << "Participation = " << (participationGrade) << endl;
    cout << "Final Exam = " << (finalExam) << endl;
    cout << endl;

    //these doubles are used to obtain the Class Average by having them multiplied against their respective averages and grades, these doubles' percentage values are aqcuired in Story 6
    double percentageLabs = 0.65;
    double percentageExams = 0.20;
    double percentageParticipation = 0.05;
    double percentageFinalExam = 0.10;
    cout << (name) << ", your class grade is: " << endl;
    cout << "Lab's Average (65%) = " << fixed << setprecision(2) << (labsAverage) << "%" << endl;
    cout << "Exam's Average (20%) = " << (examsAverage) << "%" << endl;
    cout << "Participation (5%) = " << (participationGrade) << "%" << endl;
    cout << "Final Exam (10%) = " << (finalExam) << "%" << endl;
    cout << "Class Average = " << ((labsAverage * percentageLabs) + (examsAverage * percentageExams) + (participationGrade * percentageParticipation) + (finalExam * percentageFinalExam)) << "%" << endl; // I was in between creating a Class Average variable and assigning it the value of the () to the left of the comment, however I decided to not since it is the same thing in this case
}