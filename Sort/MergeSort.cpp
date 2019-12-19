#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void mergeSort(int *a, int left, int right);

int main()
{
    int a[] = {2, 4, 5, 6, 3, 1, 8};
    mergeSort(a, 0, 6);
    for(int i = 0; i < 7; i++)
        cout << a[i];
    system("pause");
    return 0;
}

void mergeSort(int *a, int left, int right)
{
    if ((right - left) == 1)
    {
        if (a[right] < a[left])
            swap(a[right], a[left]);
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    int tmp[100] = {0};
    int l = left, r = mid, flg = 0;
    while (l < mid && r <= right)
    {
        if (a[l] < a[r])
        {
            tmp[flg] = a[l];
            l++;
        }
        else
        {
            tmp[flg] = a[r];
            r++;
        }
        flg++;        
    }
    while(l < mid)
        tmp[flg++] = a[l++];
    while(r <= right)
        tmp[flg++] = a[r++];
    for(int i = left; i <= right; i++)
        a[i] = tmp[i - left];
}