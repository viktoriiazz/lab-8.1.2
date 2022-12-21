#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 4)
        return 0;

    if (str[i + 3] != 0)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
            return 1 + Count(str, i + 3);

        return Count(str, i + 1);
    }

    return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 3] != 0)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 4);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str, 1) << " groups of 4 same characters" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}