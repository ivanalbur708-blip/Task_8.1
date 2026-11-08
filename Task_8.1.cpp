#include <iostream>

using namespace std;

int MyStrLen(const char* string)
{
    int length = 0;
    while (string[length] != '\0') length++;
    return length;
}

char* MyStrCpy(char* destination, const char* source)
{
    int index = 0;
    do
    {
        destination[index] = source[index];
        index++;
    } while (source[index - 1] != '\0');
    return destination;
}

char* MyStrCat(char* destination, const char* source)
{
    int destinationLength = MyStrLen(destination);
    int sourceIndex = 0;
    do
    {
        destination[destinationLength + sourceIndex] = source[sourceIndex];
        sourceIndex++;
    } while (source[sourceIndex - 1] != '\0');
    return destination;
}

char* MyStrChr(char* string, char symbol)
{
    for (int i = 0; ; i++)
    {
        if (string[i] == symbol) return string + i;
        if (string[i] == '\0') return 0;
    }
}

char* MyStrStr(char* string, const char* substring)
{
    if (substring[0] == '\0') return string;

    for (int i = 0; string[i] != '\0'; i++)
    {
        int j = 0;
        while (substring[j] != '\0' && string[i + j] == substring[j]) j++;
        if (substring[j] == '\0') return string + i;
    }
    return 0;
}

bool IsLetter(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z');
}

bool IsDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int main()
{


    // Task 1
    {
        char text[256];
        cout << "Enter a line: ";
        cin.getline(text, 256);

        for (int i = 0; text[i] != '\0'; i++)
        {
            if (text[i] == ' ') text[i] = '\t';
        }
        cout << text << '\n';
    }

    // Task 2
    {
        char text[256];
        int letters = 0;
        int digits = 0;
        int other = 0;

        cout << "Enter a line: ";
        cin.getline(text, 256);

        for (int i = 0; text[i] != '\0'; i++)
        {
            if (IsLetter(text[i])) letters++;
            else if (IsDigit(text[i])) digits++;
            else other++;
        }

        cout << "Letters: " << letters << "\nDigits: " << digits
            << "\nOther: " << other << '\n';
    }

    // Task 3
    {
        char sentence[256];
        int wordCount = 0;
        bool insideWord = false;

        cout << "Enter a sentence: ";
        cin.getline(sentence, 256);

        for (int i = 0; sentence[i] != '\0'; i++)
        {
            if (sentence[i] != ' ' && sentence[i] != '\t')
            {
                if (!insideWord) wordCount++;
                insideWord = true;
            }
            else
            {
                insideWord = false;
            }
        }
        cout << "Words: " << wordCount << '\n';
    }

    // Task 4
    {
        char text[256];
        cout << "Enter a line: ";
        cin.getline(text, 256);

        int length = MyStrLen(text);
        bool palindrome = true;
        for (int i = 0; i < length / 2; i++)
        {
            if (text[i] != text[length - 1 - i]) palindrome = false;
        }
        cout << (palindrome ? "Palindrome\n" : "Not a palindrome\n");
    }

    // Task 5
    {
        char first[256] = "Hello";
        char second[256];

        MyStrCpy(second, first);
        MyStrCat(second, " world");

        cout << "Length: " << MyStrLen(second) << '\n';
        cout << "Copy and concatenation: " << second << '\n';

        char* symbolPosition = MyStrChr(second, 'w');
        char* substringPosition = MyStrStr(second, "world");
        cout << "Symbol position: " << (symbolPosition == 0 ? -1 : symbolPosition - second) << '\n';
        cout << "Substring position: " << (substringPosition == 0 ? -1 : substringPosition - second) << '\n';
    }
    return 0;
}