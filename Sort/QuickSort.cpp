/* A type of Exchange Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

void quickSort(int a[], int left, int right);
int mid3(int a[], int left, int right);

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
    quickSort(args, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << args[i] << ' ';
    system("pause");
    return 0;
}

void quickSort(int a[], int left, int right)
{
    if (right <= left)
        return;
    int pivot = mid3(a, left, right);
    int l = left, r = right - 1;
    while (l < r)
    {
        while (a[++l] < pivot)
            ;
        while (pivot < a[--r])
            ;
        if(l < r)
            swap(a[l], a[r]);
    }
    swap(a[l], a[right - 1]);
    quickSort(a, left, l - 1);
    quickSort(a, l + 1, right);
}

int mid3(int a[], int left, int right)
{
    int mid = (left + right) / 2;
    if (a[mid] < a[left])
        swap(a[mid], a[left]);
    if (a[right] < a[left])
        swap(a[right], a[left]);
    if (a[right] < a[mid])
        swap(a[right], a[mid]);
    swap(a[mid], a[right - 1]);
    return a[right - 1];
}