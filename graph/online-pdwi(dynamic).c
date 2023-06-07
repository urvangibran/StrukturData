#include <stdio.h>
#include <stdlib.h>

typedef struct tipeS
{
    struct tipeS *left;
    int info;
    struct tipeS *right;
} simpul;

simpul *p, *first, *last, *pVertex, *pEdge, *q, *r, *s;
simpul *alamat[101];

int main()
{
    int n;
    scanf("%d", &n);
    int A[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    char str[n];
    scanf("%s", str);

    int i, j;
    i = 0;
    j = 0;
    p = (simpul *)malloc(sizeof(simpul));
    p->info = str[0];
    first = p;
    last = p;
    p->left = NULL;
    p->right = NULL;
    alamat[0] = p;
    printf("%c", p->info);
    printf(" alamat %d\n", alamat[0]);

    for (int i = 1; i < n; i++)
    {
        p = (simpul *)malloc(sizeof(simpul));
        p->info = str[i];
        last->left = p;
        last = last->left;
        p->left = NULL;
        p->right = NULL;
        alamat[i] = p;
        printf("%c", p->info);
        printf(" alamat %d\n", alamat[i]);
    }

    q = first;
    for (int i = 0; i < n; i++)
    {
        r = q;
        printf("Vertex %c .... ", q->info);
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                p = (simpul *)malloc(sizeof(simpul));
                p->info = A[i][j];
                p->right = p;
                p->left = alamat[j];
                printf("berhubungan dengan %c: ", p->left->info);
                printf("bobot %d; ", p->info);
                p->right = NULL;
                r = p;
            }
        }
        printf("\n");
        q = q->left;
    }
}
