#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct mahasiswa_t
{
    char *nama;
    int nim;
    struct mahasiswa_t *next;
} Mahasiswa;

void init(Mahasiswa **p)
{
    *p = NULL;
}

Mahasiswa *alokasi(char *nama, int nim)
{
    Mahasiswa *P;
    P = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    if (P != NULL)
    {
        P->next = NULL;
        P->nama = (char *)malloc(strlen(nama));
        strcpy(P->nama, nama);
        P->nim = nim;
    }
    return (P);
}

void Add(Mahasiswa **p, char *nama, int nim)
{
    Mahasiswa *newNode = alokasi(nama, nim);
    if (*p == NULL)
    {
        *p = newNode;
    }
    else
    {
        newNode->next = *p;
        *p = newNode;
    }
}

void Cetak(Mahasiswa **p)
{
    system("cls");
    printf("DATA KESELURUHAN MAHASISWA\n");
    Mahasiswa *temp = *p;
    while (temp != NULL)
    {
        printf("%s\t\t %d\n", temp->nama, temp->nim);
        temp = temp->next;
    }
    getch();
}

int main()
{
    Mahasiswa *head;
    init(&head);
    while(1)
    {
        system("cls");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Masukkan Opsi: ");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("Masukkan Nama\t: ");
            char nama[100]; int nim;
            scanf(" %[^\n]s", nama);
            printf("Masukkan NIM\t: ");
            scanf("%d", &nim);
            Add(&head, nama, nim);
            break;
        case 2:
            Cetak(&head);
            // return 0;
            break;
        default:
            printf("Opsi tidak tersedia.\n");
            getch();
        }
    }
}
