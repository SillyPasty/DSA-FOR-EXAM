#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

void getNextArray();
void kmp();
char mainStr[20] = {0};
char subStr[20] = {0};
int nextArray[20];

int main()
{
    cin >> mainStr;
    cin >> subStr;
    getNextArray();
    for (int i = 0; i < strlen(subStr); i++)
        cout << nextArray[i] << ' ';
    cout << endl;
    kmp();
    system("pause");
    return 0;
}

void getNextArray()
{
    nextArray[0] = 0;
    int i = 0, j = 1;
    while (j < strlen(subStr))
    {
        if (i == 0 || subStr[j - 1] == subStr[i - 1])
        {
            i++;
            nextArray[j] = i;
            j++;
        }
        else
            i = nextArray[i - 1];
    }
}

void kmp()
{
    int mainF = 0, subF = 0;
    while (mainF < strlen(mainStr))
    {
        if (subF == 0 && mainStr[mainF] != subStr[subF])
            mainF++;
        else if (mainStr[mainF] == subStr[subF])
        {
            mainF++;
            subF++;
        }
        else
            subF = nextArray[subF] - 1;
        if (subF == strlen(subStr))
        {
            cout << mainF - strlen(subStr) << ',';
            subF = 0;
        }
    }
}