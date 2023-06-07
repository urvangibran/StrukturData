#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tnode
{
    int data, priority;
    struct tnode *next;
}pQueueNode;

typedef struct tpq
{
    pQueueNode *top;
}PriorityQueue;

bool pq_isEmpty(PriorityQueue *pq)
{
    return (pq->top == NULL);
}

void push(PriorityQueue *ipq, int data, int prior)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode*)malloc(sizeof(pQueueNode));
    newNode->data = data;
    newNode->priority = prior;
    newNode->next = NULL;

    if((pq_isEmpty(ipq)))
    {
        ipq->top = newNode;
    }
    else if(prior > ipq->top->priority)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
    else
        {
            while(temp->next != NULL && prior < temp->next->priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            
            temp->next = newNode;
        }
    }


void pop(PriorityQueue *ipq)
{
    if(!pq_isEmpty(ipq))
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

void show(PriorityQueue *ipq)
{
    if(pq_isEmpty(ipq))
        printf("HORE\n");
    
    printf("%d\n", ipq->top->data);
    if(ipq->top != NULL)
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

int main()
{
    int n;
    PriorityQueue pqueue;
    scanf("%d", &n);
    pqueue.top = NULL;
    while(n--)
    {
        int a,b;
        char order[10];
        scanf("%s", order);
        if(!strcmp(order, "MASUK"))
        {
            scanf("%d %d", &a, &b);
            push(&pqueue, a, b);
        }
        else if(!strcmp(order, "LAYANI"))
        {
            show(&pqueue);
        }
    }
}

