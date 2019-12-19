#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int adjMatrix[7][7] = {
    {0, 2, 0, 1, 0, 0, 0},
    {0, 0, 0, 3, 10, 0, 0},
    {4, 0, 0, 0, 0, 5, 0},
    {0, 0, 2, 0, 2, 8, 4},
    {0, 0, 0, 0, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0}};
int minPath[7] = {0};
int isVisited[7] = {0};
int path[7] = {0};
queue<int> q;


void dijkstra();
void printPath(int cur);
int main()
{
    int e1, e2;
    for(int i = 0; i < 7; i++)
        minPath[i] = -1;
    scanf("%d", &e1);
    getchar();
    scanf("%d", &e2);
    adjMatrix[e1 - 1][e2 - 1] = 0;
    dijkstra();
    //system("pause");
    return 0;
}

void dijkstra()
{
    q.push(0);
    minPath[0] = 0;
    isVisited[0] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < 7; i++)
            if(adjMatrix[cur][i] != 0)
            {
                if(!isVisited[i])
                {
                    q.push(i);
                    isVisited[i] = 1;
                }
                if(minPath[i] == -1)
                {
                    minPath[i] = minPath[cur] + adjMatrix[cur][i];
                    path[i] = cur;
                }
                else if(minPath[cur] + adjMatrix[cur][i] < minPath[i])
                {
                    minPath[i] = minPath[cur] + adjMatrix[cur][i];
                    path[i] = cur;
                    q.push(i);
                }
            }
    }
    printPath(5);
    printf("6");
}
void printPath(int cur)  
{
    if(cur == 0)
    {
        printf("1,");
        return;
    }
    printPath(path[cur]);
    if(cur != 5)
        printf("%d,", cur + 1);
}