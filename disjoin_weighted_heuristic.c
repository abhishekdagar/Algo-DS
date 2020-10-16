#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int data;
    struct Node *link;
    struct item *iptr;
};
struct Node *nodead[100];
struct item
{
    struct Node *hd;
    struct Node *tl;
};
struct Node *makenode(int val)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->iptr = NULL;
    temp->link = NULL;
    return temp;
}
struct item *makeitem()
{
    struct item *temp;
    temp = (struct item *)malloc(sizeof(struct item));
    return temp;
}
struct item *makeset(int val)
{
    struct item *newset;
    newset = makeitem();
    newset->hd = makenode(val);
    newset->tl = newset->hd;
    nodead[val] = newset->hd;
    newset->hd->data = val;
    newset->hd->iptr = newset;
    newset->hd->link = NULL;
    return newset;
}
struct item *Smaller(struct item *s1, struct item *s2)
{
    struct Node *cur = s1->hd;
    int c = 0, c1 = 0;
    while (cur != NULL)
    {
        cur = cur->link;
        c++;
    }
    cur = s2->hd;
    while (cur != NULL)
    {
        cur = cur->link;
        c1++;
    }
    if (c < c1)
        return (s1);
    else
        return (s2);
}
struct item *findset(int val)
{
    struct Node *temp;
    temp = nodead[val];
    return temp->iptr;
}
void Union(struct item *s1, struct item *s2)
{
    if ((s1->hd->data) == (s2->hd->data))
        return;
    struct item *temp;
    if (Smaller(s1, s2)->hd->data == s1->hd->data)
    {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }
    struct Node *cur = s2->hd;
    while (cur != 0)
    {
        cur->iptr = s1;
        cur = cur->link;
    }
    (s1->tl)->link = s2->hd;
    s1->tl = s2->tl;
    free(s2);
}
void main()
{
    struct item *s[10];
    int graph[10][10] = {{0, 1, 0, 0, 0},
                         {1, 0, 1, 0, 0},
                         {0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 1},
                         {0, 0, 0, 1, 0}};
    int n = 5; //no. of nodes
    for (int i = 0; i < n; i++)
    {
        s[i] = makeset(i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nfind(%d):%d", i, findset(i)->hd->data);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                Union(findset(i), findset(j));
            }
        }
    }
    printf("\nAfter grouping\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nfind(%d):%d", i, findset(i)->hd->data);
    }
    printf("\nUnion(find(0),find(3)):\n");
    Union(findset(0), findset(3));
    for (int i = 0; i < n; i++)
    {
        printf("\nfind(%d):%d", i, findset(i)->hd->data);
    }
}
