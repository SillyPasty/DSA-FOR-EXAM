#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int adjMatrix[10][10] = {
    {0, 3, 0, 4, 4, 0, 0, 0, 0, 0},
    {3, 0, 10, 0, 2, 3, 0, 0, 0, 0},
    {0, 10, 0, 0, 0, 6, 1, 0, 0, 0},
    {4, 0, 0, 0, 5, 0, 0, 6, 0, 0},
    {4, 2, 0, 5, 0, 11, 0, 2, 1, 0},
    {0, 3, 6, 0, 11, 0, 2, 0, 3, 11},
    {0, 0, 1, 0, 0, 2, 0, 0, 0, 8},
    {0, 0, 0, 6, 2, 0, 0, 0, 4, 0},
    {0, 0, 0, 0, 1, 3, 0, 4, 0, 7},
    {0, 0, 0, 0, 0, 11, 8, 0, 7, 0},
};

void kruskal();
int find(int k);  // 找到当前节点所在集合的索引，默认自己
void addSet(int a, int b);  // 将a和b放入同一个集合
int isVisited[10] = {0};
int p[10];

int main()
{
    char x, y;
    int a;
    // scanf("%c,%c,%d",&x, &y, &a);
    // adjMatrix[int(x - 'A')][int(y - 'A')] = a;
    // adjMatrix[int(y - 'A')][int(x - 'A')] = a;
    for (int i = 0; i < 10; i++)
        p[i] = i;
    kruskal();
    system("pause");
    return 0;
}

int find(int k)
{
    return p[k] == k ? k : k = find(p[k]);
}
void addSet(int a, int b)
{
    int ah = find(a);
    int bh = find(b);
    for (int i = 0; i < 10; i++)
        if (p[i] == bh)
            p[i] = ah;
}
void kruskal()
{
    int cur1, cur2;
    while (1)
    {
        int min = 10000;
        cur1 = cur2 = -1;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                if (adjMatrix[i][j] < min  && find(i) != find(j) && adjMatrix[i][j] != 0)
                {
                    cur1 = i;
                    cur2 = j;
                    min = adjMatrix[i][j];  // 找到当前未加入集合的最小边
                }
            }
        addSet(cur1, cur2);
        printf("%d,", adjMatrix[cur1][cur2]);

        int flag = 1;
        int h = find(cur1);

        // printf("%d,%d\n", h, find(cur2));
        for (int i = 0; i < 10; i++)
            if(p[i] != h)
                flag = 0;
        if(flag)
            break;
    }
}
