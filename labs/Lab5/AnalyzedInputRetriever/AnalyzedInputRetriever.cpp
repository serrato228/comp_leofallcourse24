/*
Lab 5
Leonardo Serrato
COSC 1436 Fall 2024
*/

#include <iostream>
#include <string>

using namespace std;

// Struct to represent a node in the linked list (copied and pasted from lab 5)
struct Node
{
    int Value = 0;
    Node* Next = nullptr;
};

// Struct to represent the linked list (copied and pasted from lab 5 as well)
struct LinkedList
{
    Node* Head = nullptr;
};

void displayProgramInfo() 
{
    cout << "Lab 5: Analyzed Input Retriever" << endl;
    cout << "Leonardo Serrato" << endl;
    cout << "Course: COSC 1436 Fall 2024" << endl << endl;
}

void displayMenu()
{
    cout << "Main Menu" << endl;
    cout << "--------------------" << endl;
    cout << "L) ist" << endl;
    cout << "A) dd" << endl;
    cout << "D) elete" << endl;
    cout << "C) lear" << endl;
    cout << "Q) uit" << endl;
    cout << "? ";
}

char getValidatedMenuChoice() 
{
    char choice;
    while (true)
    {
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'L' || choice == 'A' || choice == 'D' || choice == 'C' || choice == 'Q') 
        {
            break;
        }
        cout << "Invalid choice. Please enter L, A, D, C, or Q: ";          //This ensures valid input is obtained, letters that hold purpose in the code
    }
    return choice;
}

void addValueToList(LinkedList& list) 
{
    int value;
    cout << "Enter the integral value to add: ";
    cin >> value;

    Node* newNode = new Node();
    newNode->Value = value;                 //I utilized google to help me complete this segment since I still dont understand nodes very well, I searched up "nodes C++" and later "newNode C++"

    if (list.Head == nullptr)    //I will put many comments here since they will be more questions that actual explanations. For this part, the if statement checks if list.Head (starts at "Head" note) is equal to no further nodes, or no nodes
    {
        list.Head = newNode;      //If so, then newNode creates a new node
    } else {
        Node* current = list.Head;          //If there are nodes prior to choosing to add values to the list, then the new nodes will be created after the last node and before the nullptr valued node
        while (current->Next != nullptr) 
        {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void listValues(const LinkedList& list) 
{
    if (list.Head == nullptr) 
    {
        cout << "The list is empty." << endl;       //This is shown if user inputted L first prior to A, or if user cleared the list and then inputted L
    } else {
        Node* current = list.Head;
        while (current != nullptr) 
        {
            cout << current->Value << endl;
            current = current->Next;
        }
    }
}

void removeValueFromList(LinkedList& list) 
{
    int value;
    cout << "Enter the integral value to remove: ";
    cin >> value;

    Node* previous = nullptr;
    Node* current = list.Head;

    while (current != nullptr)          //this ensures there is a value to be deleted, meaning that there is more than zero nodes
    {
        if (current->Value == value) 
        {
            if (previous == nullptr) 
            {
                list.Head = current->Next;          //to my understanding, this list/nodes work in a similar manner to how you described the compiler moving from value to value till a value equals another value, the only difference is that it is nodes
            } else {
                previous->Next = current->Next;
            }
            delete current;
            cout << "Value removed." << endl;
            return;
        }
        previous = current;
        current = current->Next;
    }
    cout << "Value not found in the list." << endl;
}

void clearList(LinkedList& list) 
{
    cout << "Are you sure you want to clear the list? (Y/N): ";
    char confirm;
    cin >> confirm;
    confirm = toupper(confirm);

    if (confirm == 'Y') 
    {
        Node* current = list.Head;
        while (current != nullptr) 
        {
            Node* next = current->Next;
            delete current;
            current = next;
        }
        list.Head = nullptr;
        cout << "The list has been cleared." << endl;
    } else {
        cout << "Clear operation canceled." << endl;
    }
}

// Main function
int main() 
{
    displayProgramInfo();
    LinkedList list;
    char choice;

    do {
        displayMenu();
        choice = getValidatedMenuChoice();

        switch (choice) {
            case 'L':
                listValues(list);
                break;
            case 'A':
                addValueToList(list);
                break;
            case 'D':
                removeValueFromList(list);
                break;
            case 'C':
                clearList(list);
                break;
            case 'Q':
                cout << "Goodbye!" << endl;
                break;
        }
    } while (choice != 'Q');
}


