#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>   //Char type functions from C

using namespace std;

//Character sets - maps nmeric values to characters
// ASCII (7-bit) 0-127 (char)
// ANSI (1 byte) 0-255 (char)
// MBCS (1-4 bytes, multi-byte character set) - for localization (Char)
// Each byte has to be examined to determine if subsequent bytes are needed for full char
// Unicode (2, bytes, Windows, or 4 bytes) - all languages in world (wchar_t)

bool IsIdentifier(char input)
{
    return isalnum(input) || input == '-';
};

bool IsIntegral(string const& value)
{
    //for (int index = 0; index < value.length(); ++index)
    for (char ch : value)
        if (!isdigit(ch))
            return false;

    return true;
};

bool IsValidIdentifier(string const& value)
{
    for (char ch: value)
        if (!isalnum(ch) && ch != '_')
            return false;

    return true;
};

void StringDemo()
{
    while (true)
    {
        string input;
        cout << "Enter a value: ";
        getline(cin, input);

        cout << "Integer = " << IsIntegral(input) << endl;
        cout << "Identifier = " << IsValidIdentifier(input) << endl;
    };
}

void CharDemo()
{
    while (true)
    {
        char input;
        cout << "Enter a character: ";
        cin >> input;

        //Classification ::= int func ( int )
        //
        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        cout << "Alpha = " << (isalpha(input) ? 'Y' : 'N') << endl; //Letter
        cout << "Digit = " << (isdigit(input) ? 'Y' : 'N') << endl; //Digit
        cout << "Letter/Digit = " << (isalnum(input) ? 'Y' : 'N') << endl; //Letter or Digit
        cout << "Lower = " << (islower(input) ? 'Y' : 'N') << endl; //Lower case letter
        cout << "Upper = " << (isupper(input) ? 'Y' : 'N') << endl; //Upper case letter
        cout << "Space = " << (isspace(input) ? 'Y' : 'N') << endl; //Space
        cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << endl; //Digit

        //Conversion ::= int func ( int )
        cout << "Lower = " << tolower(input) << endl;   //Convert to lower case
        cout << "Upper = " << toupper(input) << endl;   //Convert to upper case
    };
}

void WideCharDemo()
{
    while (true)
    {
        wchar_t input;
        cout << "Enter a character: ";
        wcin >> input;

        //Classification ::= int func ( int )
        //
        // isalpha - true if letter, false otherwise
        // isdigit - true if digit, false otherwise
        cout << "Alpha = " << (isalpha(input) ? 'Y' : 'N') << endl; //Letter
        cout << "Digit = " << (isdigit(input) ? 'Y' : 'N') << endl; //Digit
        cout << "Letter/Digit = " << (isalnum(input) ? 'Y' : 'N') << endl; //Letter or Digit
        cout << "Lower = " << (islower(input) ? 'Y' : 'N') << endl; //Lower case letter
        cout << "Upper = " << (isupper(input) ? 'Y' : 'N') << endl; //Upper case letter
        cout << "Space = " << (isspace(input) ? 'Y' : 'N') << endl; //Space
        //cout << "Id = " << (IsIdentifier(input) ? 'Y' : 'N') << endl; //Digit

        //Conversion ::= int func ( int )
        cout << "Lower = " << towlower(input) << endl;   //Convert to lower case
        cout << "Upper = " << towupper(input) << endl;   //Convert to upper case
    };
}

int main()
{
    //CharDemo();
    WideCharDemo();
    //StringDemo();
}

