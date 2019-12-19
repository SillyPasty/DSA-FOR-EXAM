#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

stack<char> s;
vector<char> result;
vector<char> infixToPostfix(char *str);
// void calPostfix(vector<char> result);

int main()
{
    char str[30];
    cin >> str;
    vector<char> a = infixToPostfix(str);
    cout << endl;
    //calPostfix(a);
    system("pause");
    return 0;
}

vector<char> infixToPostfix(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (s.empty() && (str[i] == '+' || str[i] == '-' || 
            str[i] == '*' || str[i] == '/'))
            s.push(str[i]);
        else if (str[i] == '+' || str[i] == '-')
        {
            while(!(s.empty()) && s.top() != '(')
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (s.top() != '(')
            {
                result.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == '*' || str[i] == '/')
        {
            if(s.top() == '*' || s.top() == '/')
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
        else
            result.push_back(str[i]);
    }
    while(!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    for (vector<char>::iterator iter = result.begin(); iter != result.end(); iter++)
        cout << (*iter);
    return result;
}

// void calPostfix(vector<char> result)
// {
//     stack<char> s2;
//     for(vector<char>::iterator iter = result.begin(); iter != result.end(); iter++)
//     {
//         if(*iter == '+' || *iter == '-' || *iter == '*' || *iter == '/')
//         {
//             char a = s2.top();
//             s2.pop();
//             char b = s2.top();
//             s2.pop();
            
//         }
//         else
//             s2.push(*iter);
//     }
// }