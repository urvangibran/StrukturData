#include<stdio.h>
//typedef 
struct Point{
	char Nama[100];
} Point[999];
unsigned long long int NIM[999];
int array_size;

int main() {
	printf("Data untuk berapa orang mahasiswa? ");
	scanf("%d", &array_size);
	printf("\n");
	int i;
    for (i = 0; i < array_size; ++i){
		printf("Masukkan nama mahasiswa ke-%d: ", i+1);
		fgets(Point[i].Nama, 100, stdin);
    	scanf("%[^\n]s",Point[i].Nama);
    	printf("Masukkan NIK mahasiswa ke-%d: ", i+1);
        scanf("%llu", &NIM[i]);
	}
	printf("\n");
    for (i = 0; i < array_size; ++i){
        printf("Nama mahasiswa ke-%d: %s\n", i+1, Point[i].Nama);
        printf("NIK mahasiswa ke-%d: %llu\n", i+1, NIM[i]);
	}
    return 0;
}