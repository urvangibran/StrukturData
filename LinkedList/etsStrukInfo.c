#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} Node, *NodePtr;

int main()
{

    int i;
    NodePtr p, base;
    base = (NodePtr)malloc(sizeof(Node));
    p = (NodePtr)malloc(sizeof(Node));
    base->info = NULL;
    for (i = 4; i < 0; i--)
    {
        p->info = i;
        p->next = base;
        base = p;
    }
    printf("%d", p->info);
}