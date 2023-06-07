#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    int data[10];
}Stack;

Stack tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

void push(char a)
{
    tumpuk.data[++tumpuk.top] = a;
}

int isEmpty()
{
    return (tumpuk.top==-1) ? 1 : 0;
}

char TOS()
{
    return tumpuk.data[tumpuk.top];
}

void pop()
{
    tumpuk.top--;
}

int priority(char a)
{
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/')
        return 2;
    if(a == '^')
        return 3;
    
    return 0;
}

int main()
{
    int t, i, j, n, idx; 
    char postfix[101];
    char infix[101];
    scanf("%d\n", &t);
    while(t--)
    {
        inisialisasi();
        idx = 0;
        scanf("%s", infix);
        n = strlen(infix);
        for(i = 0; i < n; i++)
        {
            if(infix[i] >= 'a' && 'z' >= infix[i] || infix[i] >= 'A' && 'Z' >= infix[i])
            {
                postfix[idx++] = infix[i];
            }
            else
            {
                if(infix[i] == '(')
                {
                    push(infix[i]);
                }
                else if(infix[i] == ')')
                {
                    while(TOS() != '(')
                    {
                        postfix[idx++] = TOS();
                        pop();
                    }
                    pop();
                }
                else 
                {
                    while(priority(infix[i]) <= priority(TOS()))
                    {
                    postfix[idx++] = TOS();
                    pop();
                    }
                    push(infix[i]);
                }
            }
        }
    while(!isEmpty())
    {
        postfix[idx++] = TOS();
        pop();
    }

    for(i = 0; i < n; i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
    }
    return 0;
}