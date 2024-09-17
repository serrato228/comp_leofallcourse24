// GradeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>


int main()
{
    //Obtains name input
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
   


    int lab1Grade;
    int lab2Grade;
    int lab3Grade;
    int lab4Grade;
    double numberOfLabs = 4;
    std::cout << "Please enter lab 1: ";
    std::cin >> lab1Grade;
    std::cout << "Please enter lab 2: ";
    std::cin >> lab2Grade;
    std::cout << "Please enter lab 3: ";
    std::cin >> lab3Grade;
    std::cout << "Please enter lab 4: ";
    std::cin >> lab4Grade;
    double labsAverage = ((lab1Grade + lab2Grade + lab3Grade + lab4Grade) / numberOfLabs);

    int exam1Grade;
    int exam2Grade;
    int exam3Grade;
    double numberOfExams = 3;
    std::cout << "Please enter exam 1: ";
    std::cin >> exam1Grade;
    std::cout << "Please enter exam 2: ";
    std::cin >> exam2Grade;
    std::cout << "Please enter exam 3: ";
    std::cin >> exam3Grade;
    double examsAverage = ((exam1Grade + exam2Grade + exam3Grade) / numberOfExams); 

    std::cout << (name) << ", your lab grades are: " << std::endl;
    std::cout << "Lab 1 = " << (lab1Grade) << std::endl;
    std::cout << "Lab 2 = " << (lab2Grade) << std::endl;
    std::cout << "Lab 3 = " << (lab3Grade) << std::endl;
    std::cout << "Lab 4 = " << (lab4Grade) << std::endl;

    std::cout << (name) << ", your exam grades are: " << std::endl;
    std::cout << "Exam 1 = " << (exam1Grade) << std::endl;
    std::cout << "Exam 2 = " << (exam2Grade) << std::endl;
    std::cout << "Exam 3 = " << (exam3Grade) << std::endl;

    std::cout << (name) << ", your class grade is: " << std::endl;
    std::cout << "Lab's Average (65%) = " << (labsAverage) << std::endl;
    std::cout << "Exam's Average (20%) = " << (examsAverage) << std::endl;
    
    double percentageLabs = 0.75
        //double classAverage = ((labsAverage * percentageLabs) + (examsAverage * percentageExams));
}
