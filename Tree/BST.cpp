#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
typedef int datatype;

typedef struct bst_tree_node
{
    datatype a;
    struct bst_tree_node *lc, *rc, *parent;
    int height, depth;
} BSTNODE, *BSTNODEPTR;

BSTNODEPTR create();
BSTNODEPTR initNode(int data);
void updateHeight(BSTNODEPTR cur);
void preOrderTraversal(BSTNODEPTR cur);
void inOrderTraversal(BSTNODEPTR cur);
void postOrderTraversal(BSTNODEPTR cur);
void levelOrderTraversal(BSTNODEPTR root);

void remove(BSTNODEPTR root, int n);
BSTNODEPTR findMax(BSTNODEPTR root);
BSTNODEPTR findMin(BSTNODEPTR root);
BSTNODEPTR find(BSTNODEPTR root, int n);
BSTNODEPTR getSuccessor(BSTNODEPTR cur);

int main()
{
    BSTNODEPTR head = create();
    updateHeight(head);
    levelOrderTraversal(head);
    BSTNODEPTR tmp = find(head, 5);
    remove(head, 5);
    preOrderTraversal(head);
    system("pause");
    return 0;
}
// 1 4 2 5 6 8 7 3
BSTNODEPTR initNode(int data)
{
    BSTNODEPTR newNode = new (BSTNODE);
    newNode->lc = newNode->rc = newNode->parent = NULL;
    newNode->a = data;
    newNode->depth = 0;
    return newNode;
}
BSTNODEPTR create()
{
    int data;
    cin >> data;
    BSTNODEPTR root = initNode(data);
    while (cin >> data)
    {
        BSTNODEPTR cur = root;
        while (1)
            if (data <= cur->a)
                if (!cur->lc)
                {
                    cur->lc = initNode(data);
                    cur->lc->depth = cur->depth + 1;
                    cur->lc->parent = cur;
                    break;
                }
                else
                    cur = cur->lc;
            else if (!cur->rc)
            {
                cur->rc = initNode(data);
                cur->rc->depth = cur->depth + 1;
                cur->rc->parent = cur;
                break;
            }
            else
                cur = cur->rc;
    }
    return root;
}

void updateHeight(BSTNODEPTR cur)
{
    if (!cur)
        return;
    if (!(cur->lc || cur->rc))
    {
        cur->height = 0;
        return;
    }
    updateHeight(cur->lc);
    updateHeight(cur->rc);
    if (cur->lc && cur->rc)
        cur->height = max(cur->lc->height, cur->rc->height) + 1;
    else if (cur->lc && !cur->rc)
        cur->height = cur->lc->height + 1;
    else if (cur->rc && !cur->lc)
        cur->height = cur->rc->height + 1;
}

void preOrderTraversal(BSTNODEPTR cur)
{
    if (!cur)
        return;
    cout << cur->a;
    preOrderTraversal(cur->lc);
    preOrderTraversal(cur->rc);
}

void inOrderTraversal(BSTNODEPTR cur)
{
    if (!cur)
        return;
    inOrderTraversal(cur->lc);
    cout << cur->a;
    inOrderTraversal(cur->rc);
}

void postOrderTraversal(BSTNODEPTR cur)
{
    if (!cur)
        return;
    postOrderTraversal(cur->lc);
    postOrderTraversal(cur->rc);
    cout << cur->a;
}

void levelOrderTraversal(BSTNODEPTR root)
{
    queue<BSTNODEPTR> q;
    q.push(root);
    while (!q.empty())
    {
        BSTNODEPTR cur = q.front();
        if (cur->lc)
            q.push(cur->lc);
        if (cur->rc)
            q.push(cur->rc);
        q.pop();
        cout << cur->a << "height:" << cur->height << endl;
    }
}

BSTNODEPTR findMax(BSTNODEPTR root)
{
    BSTNODEPTR cur = root;
    while (cur->rc)
        cur = cur->rc;
    cout << "MAX:" << cur->a << endl;
    return cur;
}

BSTNODEPTR findMin(BSTNODEPTR root)
{
    BSTNODEPTR cur = root;
    while (cur->lc)
        cur = cur->lc;
    cout << "MIN:" << cur->a << endl;
    return cur;
}

BSTNODEPTR find(BSTNODEPTR root, int n)
{
    BSTNODEPTR cur = root;
    while (cur)
    {
        if (cur->a == n)
            return cur;
        else if (cur->a < n)
            cur = cur->rc;
        else
            cur = cur->lc;
    }
    return cur;
}

void remove(BSTNODEPTR root, int n)
{
    BSTNODEPTR nodeToRemove = find(root, n);
    if (!(nodeToRemove->lc || nodeToRemove->rc))
    {
        if(nodeToRemove == nodeToRemove->parent->lc)
            nodeToRemove->parent->lc = NULL;
        else
            nodeToRemove->parent->rc = NULL;
        delete (nodeToRemove);
    }
        
    else if (nodeToRemove->lc && nodeToRemove->rc)
    {
        BSTNODEPTR succ = getSuccessor(nodeToRemove);
        swap(nodeToRemove->a, succ->a);
        remove(root, n);
    }
    else
    {
        if (nodeToRemove->lc)
            if (nodeToRemove == nodeToRemove->parent->lc)
                nodeToRemove->parent->lc = nodeToRemove->lc;
            else
                nodeToRemove->parent->rc = nodeToRemove->lc;
        else
        {
            if (nodeToRemove == nodeToRemove->parent->lc)
                nodeToRemove->parent->lc = nodeToRemove->rc;
            else
                nodeToRemove->parent->rc = nodeToRemove->rc;
        }
        delete (nodeToRemove);
    }
}

BSTNODEPTR getSuccessor(BSTNODEPTR cur)
{
    BSTNODEPTR tmp = cur;
    tmp = tmp->rc;
    while (tmp->lc)
        tmp = tmp->lc;
    return tmp;
}