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

void selectionSort(int max, int a[])
{
    int i, j,k, count = 1;
    for (i = 0; i < max; i++)
    {
        k = i;
        for (j = i + 1; j < max; j++)
            if (a[j] < a[k])
                k = j;
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
    selectionSort(max, data);
}