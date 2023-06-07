#include <stdio.h>

#define size 7

int arr[size];

void init()
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d masuk pada arr[%d]\n", value, key);
    }
    else
    {
        printf("Terjadi Collision : arr[%d] sudah ada value, yaitu %d \n", key, arr[key]);
        while (key)
        {
            if (arr[key] == -1)
            {
                arr[key] = value;
                printf("lalu nilai %d masuk pada arr[%d]\n", value, key);
                break;
            }
            key++;
        }
    }
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n", value);
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void printHash()
{
    int i;
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    init();
    insert(10); // key = 10 % 7 ==> 3
    insert(4);  // key = 4 % 7  ==> 4
    insert(2);  // key = 2 % 7  ==> 2
    insert(3);  // key = 3 % 7  ==> 3 (collision)

    printf("Hash table\n");
    printHash();
    printf("\n");

    return 0;
}