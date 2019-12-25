/* 
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

void radixSort(int a[], int len);
int getMax(int a[], int len);

int main()
{
    srand((unsigned)time(NULL));
    int len = 20;
    int args[len];
    for (int i = 0; i < len; i++)
        args[i] = rand();
    for (int i = 0; i < len; i++)
        cout << args[i] << ' ';
    cout << endl;
    radixSort(args, len);
    for (int i = 0; i < len; i++)
        cout << args[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}

void radixSort(int a[], int len)
{
    int id = 10, flg = 0, cnt = 0;
    int bucket[10][20] = {0};
    int idx[10] = {0};
    int max = getMax(a, len);
    while (cnt < max)
    {
        for (int i = 0; i < len; i++)
        {
            int m = (a[i] % id) / (id / 10);
            bucket[m][idx[m]++] = a[i];
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < idx[i]; j++)
                a[flg++] = bucket[i][j];
            idx[i] = 0;
        }
        id *= 10;
        flg = 0;
        cnt++;
    }
}

int getMax(int a[], int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        int cnt = 1, tes = 10;
        while (a[i] / tes)
        {
            tes *= 10;
            cnt++;
        }
        max = max < cnt ? cnt : max;
    }
    return max;
}