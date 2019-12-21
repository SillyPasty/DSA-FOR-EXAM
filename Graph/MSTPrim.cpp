#include <cstdio>
#include <cstdlib>
#include <iostream>
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

void prim(int root);
int isVisited[10] = {0};

int main()
{
    prim(0);
    system("pause");
    return 0;
}

void prim(int root)
{
    int knownNode[10], edgeInfo[10][3];
    int start = 0, end = 0, edge = 0;
    knownNode[end++] = root;
    isVisited[root] = 1;
    while (end <= 10)
    {
        int mina = -1, minb = -1;
        for (int i = 0; i < end; i++)
        {
            int cur = knownNode[i];
            for(int j = 0; j < 10; j++)
            {
                if(adjMatrix[cur][j] && !isVisited[j])
                {
                    if(mina == -1 || adjMatrix[cur][j] < adjMatrix[mina][minb])
                    {
                        mina = cur;
                        minb = j;
                    }
                }
            }
        }
        knownNode[end++] = minb;
        isVisited[minb] = 1;
        edgeInfo[edge][0] = mina;
        edgeInfo[edge][1] = minb;
        edgeInfo[edge++][2] = adjMatrix[mina][minb];
    }
    for(int i = 0; i < 9; i++)
        cout << edgeInfo[i][0] << "->" << edgeInfo[i][1] << "weight:" << edgeInfo[i][2] << endl;
}