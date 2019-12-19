#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct queueNode
{
    int data;
    struct queueNode *next;
}NODE, *NODEPTR;

NODEPTR init();
NODEPTR enqueue(NODEPTR tail, int n);
int front(NODEPTR head);
int dequeue(NODEPTR head);
bool isEmpty(NODEPTR head);

int main()
{
    NODEPTR h = init();
    NODEPTR t;
    t = enqueue(h, 1);
    t = enqueue(t, 5);
    cout << front(h) << endl;
    cout << dequeue(h) << endl;
    cout << front(h) << endl;
    cout << dequeue(h) << endl;
    system("pause");
    return 0;
}

NODEPTR init()
{
    NODEPTR head = new(NODE);
    head->next = NULL;
    head->data = -1;
    return head;
}

NODEPTR enqueue(NODEPTR tail, int n)
{
    NODEPTR added = new(NODE);
    added->next = NULL;
    added->data = n;
    tail->next = added;
    tail = added;
    return tail;
}

int front(NODEPTR head)
{
    if(isEmpty(head))
    {
        cout << "EMPTY!";
        return -1;
    }
    return head->next->data;
}

int dequeue(NODEPTR head)
{
    if(isEmpty(head))
    {
        cout << "EMPTY!";
        return -1;
    }
    NODEPTR tmp = head->next;
    int n = tmp->data;
    head->next = tmp->next;
    delete(tmp);
    return n;
}

bool isEmpty(NODEPTR head)
{
    if(head->next)
        return false;
    return true;
}