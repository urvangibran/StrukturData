#include <stdio.h>

int main() {
    int num[] = {8, 3, 2, 1, 6, 9, 10};
    int temp, len = sizeof(num) / sizeof(num[0]);

    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            while(num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(int i=0; i<len; i++)
        printf("%d, ", num[i]);
}