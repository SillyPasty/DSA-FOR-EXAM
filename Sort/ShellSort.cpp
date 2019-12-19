#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void shellSort(int *input_array, int n);

int main()
{
    int n, input_array[200] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d,", &input_array[i]);
    shellSort(input_array, n);
    //system("pause");
    return 0;
}

void shellSort(int *input_array, int n)
{
    for(int d = n / 2; d > 0; d /= 2)
    {
        for(int i = 0; i < d; i++)
        {
            for(int j = i; j < n; j += d)
            {
                int k, cur = input_array[j];
                for(k = j - d; 0 <= k && input_array[k] < cur; k -= d)
                    input_array[k + d] = input_array[k];
                input_array[k + d] = cur;
            }
        }
        for(int k = 0; k < n; k++)
            cout << input_array[k] << ',';
        cout << '\n';
    }

}

/*
10
49,38,65,97,76,13,27,50,2,8,
*/