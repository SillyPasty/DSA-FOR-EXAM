#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE, *NODEPTR;

NODEPTR init();
bool insert(int n, NODEPTR h);
bool del(int n, NODEPTR h);
void traversal(NODEPTR h);
NODEPTR find(int n, NODEPTR h);

int main()
{
    NODEPTR head = init();
    insert(1, head);
    insert(2, head);
    traversal(head);
    system("pause");
    return 0;
}

NODEPTR init()
{
    NODEPTR head = new (NODE);
    head->data = -1;
    head->next = NULL;
    return head;
}

bool insert(int n, NODEPTR h)
{
    NODEPTR tmp = h;
    NODEPTR added = new (NODE);
    if (!added)
        return false;
    added->next = NULL;
    added->data = n;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = added;
    return true;
}

bool del(int n, NODEPTR h)
{
    NODEPTR tmp = h;
    while (tmp->next != NULL)
    {
        if (tmp->next->data == n)
        {
            NODEPTR x = tmp->next;
            tmp->next = tmp->next->next;
            delete x;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void traversal(NODEPTR h)
{
    NODEPTR tmp = h;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        printf("%d->", tmp->data);
    }
}

NODEPTR find(int n, NODEPTR h)
{
    NODEPTR tmp = h->next;
    while (tmp != NULL)
    {
        if (tmp->data == n)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}