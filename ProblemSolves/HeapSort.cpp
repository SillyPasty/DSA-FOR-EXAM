#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void heapAdj(int a[], int cur, int len);
void heapSort(int a[], int len, int tim);
// 31,41,59,26,53,58,97,-1
int main()
{
    int tm, cnt = 0, tem = 0;
    char str[200];
    int arg[200];
    cin >> str;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != ',')
            tem = tem * 10 + int(str[i] - '0');
        else
        {
            arg[cnt] = tem;
            tem = 0;
            cnt++;
        }
    }
    cin >> tm;
    heapSort(arg, cnt, tm);
    //system("pause");
    return 0;
}

void heapAdj(int a[], int cur, int len)
{
    int tem = a[cur];
    for (int i = cur * 2 + 1; i < len; i = i * 2 + 1)
    {
        if (i + 1 < len && a[i] < a[i + 1])
            i++;
        if (tem < a[i])
        {
            a[cur] = a[i];
            cur = i;
        }
        else
            break;
    }
    a[cur] = tem;
}

void heapSort(int a[], int len, int tim)
{
    int cnt = 2;
    for (int i = len / 2 - 1; i >= 0; i--)
        heapAdj(a, i, len);
    if (tim == 1)
    {
        for (int j = 0; j < len; j++)
            cout << a[j] << ',';
        cout << endl;
    }
    for (int i = len - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapAdj(a, 0, i);
        if (tim == cnt)
        {
            for (int j = 0; j < len; j++)
                cout << a[j] << ',';
            cout << endl;
        }
        cnt++;
    }
}