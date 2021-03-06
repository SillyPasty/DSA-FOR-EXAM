/* A type of Selection Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(int a[], int len);

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
    selectionSort(args, len);
    system("pause");
    return 0;
}

void selectionSort(int a[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        int flg = i;
        for(int j = i; j < len; j++)
            if(a[j] < a[flg])
                flg = j;
        swap(a[i], a[flg]);
    }
    for(int i = 0; i < len; i++)
        cout << a[i] << ' ';
}