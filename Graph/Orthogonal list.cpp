#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct anode
{
    int tailvex, headvex;
    struct anode *hlink, *tlink;
} ARCNODE, *ARCNODEPTR;

typedef struct
{
    char data;
    struct anode *firstin, *firstout;
} VERTEXNODE;

int adjMatrix[6][6] = {
    {0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}};

VERTEXNODE heads[6];

void create();
ARCNODEPTR newArc(int tail, int head);

int main()
{
    create();
    for(int i = 0; i < 6; i++)
    {
        cout << heads[i].data << "->";
        ARCNODEPTR nArc = heads[i].firstout;
        while(nArc)
        {
            cout << nArc->tailvex << '-' << nArc->headvex << "->";
            nArc = nArc->tlink; 
        }
        cout << "NULL" << endl;

        cout << heads[i].data << "->";
        nArc = heads[i].firstin;
        while(nArc)
        {
            cout << nArc->tailvex << '-' << nArc->headvex << "->";
            nArc = nArc->hlink; 
        }
        cout << "NULL" << endl;
    }
    system("pause");
    return 0;
}

ARCNODEPTR newArc(int tail, int head)
{
    ARCNODEPTR n = new (ARCNODE);
    n->hlink = n->tlink = NULL;
    n->tailvex = tail;
    n->headvex = head;
    return n;
}

void create()
{
    for (int i = 0; i < 6; i++)
    {
        heads[i].data = char('A' + i);
        heads[i].firstin = NULL;
        heads[i].firstout = NULL;
    }
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (adjMatrix[i][j])
            {
                ARCNODEPTR nArc = newArc(i + 1, j + 1);
                if (heads[i].firstout)
                {
                    ARCNODEPTR temp = heads[i].firstout;
                    while (temp->tlink)
                        temp = temp->tlink;
                    temp->tlink = nArc;
                }
                else
                    heads[i].firstout = nArc;

                if(heads[j].firstin)
                {
                    ARCNODEPTR temp = heads[j].firstin;
                    while (temp->hlink)
                        temp = temp->hlink;
                    temp->hlink = nArc;
                }
                else
                    heads[j].firstin = nArc;    
            }
}