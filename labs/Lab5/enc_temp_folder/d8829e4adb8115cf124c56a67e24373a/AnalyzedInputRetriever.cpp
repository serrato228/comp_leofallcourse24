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
        cout << "Invalid choice. Please enter L, A, D, C, or Q: ";
    }
    return choice;
}

void addValueToList(LinkedList& list) 
{
    cout << "Enter the integral value to add: ";
    int value;
    cin >> value;

    Node* newNode = new Node();
    newNode->Value = value;

    if (list.Head == nullptr) 
    {
        list.Head = newNode;
    } else {
        Node* current = list.Head;
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
        cout << "The list is empty." << endl;
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
    cout << "Enter the integral value to remove: ";
    int value;
    cin >> value;

    Node* previous = nullptr;
    Node* current = list.Head;

    while (current != nullptr) 
    {
        if (current->Value == value) 
        {
            if (previous == nullptr) 
            {
                list.Head = current->Next;
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


