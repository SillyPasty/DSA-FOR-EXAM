#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct stacknode
{
    int data;
    struct stacknode *next;
}NODE, *NODEPTR;

NODEPTR init();
int pop(NODEPTR h);
void push(int n, NODEPTR h);
bool isEmpty(NODEPTR h);
int top(NODEPTR h);

int main()
{
    NODEPTR head = init();
    push(5, head);
    push(6, head);
    printf("%d, %d, %d",pop(head), top(head) , pop(head));
    system("pause");
    return 0;
}

NODEPTR init()
{
    NODEPTR head = new(NODE);
    head->next = NULL;
    head->data = 0;
    return head;
}

int pop(NODEPTR h)
{
    NODEPTR t = h->next;
    int tmp = h->next->data;
    h->next = t->next;
    delete(t);
    return tmp;
}

void push(int x, NODEPTR h)
{
    NODEPTR t = h->next;
    NODEPTR n = new(NODE);
    h->next = n;
    n->data = x;
    n->next = t;
}

bool isEmpty(NODEPTR h)
{
    if(h->next == NULL)
        return true;
    return false;
}

int top(NODEPTR h)
{
    if(!isEmpty(h))
        return -65536;
    return h->next->data;
}