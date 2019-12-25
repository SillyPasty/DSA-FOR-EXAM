/* A type of Selection Sorting
 * By Yubo Wang 2019.12.23
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapAdjust(int arg[], int s, int len);
void heapSort(int arg[], int len);

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
    heapSort(args, len);
    system("pause");
    return 0;
}

void heapAdjust(int arg[], int s, int len)
{
    int a = arg[s];
    for (int cur = s * 2; cur < len; cur *= 2)
    {
        if(cur == 0)
            cur += 1;
        if (arg[cur] < arg[cur + 1] && (cur < len - 1))
            cur++;
        if(arg[cur] < a)
            break;
        arg[s] = arg[cur];
        s = cur;
    }
    arg[s] = a;
}

void heapSort(int arg[], int len)
{
    for(int i = len / 2; 0 < i; i--)
        heapAdjust(arg, i, len);
    for(int i = len - 1; 0 < i; i--)
    {
        swap(arg[i], arg[0]);
        heapAdjust(arg, 0, i - 1);
    }
    for (int i = 0; i < len; i++)
        cout << arg[i] << ' ';
    cout << endl;
}