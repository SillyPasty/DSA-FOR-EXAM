#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int MAX = INT16_MAX;

int adjMatrix[7][7] = {
    {0, 2, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 10, 0, 0},
    {4, 0, 0, 0, 0, 5, 0},
    {0, 0, 2, 0, 2, 8, 4},
    {0, 0, 0, 0, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0}};
int minPath[7] = {0};
int isVisited[7] = {0};
int path[7] = {0};

void dijkstra(int start);
void floyd(int head, int tail);
void showPath(int i);

int main()
{
    dijkstra(0);
    floyd(0, 5);
    system("pause");
    return 0;
}

void dijkstra(int start)
{
    int queue[100] = {0};
    int front = 0, end = 0;
    path[start] = -1;
    queue[end++] = start;
    isVisited[start] = 1;
    while (front != end)
    {
        int cur = queue[front], minFlag = front;
        for (int i = front; i < end; i++)
            if (minPath[queue[i]] < minPath[cur])
            {
                cur = queue[i];
                minFlag = i;
            }
        queue[minFlag] = queue[front++];
        for (int i = 0; i < 7; i++)
            if (adjMatrix[cur][i])
            {
                if (!isVisited[i])
                {
                    queue[end++] = i;
                    isVisited[i] = 1;
                }
                if ((!minPath[i] && i != start) || minPath[cur] + adjMatrix[cur][i] < minPath[i])
                {
                    minPath[i] = minPath[cur] + adjMatrix[cur][i];
                    path[i] = cur;
                }
            }
    }
    for (int i = 0; i < 7; i++)
    {
        showPath(i);
        cout << endl;
    }
}

void showPath(int i)
{
    if (path[i] == -1)
    {
        cout << i + 1 << "->";
        return;
    }
    showPath(path[i]);
    cout << i + 1 << "->";
}

void floyd(int head, int tail)
{
    int minPath[7][7];
    int path[7][7];
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
        {
            if (!adjMatrix[i][j])
                minPath[i][j] = MAX;
            else
                minPath[i][j] = adjMatrix[i][j];
            path[i][j] = -1;
        }
    for (int k = 0; k < 7; k++)
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
            {
                if (minPath[i][k] != MAX && minPath[k][j] != MAX && (minPath[i][k] + minPath[k][j] < minPath[i][j]))
                {
                    minPath[i][j] = minPath[i][k] + minPath[k][j];
                    path[i][j] = k;
                }
            }

    int h = head, t = tail;
    cout << tail + 1 << "<-";
    while (path[h][t] != -1)
    {
        cout << path[h][t] + 1 << "<-";
        t = path[h][t];
    }
    cout << head + 1;
}