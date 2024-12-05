#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//pointer - memory adds

void StackDemo()
{
    double localDouble = 45.6;

    //Declares a pointer to a double
    // Pointer is always a memory address
    // Pointer is always eitehr 4 or 8 bytes long
    // Pointer values is always an integral value
    
    // Pointers have 2 data points: value (memory address), value they reference (in memory)
    // address-of :: & variable
    //      Type of expression is T* where T is the type of the variable
    double* ptrDouble = &localDouble; //pointer to double

    //Assign new value to value at memory address
    *ptrDouble = 89.7;

    //Type coercion doesn't behave the same with pointers
    int localInt = 56;
    localDouble = localInt;
    //ptrDouble = &localInt; not allowed

    // double* != double
    //   ptrDouble = 90.6;

    // Dereferencing a pointer
    //  deference-op :: 8E
    //      Type of expression is T where E is T*
    cout << ptrDouble << " " << *ptrDouble << endl;
    cout << (*ptrDouble == localDouble) << endl;
};

void EmptyDemo()
{
    float payRate = 12.50;

    // Always init to 0 or valid memory
    //float* pPayRate = NULL;       // C, old school, not recommended
    float* pPayRate = nullptr;      // C++m recommended

    //Print value and dereferenced value
    cout << pPayRate << " = ";

    //Always verify pointer before dereferencing
    //      if (pPayRate != nullptr)
    //      if (ptr != NULL)    //not recommended
    //      if (ptr)
    //if (pPayRate != nullptr)
    if (pPayRate)
        cout << *pPayRate;
    cout << endl;
};

struct Employee
{
    int Id;
    string Name;

    int DummyValues[1000];
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    Employee* employees[MaxEmployees] = {0};
    int id = 1000;

    //int numberOfEmployees = 0;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        string name;
        cout << "Enter name or empty to quit: ";
        getline(cin, name);

        if (name == "")
            break;

        //Add to array
        // new-op ::    new T; returns T*

        Employee* employee = new Employee;
        //(*employee).Id = ++id;
        employee->Id = ++id;
        employee->Name = name;
        employees[index] = employee;
        //++numberOfEmployees;
    };

    //Print employees
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;

        cout << "[" << employees[index]->Id << "]" << employees[index]->Name << endl;
    };

    // Ensure that any memory allocate by new is cleanred up using delete
    //  delete-op ::= delete E;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;

        //Delete the memory
        Employee* employee = employees[index];
        delete employee;
        employees[index] = nullptr; //Always reset to null to avoid issues
        delete employees[index];    //This works
        //employee->Id = 20;  //Going to fail

        //delete &index;  //Bad things will happen
    };
}

// Pointers can be passed as parameters
//void DisplayIntArray(int arr[], int size)
void DisplayIntArray(int* arr, int size)
{
    for (int index = 0; index < 100; ++index)
        cout << arr[index] << " ";
    cout << endl;
};

void ArrayPointerDemo()
{
    int values[100];

    // Array variables are pointers
    int* ptrValues = values;

    for (int index = 0; index < 100; ++index)
    {
        //Pointer arithmetic
        // Addition/subtraction
        // Value is always multiplied by sizeof(T) so you are referencing a whole element
        //arr[index] = arr + index = arr + (sizeof(T) * index)
        // arr[index] = *(arr + index)
        *(ptrValues + index) = index + 1;
        //*ptrValues + index = index + 1;               //this is not valid as the parenthesis matter
    };
    /*for (int index = 0; index < 100; ++index)
        values[index] = index + 1;*/

    DisplayIntArray(ptrValues, 100);

    int localVariable = 100;
    DisplayIntArray(&localVariable, 1);
}

