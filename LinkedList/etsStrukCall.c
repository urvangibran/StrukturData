#include <stdio.h>

void call(int, int, int);

int main()
{
    int a = 10;
    // call(a, ++a, a++);
    // call(a, a++, ++a);
    // call(a++, a++, ++a);
    // call(a, ++a, ++a);
    // call(a++, ++a, ++a);
    call(a++, ++a, a++);
    return 0;
}

try (int a)
{
    printf("%d", a);
}

void call(int x, int y, int z)
{
    printf("%d %d %d\n", x, y, z);
}
