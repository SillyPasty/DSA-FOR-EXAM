#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

void selectionSort(int a[], int n);

int main()
{
    int a, s[21];
    cin >> a;
    for(int i = 0; i < a; i++)
        scanf("%d,", &s[i]);
    selectionSort(s, a);
    system("pause");
    return 0;
}

void selectionSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int indMin = i;
        for(int j = i + 1; j < n; j++)
            indMin = a[indMin] < a[j] ? indMin : j;
        swap(a[indMin], a[i]);
        for(int j = 0; j < n; j++)
            cout << a[j] << ',';
        cout << endl;
    }
}