#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct mahasiswa_t
{
    char *nama;
    int nim;
    struct mahasiswa_t *next, *prev;
} Mahasiswa;

Mahasiswa *head, *tail;

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
        // P->next = NULL;
        // P->prev = NULL;
        P->nama = (char *)malloc(strlen(nama));
        strcpy(P->nama, nama);
        P->nim = nim;
    }
    return (P);
}

void AddFirst(Mahasiswa **p, char *nama, int nim)
{
    Mahasiswa *newNode = alokasi(nama, nim);
    if (*p == NULL)
    {
        *p = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = *p;
        (*p)->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        *p = newNode;
    }
    head = tail->next;
}

void AddLast(Mahasiswa **p, char *nama, int nim)
{
    Mahasiswa *temp;
    Mahasiswa *newNode = alokasi(nama, nim);
    if (*p == NULL)
    {
        *p = newNode;
        head = tail = newNode;   
    }
    else
    {
        temp = *p;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        tail = newNode; 
    }
}

void Cetak(Mahasiswa **p)
{
    system("cls");
    printf("DATA KESELURUHAN MAHASISWA\n");
    Mahasiswa *temp = *p;
    while (temp->next != head)
    {
        printf("%s\t\t %d\n", temp->nama, temp->nim);
        temp = temp->next;
    }
    printf("%s\t\t %d\n", temp->nama, temp->nim);
    // getch();
}

int main()
{
    Mahasiswa *head;
    init(&head);
    while (1)
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
            printf("1. Add First\n");
            printf("2. Add Last\n");
            printf("Masukkan Pilihan: ");
            int option2;
            scanf("%d", &option2);
            switch (option2)
            {
            case 1:
                system("cls");
                printf("Masukkan Nama\t: ");
                char nama[100];
                int nim;
                scanf(" %[^\n]s", nama);
                printf("Masukkan NIM\t: ");
                scanf("%d", &nim);
                AddFirst(&head, nama, nim);
                break;
            case 2:
                system("cls");
                printf("Masukkan Nama\t: ");
                scanf(" %[^\n]s", nama);
                printf("Masukkan NIM\t: ");
                scanf("%d", &nim);
                AddLast(&head, nama, nim);
                break;
            }
            break;
        case 2:
            Cetak(&head);
            return 0;
        default:
            printf("Opsi tidak tersedia.\n");
            getch();
        }
    }
}