void NewArrayDemo()
{
    //double arr[100]

    //Dynamically allocate array at runtime
    int size;
    cout << "How many elements: ";
    cin >> size;

    //Array decl won't work at runtime
    // new T[size]
    //  Size must be integral and > 0
    // Ensure you delete this when done
    double* arr = new double[size];

    //Arrays and pointers are interchangeable so nothing else changes
    for (int index = 0; index < size; ++index)
    {
        cout << "Enter a value: ";
        cin >> arr[index];

        if (arr[index] == 0)
            break;
    };

    //Cleanup
    delete arr;   // This is wrong by the way
    delete[] arr; // Required for arrays
};

void NewArrayDemo2()
{
    while (true)
    {
        NewArrayDemo();

        cout << "Keep going (Y/N)? ";

        char choice;
        cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    };
}

// Employee is pass by value (memory address), any changes to employee are visible to caller
void InitializeEmployeeByRef(int& employee)
{
    //No need to validate argument

    cout << "Enter the employee ID: ";
    //getline(cin, employee.Name);
    cin >> employee;
};

// Employee is pass by value (memory address)
// When dereferencing the pointer then any changes to value are visible to caller
void InitializeEmployeeByPtr(int* employee)
{
    //Validate pointer
    if (employee) //employee != nullptr || employee != NULL
    {
        //employee++;

        cout << "Enter the employee ID: ";
        //getline(cin, employee.Name);
        cin >> *employee;
    };
};

void PassByRefVsPointerDemo()
{
    //Employee employee;
    int employeeId;

    //Pass by ref - must pass a variable
    InitializeEmployeeByRef(employeeId);

    //Pass by value - must pass the address of variable
    InitializeEmployeeByPtr(&employeeId);

    InitializeEmployeeByPtr(nullptr);
};

Employee* CreateEmployee()
{
    Employee* ptrEmployee = new Employee();

    return ptrEmployee;
}

int* FindElement(int values[], int size, int desiredValue)
{
    for (int index = 0; index < size; ++index)
    {
        if (values[index] == desiredValue)
            return &values[index];
    };

    return nullptr;
}

double g_SomeVariable = 9.18175;

double* GetConstant()
{
    return &g_SomeVariable;
}

// Never do this because it doesn't work
double* DontDoThis()
{
    double someValue = 1.2914;

    return &someValue;
}

void PointerReturnDemo()
{
    // Pointer as return type
    //  New instance from function (caller is responsible for lifetime)
    //  RAII - Resource Acquisition is Initialization
    Employee* pNewEmployee = CreateEmployee();
    delete pNewEmployee;

    // Pointer is to memory that the caller owns
    int values[100] = {0};
    values[50] = 20;
    int* pMatch = FindElement(values, 100, 20);

    // Pointer to global object
    double* pConstant = GetConstant();
}

// message is a reference to a constant string
// reference for perf reasons
// const string&
int ReadInt(string const& message)
{
    //Constant, cannot modify
    //message = "Broke";
    cout << message;

    int value;
    cin >> value;
    
    return value;
}

void ConstantPointersDemo()
{
    string message = "Enter a number: ";
    int value = ReadInt("Enter a number: ");

    // non-const vs const
    int nonConstValue = 10;
    const int constValue = 20;

    //Non-const are readable/writable
    nonConstValue = 20;

    //Const are read only
    //constValue = 30;

    //Pointer can be dereferenced to read/write
    int* pNonConst = &nonConstValue;
    *pNonConst = 40;

    // Can add const to something (non-const to const is allowed)
    // Cannot take away const from something (const to non-const is not allowed)
    //pNonConst = &constValue;
    *pNonConst = 50;

    int const* pConst = &constValue;
    pConst = &nonConstValue;

    nonConstValue = (int)45.6; //C-style
    nonConstValue = static_cast<int>(45.6); //C++ cast

    // const_cast<T> casts T to either const T or T depending on what it is
    pConst = const_cast<int*>(&nonConstValue);
    pNonConst = const_cast<int*>(&constValue);
    *pNonConst = 50;
}

int main()
{
    //StackDemo();
    //EmptyDemo();
    //DynamicMemoryDemo();
    //ArrayPointerDemo();
    //NewArrayDemo2();
    //PointerReturnDemo();
    ConstantPointersDemo();
}
