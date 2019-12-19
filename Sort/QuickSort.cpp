#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int CUT_OFF = 3;
int piv;

void quickSort(int a[], int left, int right);
int median3(int a[], int left, int right);

void insertSort(int *input_array, int n, int left);

int main()
{
    int a[] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
    cin >> piv;
    quickSort(a, 0, 9);
    //system("pause");
    return 0;
}

int median3(int a[], int left, int right)
{
    int med = (left + right) / 2;
    if (a[med] < a[left])
        swap(a[left], a[med]);
    if (a[right] < a[left])
        swap(a[right], a[left]);
    if (a[right] < a[med])
        swap(a[med], a[right]);
    swap(a[med], a[right - 1]);
    return a[right - 1];
}

void quickSort(int a[], int left, int right)
{
    int i, j, pivot;
    if (left + CUT_OFF <= right)
    {
        if (right == 9 && left == 0)
        {
            pivot = a[piv];
            swap(a[right], a[piv]);
            j = right;
        }
        else
        {
            pivot = median3(a, left, right);
            j = right - 1;
        }
        i = left - 1;

        while (1)
        {
            while (a[++i] < pivot)
            {
            }
            while (pivot < a[--j])
            {
            }
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }
        if (right == 9 && left == 0)
            swap(a[right], a[i]);
        else
            swap(a[i], a[right - 1]);
        cout << "Qsort(" << left << ',' << right << "):";
        for (int i = 0; i < 10; i++)
            cout << a[i] << ',';
        cout << endl;
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
    {
        cout << "insert(" << left << ',' << right - left + 1 << "):";
        insertSort(a, right + 1, left);
    }
}

void insertSort(int *input_array, int n, int left)
{
    for (int i = left + 1; i < n; i++)
    {
        int cur = input_array[i];
        int j;
        for (j = i - 1; left <= j && cur < input_array[j]; j--)
            input_array[j + 1] = input_array[j];
        input_array[j + 1] = cur;
    }
    for (int k = 0; k < 10; k++)
        cout << input_array[k] << ',';
    cout << endl;
}
