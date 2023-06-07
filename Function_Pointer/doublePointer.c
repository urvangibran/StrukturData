#include <stdio.h>

int main()
{
    char *arr = "buku";
    char **brr;
    printf("%s", arr);
    brr[0] = "handphone";
    brr[1] = "laptop";
    printf("%s", brr[1]);
}