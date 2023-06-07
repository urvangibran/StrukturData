#include <stdio.h>
typedef long long ll;

ll pangkat(ll x, ll y)
{
    int i; ll res = x;
    for(i = 0; i < y - 1; i++)
    {
        res*=x;
    }
    return res;
}

int main()
{
    ll x, y;
    scanf("%lld %lld", &x, &y);
    if(y < 0)
    {
        printf("1 / %lld ", pangkat(x,y));
    }
    else
    {
        printf("%lld", pangkat(x, y));
    }
    return 0;
}