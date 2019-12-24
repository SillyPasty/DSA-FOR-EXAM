/* A type of Inserting Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort(int a[], int len);

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
    insertionSort(args, len);
    system("pause");
    return 0;
}

void insertionSort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int j, cur = a[i];
        for (j = i; 0 < j && cur < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = cur;
    }
    for (int i = 0; i < len; i++)
        cout << a[i] << ' ';
}