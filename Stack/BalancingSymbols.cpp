#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

stack<char> s;

int main()
{
    char str[20];
    bool flag = true;
    cin >> str;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else if (str[i] == s.top())
            s.pop();
        else if (str[i] != s.top())
            flag = false;
    printf("%d\n", flag ? "YES" : "NO");
    system("pause");
    return 0;
}