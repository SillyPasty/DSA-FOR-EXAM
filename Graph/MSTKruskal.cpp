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

void kruskal(int root);
int findS(int a);
void joint(int a, int b);
int setP[10];

int main()
{
    for (int i = 0; i < 10; i++)
        setP[i] = i;
    kruskal(0);
    system("pause");
    return 0;
}

int findS(int a)
{
    return setP[a] == a ? a : findS(setP[a]);
}

void joint(int a, int b)
{
    int aS = findS(a);
    int bS = findS(b);
    for (int i = 0; i < 10; i++)
        if (setP[i] == aS)
            setP[i] = bS;
}

void kruskal(int root)
{
    int edgeInfo[10][3], edgF = 0;
    while (edgF <= 9)
    {
        int mina = -1, minb = -1;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (adjMatrix[i][j])
                    if ((mina == -1 || (adjMatrix[i][j] < adjMatrix[mina][minb])) && findS(i) != findS(j))
                    {
                        mina = i;
                        minb = j;
                    }
        joint(minb, mina);
        edgeInfo[edgF][0] = mina;
        edgeInfo[edgF][1] = minb;
        edgeInfo[edgF++][2] = adjMatrix[mina][minb];
    }
    for (int i = 0; i < 9; i++)
        cout << edgeInfo[i][0] << "->" << edgeInfo[i][1] << "weight:" << edgeInfo[i][2] << endl;
    // for(int i = 0; i < 10; i++)
    //     cout << setP[i];
    
}