#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct arc
{
    int data;
    struct arc *next;
} ARC, *ARCNODE;

typedef struct v
{
    char data;
    struct arc *next;
} VERTEX, *VERTEXPTR;

int adjMatrix[6][6] = {
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}};

int isVisit[6] = {0};
VERTEXPTR *buildAdjList();
void dfsAdjMat(int row);
void dfsAdjLis(int node, VERTEXPTR *h);
void bfsAdjMat();
void bfsAdjLis(VERTEXPTR *h);

int main()
{
    VERTEXPTR *a = buildAdjList();
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << a[i]->data << ':';
    //     ARCNODE cur = a[i]->next;
    //     while (cur)
    //     {
    //         cout << "->" << cur->data;
    //         cur = cur->next;
    //     }
    //     cout << endl;
    // }
    cout << 'A' << "->";
    isVisit[0] = 1;
    dfsAdjMat(0);
    cout << endl;
    for(int i = 1; i < 6; i++)
        isVisit[i] = 0;
    cout << 'A' << "->";
    dfsAdjLis(0, a);
    cout << endl;
    bfsAdjMat();
    cout << endl;
    bfsAdjLis(a);
    system("pause");
    return 0;
}

VERTEXPTR *buildAdjList()
{
    VERTEXPTR *l = new (VERTEXPTR[6]);

    for (int i = 0; i < 6; i++)
    {
        l[i] = new (VERTEX);
        l[i]->data = char(i + 'A');
        l[i]->next = NULL;
        ARCNODE cur = NULL;
        for (int j = 0; j < 6; j++)
            if (adjMatrix[i][j])
            {
                ARCNODE newArc = new (ARC);
                newArc->data = j;
                newArc->next = NULL;
                if (cur)
                    cur->next = newArc;
                else
                    l[i]->next = newArc;
                cur = newArc;
            }
    }
    return l;
}

void dfsAdjMat(int row)
{
    for (int i = 0; i < 6; i++)
        if (adjMatrix[row][i] && !isVisit[i])
        {
            cout << char(i + 'A') << "->";
            isVisit[i] = 1;
            dfsAdjMat(i);
        }
}

void dfsAdjLis(int node, VERTEXPTR *h)
{
    ARCNODE e = h[node]->next;
    while(e)
    {
        if(!isVisit[e->data])
        {
            cout << char(e->data + 'A') << "->";
            isVisit[e->data] = 1;
            dfsAdjLis(e->data, h);
        }
        e = e->next;
    }
}
void bfsAdjMat()
{
    int isVisit[6] = {0};
    int queue[100];
    for (int i = 0; i < 100; i++)
        queue[i] = -1;
    int front = 0, end = 0;
    cout << 'A' << "->";
    isVisit[0] = 1;
    queue[end++] = 0;
    while(front != end)
    {
        int cur = queue[front++];
        for(int i = 0; i < 6; i++)
        {
            if(adjMatrix[cur][i] && !isVisit[i])
            {
                cout << char(i + 'A') << "->";
                isVisit[i] = 1;
                queue[end++] = i;
            }
        }
    } 
}

void bfsAdjLis(VERTEXPTR *h)
{
    int isVisit[6] = {0};
    int queue[100];
    for (int i = 0; i < 100; i++)
        queue[i] = -1;
    int front = 0, end = 0;
    cout << 'A' << "->";
    isVisit[0] = 1;
    queue[end++] = 0;
    while(front != end)
    {
        int cur = queue[front++];
        ARCNODE e = h[cur]->next;
        while(e)
        {
            if(!isVisit[e->data])
            {
                cout << char(e->data + 'A') << "->";
                isVisit[e->data] = 1;
                queue[end++] = e->data;
            }
            e = e->next;
        }
    } 
}