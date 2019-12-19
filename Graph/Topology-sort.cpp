#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int adjMatrix[11][11] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
char ans[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'S', 'T'};
void topSort();

int main()
{
    topSort();
    // ans should be S,B,G,D,H,A,E,I,F,C,T,
    system("pause");
    return 0;
}

void topSort()
{
    int queue[100];
    for (int i = 0; i < 100; i++)
        queue[i] = -1;
    int front = 0, end = 0;
    for (int i = 10; 0 <= i; i--)
    {
        int flag = 0;
        for (int j = 0; j < 11; j++)
            if (adjMatrix[j][i])
                flag = 1;
        if (!flag)
            queue[end++] = i;
    }
    while (front != end)
    {
        int cur = queue[front++];
        cout << ans[cur] << ',';
        for (int i = 0; i < 11; i++)
        {
            if (adjMatrix[cur][i])
            {
                int flag = 0;
                adjMatrix[cur][i] = 0;
                for (int j = 0; j < 11; j++)
                {
                    if (adjMatrix[j][i])
                        flag = 1;
                }
                if (!flag)
                    queue[end++] = i;   
            }
        }
    }
}
