#include <stdio.h>
typedef unsigned long long ull;

ull faktorial(int n)
{
    ull i, res = 1;
    for(i = 2; i <= n; i++)
    {
        res*=i;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%llu ", faktorial(n));
    return 0;
}