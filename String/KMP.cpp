#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int nextArray[100] = {0};

void getnextArray(char *str);
void kmp(char *sub_string, char *main_string);

int main()
{
    char sub_str[20];
    char main_str[20];
    cin >> sub_str;
    cin >> main_str;
    getnextArray(sub_str);
    for (int i = 0; i < strlen(sub_str); i++)
        cout << nextArray[i];
    cout << endl;
    kmp(sub_str, main_str);
    system("pause");
    return 0;
}

void getnextArray(char *str)
{
    // Create next array
    for (int i = 0; i < strlen(str); i++)
        if (i == 0)
            nextArray[i] = -1;
        else if (str[nextArray[i - 1]] == str[i - 1])
            nextArray[i] = nextArray[i - 1] + 1;
        else
            nextArray[i] = 0;
}

void kmp(char *sub_string, char *main_string)
{
    // Use KMMMMP
    int flag = 0;
    while (flag + strlen(sub_string) <= strlen(main_string))
    {
        for (int i = 0; i < strlen(sub_string); i++)
            if (sub_string[i] != main_string[flag + i])
            {
                flag += (i - nextArray[i]);
                break;
            }
            else if (i == (strlen(sub_string) - 1) &&
                     sub_string[i] == main_string[flag + i])
            {
                flag += 1;
                cout << flag;
            }
    }
}