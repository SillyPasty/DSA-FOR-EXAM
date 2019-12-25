/* 
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mergeSort(int a[], int l, int r);
int len = 20;
int args[20];

int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++)
        args[i] = rand();
    for (int i = 0; i < len; i++)
        cout << args[i] << ' ';
    cout << endl;
    mergeSort(args, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << args[i] << ' ';
    cout << endl;
    system("pause");
    return 0;
}

void mergeSort(int a[], int l, int r)
{
    if (r <= l)
        return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    int tmp[100] = {0};
    int ind = 0, left = l, right = mid + 1;
    while (left <= mid && right <= r)
    {
        if (a[left] < a[right])
            tmp[ind++] = a[left++];
        else
            tmp[ind++] = a[right++];
    }
    while (left <= mid)
        tmp[ind++] = a[left++];
    while (right <= r)
        tmp[ind++] = a[right++];
    for (int i = 0; i < ind; i++)
        a[l + i] = tmp[i];
}