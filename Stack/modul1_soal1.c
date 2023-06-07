#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct pqNode_t{
    int x, id;
    struct pqNode_t *next;
}pQueNode;

typedef struct pqueue_t{
    pQueNode *top;
    unsigned _size;
}PriorityQueue;

bool pq_isEmpty(PriorityQueue *pq)
{
    return(pq->top == NULL);
}

void pq_push(PriorityQueue *pq, int val_id, int value)
{
    pq->_size++;
    pQueNode *temp = pq->top;
    pQueNode *newNode = (pQueNode*) malloc(sizeof(pQueNode));
    newNode->x = value;
    newNode->id = val_id;
    newNode->next = NULL;

    if(pq_isEmpty(pq))
    {
        pq->top = newNode;
        return;
    }
    if(value < pq->top->x)
    {
        newNode->next = pq->top;
        pq->top = newNode;
    }
    else
    {
        while(temp->next != NULL && temp->next->x < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pop(PriorityQueue *pq)
{
    if(!pq_isEmpty(pq))
    {
        pQueNode *temp = pq->top;
        pq->top = pq->top->next;
        free(temp);  
    }
}

int top_pq(PriorityQueue *pq)
{
    if(!pq_isEmpty(pq))
        return pq->top->x;
    return 0;
}

int main()
{
    PriorityQueue pqueue;
    int n, a, b;
    scanf("%d\n", &n);
    while(n--)
    {
        char order[10];
        scanf("%[^\n] %d %d", order, &a, &b);
        if(strcmp(order, "MASUK") == 0)
        {
            pq_push(&pqueue, a, b);
        }
        else if(strcmp(order, "LAYANI") == 0)
        {
            printf("%d ", top_pq(&pqueue));
            pop(&pqueue);
        }
    }
    return 0;
}