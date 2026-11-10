
#include <iostream>
#include <cctype>
using namespace std;

int mystrlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

char* mystrcpy(char* str1, const char* str2)
{
    int i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return str1;
}

char* mystrcat(char* str1, const char* str2)
{
    int i = mystrlen(str1);
    int j = 0;

    while (str2[j] != '\0')
        str1[i++] = str2[j++];

    str1[i] = '\0';
    return str1;
}

char* mystrchr(char* str, char symbol)
{
    for (int i = 0; ; i++)
    {
        if (str[i] == symbol)
            return str + i;

        if (str[i] == '\0')
            return nullptr;
    }
}

char* mystrstr(char* str1, char* str2)
{
    if (str2[0] == '\0')
        return str1;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        int j = 0;

        while (str1[i + j] != '\0' &&
            str2[j] != '\0' &&
            str1[i + j] == str2[j])
        {
            j++;
        }

        if (str2[j] == '\0')
            return str1 + i;
    }

    return nullptr;
}

void ReplaceSpaces(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            str[i] = '\t';
    }
}

void CountCharacters(const char* str, int& letters, int& digits, int& others)
{
    letters = 0;
    digits = 0;
    others = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = static_cast<unsigned char>(str[i]);

        if (isalpha(ch))
            letters++;
        else if (isdigit(ch))
            digits++;
        else
            others++;
    }
}

int CountWords(const char* str)
{
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = static_cast<unsigned char>(str[i]);

        if (isspace(ch))
        {
            inWord = false;
        }
        else if (!inWord)
        {
            count++;
            inWord = true;
        }
    }

    return count;
}

bool IsPalindrome(const char* str)
{
    int left = 0;
    int right = mystrlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    char str[256];

    cout << "Enter string: ";
    cin.getline(str, 256);

    // Task 1
    char modified[256];
    mystrcpy(modified, str);
    ReplaceSpaces(modified);

    cout << "With tabs: " << modified << '\n';

    // Task 2
    int letters, digits, others;
    CountCharacters(str, letters, digits, others);

    cout << "Letters: " << letters << '\n';
    cout << "Digits: " << digits << '\n';
    cout << "Other symbols: " << others << '\n';

    // Task 3
    cout << "Words: " << CountWords(str) << '\n';

    // Task 4
    if (IsPalindrome(str))
        cout << "Palindrome\n";
    else
        cout << "Not palindrome\n";

    // Task 5
    char buffer[512];
    mystrcpy(buffer, str);

    cout << "Length: " << mystrlen(buffer) << '\n';
    cout << "Copied: " << buffer << '\n';

    mystrcat(buffer, " example");
    cout << "Concatenated: " << buffer << '\n';

    char* foundChar = mystrchr(buffer, 'a');
    if (foundChar != nullptr)
        cout << "Character index: " << foundChar - buffer << '\n';
    else
        cout << "Character not found\n";

    char substring[] = "example";
    char* foundSubstring = mystrstr(buffer, substring);

    if (foundSubstring != nullptr)
        cout << "Substring index: " << foundSubstring - buffer << '\n';
    else
        cout << "Substring not found\n";
}
