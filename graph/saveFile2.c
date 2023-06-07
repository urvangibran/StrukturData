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

void saveGraphToFile(int n, int A[][n], char str[])
{
    FILE *file = fopen("graph.txt", "w");
    if (file == NULL)
    {
        printf("Gagal membuka file.");
        return;
    }

    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(file, "%d ", A[i][j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "%s\n", str);

    fclose(file);
}

void loadGraphFromFile(int *n, int A[][101], char str[])
{
    FILE *file = fopen("graph.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file.");
        return;
    }

    fscanf(file, "%d", n);

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            fscanf(file, "%d", &A[i][j]);
        }
    }

    fscanf(file, "%s", str);

    fclose(file);
}

void printGraph(int n, int A[][101], char str[])
{
    printf("Matriks:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("String: %s\n", str);

    printf("Hubungan antar vertex:\n");
    q = first;
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %c .... ", q->info);
        r = q->right;
        while (r != NULL)
        {
            printf("berhubungan dengan %c: bobot %d; ", r->left->info, r->info);
            r = r->right;
        }
        printf("\n");
        q = q->left;
    }
}

void inputVertices(int n, int A[][n], char str[])
{
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
                p->left = alamat[j];
                printf("berhubungan dengan %c: ", p->left->info);
                printf("bobot %d; ", p->info);
                p->right = r->right;
                r->right = p;
                r = p;
            }
        }
        printf("\n");
        q = q->left;
    }
}

int main()
{
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    int choice;
    printf("Apakah Anda ingin melakukan input vertex atau hanya mencetak vertex?\n");
    printf("1. Input Vertex\n");
    printf("2. Cetak Vertex\n");
    printf("Pilihan Anda: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int A[n][n];

        printf("Masukkan elemen matriks A:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }

        char str[n];
        printf("Masukkan string: ");
        scanf("%s", str);

        inputVertices(n, A, str);
        saveGraphToFile(n, A, str);
        printf("Data telah disimpan di file.\n");
    }
    else if (choice == 2)
    {
        int A[101][101];
        char str[101];

        loadGraphFromFile(&n, A, str);
        printGraph(n, A, str);
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }

    return 0;
}
