#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nilai, index;
    char huruf[5] = {'E', 'A', 'B', 'D', 'G'};
    scanf("%d", &nilai);
    index = nilai / 10;
    if (index < 6)
    {
        index = 0;
    }
    else
    {
        index = index - 5;
    }
    printf("nilai = %d konversi = %c", nilai, huruf[index]);
    return 0;
}