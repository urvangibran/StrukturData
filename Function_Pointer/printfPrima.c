#include <stdio.h>
#include <stdbool.h>

bool cekPrima(int n)
{
    bool cek = 1;
    if(n == 1 || n == 0)
        cek = 0;

    int i;
    for(i = 2; i*i <= n; i++)
    {
        if(n % i == 0) cek = 0;
    }

    return cek;
}

int main()
{
    int num;
    scanf("%d", &num);
    int i;
    for(i = 0; i <= num; i++)
    {
        if(cekPrima(i)) printf("%d ", i);
    }


    return 0;
}