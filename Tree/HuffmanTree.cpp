#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct bst_tree_node
{
    int weight;
    char data;
    struct bst_tree_node *lc, *rc, *parent;
    char str[100] = {0};
    int height, depth;
} BSTNODE, *BSTNODEPTR;

char *huff[26];
// 10111010100001000110011110110100
BSTNODEPTR create();
BSTNODEPTR initNode(int w, char da);
BSTNODEPTR buildHuffmanTree(char str[]);
void decode(char str[], BSTNODEPTR h);
char *uncode(BSTNODEPTR head);
void updateHeight(BSTNODEPTR cur);
void preOrderTraversal(BSTNODEPTR cur);
void inOrderTraversal(BSTNODEPTR cur);
void postOrderTraversal(BSTNODEPTR cur);
void levelOrderTraversal(BSTNODEPTR root);

void upgradeTraversal(BSTNODEPTR cur, char c[], char s[]);

int main()
{
    char str[] = "aaaaaaabbbbbbbbbbbbbbbbbbbccddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeefffggggggggggggggggggggghhhhhhhhhh";
    
    BSTNODEPTR head = buildHuffmanTree(str);
    upgradeTraversal(head, "", "");
    char str2[1000] = {0};
    // for(int i = 0; i < strlen(str); i++)
    //     strcat(str2, huff[int(str[i] - 'a')]);
    // cout << str2 << endl;
    cin >> str2;
    decode(str2, head);
    // preOrderTraversal(head);
    system("pause");
    return 0;
}
// 1 4 2 5 6 8 7 3

void upgradeTraversal(BSTNODEPTR cur, char c[], char s[])
{
    if(!cur)
        return;
    strcat(cur->str, s);
    strcat(cur->str, c);
    if(cur->data <= 'z' && 'a' <= cur->data)
    {
        huff[int(cur->data - 'a')] = cur->str;
    }
    upgradeTraversal(cur->lc, "0", cur->str);
    upgradeTraversal(cur->rc, "1", cur->str);
}
BSTNODEPTR initNode(int w, char da)
{
    BSTNODEPTR newNode = new (BSTNODE);
    newNode->lc = newNode->rc = newNode->parent = NULL;
    newNode->data = da;
    newNode->weight = w;
    newNode->depth = 0;
    // newNode->str = "";
    return newNode;
}

void decode(char str[], BSTNODEPTR h)
{
    BSTNODEPTR tmp = h;
    for(int i = 0; i < strlen(str); i++)
    {
        if(int(str[i] - '0') == 0)
            tmp = tmp->lc;
        else
            tmp = tmp->rc;
        if(tmp->data <= 'z' && 'a' <= tmp->data)
        {
            cout << tmp->data;
            tmp = h;
        }
    }
}

BSTNODEPTR buildHuffmanTree(char str[])
{
    BSTNODEPTR lis[100];
    int isAvi[100];
    for (int i = 0; i < 100; i++)
        isAvi[i] = -1;
    int wei[26] = {0}, flg = 0;
    // for(int i = 0; i < 26; i++)
    //     wei[i] = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        wei[str[i] - 'a']++;
    }
    // for(int i = 0; i < 26; i++)
    //     cout << wei[i];
    for (int i = 0; i < 26; i++)
    {
        if (wei[i] != 0)
        {
            BSTNODEPTR n = initNode(wei[i], char(i + 'a'));
            lis[flg] = n;
            isAvi[flg] = wei[i];
            flg++;
        }
    }
    
    int i, j;
    while (1)
    {
        int min1Flag = -1, min2Flag = -1;
        for (j = 0; j < flg; j++)
            if (isAvi[j] != -1)
            {
                min1Flag = j;
                break;
            }
        for (j = 0; j < flg; j++)
            if (isAvi[j] != -1 && lis[j]->weight < lis[min1Flag]->weight)
                min1Flag = j;
        isAvi[min1Flag] = -1;

        for (j = 0; j < flg; j++)
            if (isAvi[j] != -1)
            {
                min2Flag = j;
                break;
            }
        for (j = 0; j < flg; j++)
            if (isAvi[j] != -1 && lis[j]->weight < lis[min2Flag]->weight)
            {
                min2Flag = j;
            }
        if (min2Flag == -1)
            return lis[min1Flag];
        // cout << "min1:" << min1Flag << "min2:" << min2Flag << endl;
        isAvi[min2Flag] = -1;
        BSTNODEPTR n = initNode(lis[min1Flag]->weight + lis[min2Flag]->weight, '_');
        n->lc = lis[min1Flag];
        n->rc = lis[min2Flag];
        lis[flg] = n;
        isAvi[flg] = n->weight;
        flg++;
        // for(int i = 0; i < flg; i++)
        //     cout << lis[i]->weight << ',' << isAvi[i] << endl;
        // cout << "--------" << flg << endl;
    }
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
    cout << cur->data;
    preOrderTraversal(cur->lc);
    preOrderTraversal(cur->rc);
}

void inOrderTraversal(BSTNODEPTR cur)
{
    if (!cur)
        return;
    inOrderTraversal(cur->lc);
    cout << cur->data;
    inOrderTraversal(cur->rc);
}

void postOrderTraversal(BSTNODEPTR cur)
{
    if (!cur)
        return;
    postOrderTraversal(cur->lc);
    postOrderTraversal(cur->rc);
    cout << cur->data;
}