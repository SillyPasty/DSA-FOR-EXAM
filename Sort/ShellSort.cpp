/* A type of Inserting Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

void shellSort(int a[], int len);

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
    shellSort(args, len);
    system("pause");
    return 0;
}

void shellSort(int a[], int len)
{
    int h = len / 2;
    while (h)
    {
        for (int i = h; i < len; i++)
        {
            int j, cur = a[i];
            for (j = i; h <= j && cur < a[j - h]; j -= h)
                a[j] = a[j - h];
            a[j] = cur;
        }
        h /= 2;
    }
    for (int i = 0; i < len; i++)
        cout << a[i] << ' ';
}