#include <iostream>

using namespace std;

// N! -1 * 2 * 3 * ... * N
//int Factorial( int number )
//{
//    int result = 1;
//
//    for (int index = 0; index < number; ++index)
//        result *= (index + 1);
//
//    return result;
//}
//
//int Factorial2(int number)
//{
//    if (number <= 1)
//        return 1;
//
//    return number * Factorial2(number - 1);
//}

void PrefixPostfixDemo()
{
    int value;
    cout << "Enter a value: ";
    cin >> value;

    // prefix inc := ++X => X = X + 1; X
    // prefix dec := --X => X = X - 1; X

    cout << value++ << " ";
    cout << ++value << " ";
    cout << value-- << " ";
    cout << --value << " " << endl;

}

//void DisplayTruthTable()
//{
//    cout << " A " << " B " << " && " << " || " << endl;
//
//    //False, False
//    //False, True
//    //True, False
//    //True, True
//    //Conditional ::+ Eb ? Et : Ef
//    cout << false << false << (false && false) < (false || false) << endl;
//    cout << false << true << (false && true) < (false || true) << endl;
//    cout << true << false << (true && false) < (true || false) << endl;
//    cout << true << true << (true && true) < (true || true) << endl;
//}
bool isDigit(char value)
{
    switch (value)
    {
        case '0':
        case '1':
        case '2':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': return true;
    };
    return false;
};
bool isLetter(char value)
{
    if ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z'))
    return true;

    return false;
};
string GetCharacterClass(char value)
{
    //Identify the char
    // a..Z = letter
    // 0..0 = digit
    // * = symbol
    if (isDigit(value))
        return "Digit";
    else if (isLetter(value))
        return "Letter";
    else
        return "Symbol";
}

void SwitchDemo()
{
    do
    {
        char input;
        cout << "Enter a character: ";
        cin >> input;

        cout << GetCharacterClass(input) << endl;
    } while (true);
}

int main()
{
    /*cout << Factorial(3) << " " << Factorial2(3) << endl;
    cout << Factorial(1) << " " << Factorial2(1) << endl;
    cout << Factorial(5) << " " << Factorial2(5) << endl;*/
    //DisplayTruthTable();
    //PrefixPostfixDemo();
    SwitchDemo();
}
