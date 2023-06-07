#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cls system("cls");

typedef struct TNode_t
{
    int data;
    char nama[40];

    struct Tnode *next;
} TNode;

typedef struct LinkedList_t
{
    TNode *head, *tail;
} Linked;

void init(Linked *node)
{
    node->head = NULL;
    node->tail = NULL;
}

int isEmpty(Linked *node)
{
    if (node->tail == NULL)
        return 1;
    else
        return 0;
}

void insertFront(Linked *node, int value, char *nama)
{
    TNode *newNode;
    newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = value;
    strcpy(newNode->nama, nama);
    newNode->next = NULL;
    if (isEmpty(node))
    {
        node->head = node->tail = newNode;
        node->tail->next = node->head;
    }
    else
    {
        newNode->next = node->head;
        node->tail->next = newNode;
        node->head = newNode;
    }
    printf("Data Depan Berhasil Ditambahkan\n");
}

void insertMiddle(Linked *node, int value, char *nama, int pos)
{
    TNode *newNode;
    newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = value;
    strcpy(newNode->nama, nama);
    newNode->next = NULL;
    if (isEmpty(node))
    {
        node->head = node->tail = newNode;
        node->tail->next = NULL;
    }
    else
    {
        TNode *temp;
        temp = node->head;
        int idx = 0;
        while (temp->next != node->head && idx < pos - 2)
        {
            temp = temp->next;
            idx++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBack(Linked *node, int value, char nama[])
{
    TNode *newNode, *temp;
    newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = value;
    strcpy(newNode->nama, nama);
    newNode->next = NULL;
    if (isEmpty(node))
    {
        node->head = newNode;
        node->tail = newNode;
        node->tail->next = node->head;
    }
    else
    {
        node->tail->next = newNode;
        newNode->next = node->head;
        node->tail = newNode;
    }
    printf("Data Belakang Berhasil Ditambahkan");
}

void removeFirst(Linked *node)
{
    TNode *del;
    int d;
    char nama[30];
    if (!isEmpty(node))
    {
        if (node->head != node->tail)
        {
            del = node->head;
            d = del->data;
            strcpy(nama, del->nama);
            node->head = node->head->next;
            node->tail->next = node->head;
            del->next = NULL;
            free(del);
        }
        else
        {
            d = node->tail->data;
            strcpy(nama, node->tail->nama);
            node->head = node->tail = NULL;
        }
        printf("%s %d terhapus\n", nama, d);
    }
    else
    {
        printf("Masih Kosong\n");
    }
}

void removeLast(Linked *node)
{
    TNode *del;
    int d;
    char nama[30];
    if (!isEmpty(node))
    {
        if (node->head != node->tail)
        {
            del = node->tail;
            d = del->data;
            strcpy(nama, del->nama);
            TNode *temp;
            // transversing
            temp = node->head;
            while (temp->next != node->tail)
                temp = temp->next;
            node->tail = temp;
            temp->next = node->head;
            del->next = NULL;
            free(del);
        }
        else
        {
            d = node->tail->data;
            strcpy(nama, node->tail->nama);
            node->head = node->tail = NULL;
        }
        printf("%s %d terhapus\n", nama, d);
    }
    else
    {
        printf("Masih Kosong\n");
    }
}

void display(Linked *node)
{
    TNode *temp;
    temp = node->head;
    cls;
    if (!isEmpty(node))
    {
        printf("DATA KESELURUHAN MAHASISWA\n");
        while (temp->next != node->head)
        {
            printf("%s\t %d\n", temp->nama, temp->data);
            temp = temp->next;
        }
        printf("%s\t %d\n", temp->nama, temp->data);
    }
    else
    {
        printf("Data Kosong\n");
    }
}

int main()
{
    Linked urutan;
    init(&urutan);
    while (1)
    {

        cls;
        printf("1. Input Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampil Data\n");
        printf("Masukkan Pilihan: ");
        int opt;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            cls;
            printf("1. Input Depan\n");
            printf("2. Input Belakang\n");
            printf("3. Input At\n");
            printf("Masukkan Pilihan: ");
            int opt_1;
            scanf("%d", &opt_1);
            switch (opt_1)
            {
                int nim;
                char nama[30];
            case 1:
                cls;
                fflush(stdin);
                printf("Nama \t: ");
                scanf("%[^\n]*c", nama);
                printf("NIM \t: ");
                scanf("%d", &nim);
                insertFront(&urutan, nim, nama);
                getch();
                break;
            case 2:
                cls;
                fflush(stdin);
                printf("Nama \t: ");
                scanf("%[^\n]", nama);
                printf("NIM \t: ");
                scanf("%d", &nim);
                insertBack(&urutan, nim, nama);
                getch();
                break;
            case 3:
                cls;
                int at;
                fflush(stdin);
                printf("Nama \t: ");
                scanf("%[^\n]*c", nama);
                printf("NIM \t: ");
                scanf("%d", &nim);
                printf("Input data ke-: ");
                scanf("%d", &at);
                insertMiddle(&urutan, nim, nama, at);
            }
            break;
        case 2:
            cls;
            printf("1. Hapus Depan\n");
            printf("2. Hapus Belakang\n");
            printf("3. Hapus At\n");
            printf("Masukkan pilihan: ");
            int opt_2;
            scanf("%d", &opt_2);
            switch (opt_2)
            {
            case 1:
                removeFirst(&urutan);
                getch();
                break;
            case 2:
                removeLast(&urutan);
                getch();
            }
            break;
        case 3:
            display(&urutan);
            getch();
            // return 0;
            break;
        default:
            printf("Opsi tidak tersedia");
        }
    }
}
