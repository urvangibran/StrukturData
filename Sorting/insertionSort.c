#include <stdio.h>
#include <stdlib.h>

void cetak(int max, int x[])
{
    int d;
    for (d = 0; d < max; d++)
    {
        printf("%2d\t", x[d]);
    }
    printf("\n");
}

void swap(int x, int y, int datanya[])
{
    int temp;
    temp = datanya[x];
    datanya[x] = datanya[y];
    datanya[y] = temp;
}

void insertionSort(int max, int a[])
{
    int i, k, count = 1;
    for (i = 1; i < max; i++)
        for (k = i; k > 0 && a[k] < a[k - 1]; k--)
        {
            swap(k, k - 1, a);
            printf("swap ke %2d \t", count++);
            cetak(max, a);
        }
}

int main()
{
    int data[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int max = 8;
    printf("data awal \t");
    cetak(max, data);
    insertionSort(max, data);
}