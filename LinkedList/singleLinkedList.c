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
        node->tail->next = NULL;
    }
    else
    {
        newNode->next = node->head;
        node->head = newNode;
    }
    printf("Data Masuk\n");
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
        while (temp->next != NULL && idx < pos - 2)
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
        node->tail->next = NULL;
    }
    else
    {
        node->tail->next = newNode;
        node->tail = newNode;
    }
    printf("Data Masuk");
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

void reverse(Linked *node) {
    TNode *prev = NULL;
    TNode *current = node->head;
    TNode *selanjutnya;
    while(current->data != NULL)
    {
        selanjutnya = current->next;
        current->next = prev;
        prev = current;
        current = selanjutnya;
    }
    node->head = current;
}

void display(Linked *node)
{
    cls;
    TNode *temp;
    temp = node->head;
    printf("DATA KESELURUHAN MAHASISWA\n");
    if (!isEmpty(node))
    {
        while (temp->data != NULL)
        {
            printf("%s\t %d\n", temp->nama, temp->data);
            temp = temp->next;
        }
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
                scanf("%d",&at);
                insertMiddle(&urutan, nim, nama, at);

            }
            break;
        case 2:
            cls;
            printf("1. Hapus Depan\n");
            printf("2. Hapus Belakang\n");
            printf("3. Hapus At\n");
            printf("4. Masukkan pilihan: ");
            int opt_2;
            scanf("%d", &opt_2);
            switch (opt_2)
            {
            case 1:
                removeFirst(&urutan);
                break;
            }
            break;
        case 3:
            display(&urutan);
            return 0;
        default:
            printf("Opsi tidak tersedia");
        }
    }
}
