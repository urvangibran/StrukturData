#include <stdio.h>
#include <stdlib.h>

typedef struct big {
    int x, y;
} Big, *BigPtr;

int main() {
    BigPtr a = (BigPtr) malloc (sizeof(BigPtr));

    a->x = 10;
    a->y = a->x + 13;
    
    printf("%d", a->y); 
}