#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id, priority;
    struct node *next;
} PQNode;

typedef struct pq
{
    PQNode *top;
} PQ;

void masuk(PQ *inp, int priority, int id)
{
    PQNode *temp = inp->top;
    PQNode *newNode = (PQNode *)malloc(sizeof(PQNode));
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;

    if (inp->top == NULL)
    {
        inp->top = newNode;
    }

    else if (priority > inp->top->priority)
    {
        newNode->next = inp->top;
        inp->top = newNode;
    }

    else
    {
        while (temp->next != NULL && temp->next->priority > priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void layani(PQ *inp)
{   
    if (inp->top == NULL)
    {
        puts("HORE");
    }
    
    printf("%d\n", inp->top->id);
    if (inp->top != NULL)
    {
        PQNode *temp = inp->top;
        inp->top = inp->top->next;
        free(temp);
    }
}

int main()
{
    int t;
    PQ stat;
    scanf("%d", &t);
    stat.top = NULL;
    while (t--)
    {
        int id_temp, priority_temp;
        char opr[10];
        scanf("%s", opr);
        if (!strcmp(opr, "MASUK"))
        {
            scanf("%d %d", &id_temp, &priority_temp);
            masuk(&stat,priority_temp,id_temp);
        }

        else if (!strcmp(opr, "LAYANI"))
        {
            layani(&stat);
        }
    }
}