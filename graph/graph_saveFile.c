#include <stdio.h>
#include <stdlib.h>
#define cls system("cls");

typedef struct tipeS
{
    struct tipeS *left;
    int info;
    struct tipeS *right;
} simpul;

simpul *p, *first, *last, *pVertex, *pEdge, *q, *r, *s;
simpul *alamat[101];

void save(int n, int A[n][n], char str[])
{
    FILE *file = fopen("db.txt", "w");
    if (file == NULL)
    {
        printf("File tidak ditemukan");
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

void load(int *n, int A[101][101], char str[])
{
    FILE *file = fopen("db.txt", "r");
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

void printMatrix(int n, int A[101][101], char str[])
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
}

void print(int n, int A[n][n], char str[])
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

int main()
{
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    int opt;
    cls;
    printf("1. Input And Save Vertex\n");
    printf("2. Load And Print Vertex\n");
    printf("Masukakn pilihan: ");
    scanf("%d", &opt);

    if (opt == 1)
    {
        int A[n][n];
        cls;
        printf("Masukkan elemen matriks:\n");
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

        print(n, A, str);
        save(n, A, str);
        printf("Data telah disimpan di file.\n");
    }
    else if (opt == 2)
    {
        int A[n][n];
        char str[n];
        load(&n, A, str);
        print(n, A, str);
        // printMatrix(n, A, str);
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }
    return 0;
}
