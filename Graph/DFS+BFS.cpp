#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

int adjMatrix[6][6] = {
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}};
int isVisit[6] = {0};

void dfs(int row);
void bfs(int row);

int main()
{
    cout << char('A' + 0) << endl;
    isVisit[0] = 1;
    dfs(0);

    for(int i = 0; i <6; i++)
        isVisit[i] = 0;  
    cout << char('A' + 0) << endl;
    isVisit[0] = 1;
    bfs(0);
    system("pause");
    return 0;
}

void dfs(int row)
{
    for (int i = 0; i < 6; i++)
        if (adjMatrix[row][i] == 1 && !isVisit[i])
        {
            cout << char('A' + i) << endl;
            isVisit[i] = 1;
            dfs(i);
        }
}

void bfs(int row)
{
    queue<int> vis;
    vis.push(row);
    while (!vis.empty())
    {
        row = vis.front();
        for (int i = 0; i < 6; i++)
            if (adjMatrix[row][i] == 1 && !isVisit[i])
            {
                vis.push(i);
                cout << char('A' + i) << endl;
                isVisit[i] = 1;
            }
        vis.pop();
    }
}