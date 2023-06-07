#include <stdio.h>

void main()
{
    char S[] = "anton";
    char*p;

    //cara 1
    p = S;

    //cara 2 
    //p = &S[0];

    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%c ", *p);
        p++;
    }
    printf("\n");

    for(i = 0; i < 5 ; i++)
    {
        printf("%c ", *p);
        p++;
    }
    printf("\n");

    p--;
    for(i = 0; i < 5; i++)
    {
        printf("%c ", *p);
        p--;
    }

    printf("\n");
    p = S;
    for(i = 0; i < 5; i++)
    {
        printf("%c ", *p);
        p++;
    }
}