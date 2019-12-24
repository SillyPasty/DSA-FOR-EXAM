#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void insertSort(int *input_array, int n);

int main()
{
    int n, input_array[200] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d,", &input_array[i]);
    insertSort(input_array, n);
    system("pause");
    return 0;
}

void insertSort(int *input_array, int n)
{
    for(int i = 1; i < n; i++)
    {
        int cur = input_array[i];
        int j;
        for(j = i - 1; 0 <= j && cur < input_array[j]; j--)
            input_array[j + 1] = input_array[j];
        input_array[j + 1] = cur;
        for(int k = 0; k < n; k++)
            cout << input_array[k] << ',';
        cout << '\n';
    }
}