/* A type of Exchange Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

void bubbleSort(int a[], int len);

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
    bubbleSort(args, len);
    system("pause");
    return 0;
}

void bubbleSort(int a[], int len)
{
    for(int i = len - 1; 0 < i; i--)
        for(int j = 0; j < i; j++)
            if(a[j + 1] < a[j])
                swap(a[j + 1], a[j]);
    for(int i = 0; i < len; i++)
        cout << a[i] << ' ';
}
