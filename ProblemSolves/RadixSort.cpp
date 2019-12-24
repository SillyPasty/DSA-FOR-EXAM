#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

void radixSort(int arg[], int a, int len);
int getMax(int arg[], int len);
// 17,5,12,21,143,56,
// 1
int main()
{
    char s[50];
    int len = 0, tmp = 0, a;
    int arg[21];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ',')
        {
            arg[len++] = tmp;
            tmp = 0;
        }
        else
            tmp = 10 * tmp + int(s[i] - '0');
    }
    cin >> a;
    radixSort(arg, a - 1, len);
    system("pause");
    return 0;
}

void radixSort(int arg[], int a, int len)
{
    int flg = 0, cnt = 10;
    int ind[10] = {0};
    int bucket[10][21] = {0};
    int max = getMax(arg, len);
    int tms = 0;
    while (tms < max)
    {
        flg = 0;
        for (int i = 0; i < len; i++)
        {

            int m = arg[i] % cnt / (cnt / 10);
            bucket[m][ind[m]++] = arg[i];
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < ind[i]; j++)
                arg[flg++] = bucket[i][j];
            ind[i] = 0;
        }
        cnt *= 10;
        if (tms == a)
            for (int i = 0; i < len; i++)
                cout << arg[i] << ',';
        tms++;
    }
}

int getMax(int arg[], int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        int cnt = 1, tes = 10;
        while (arg[i] / tes)
        {
            tes *= 10;
            cnt++;
        }
        max = max < cnt ? cnt : max;
    }
    return max;
}