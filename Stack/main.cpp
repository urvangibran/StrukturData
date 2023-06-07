#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct grades{
    int matematika;
    int indonesia;
    int inggris;
    int kejuruhan;
    float mean;
};
struct person{
    char name[200];
};
struct info{
    struct person mahasiswa;
    struct grades nilai;
};
struct info infoMahasiswa[100];
int banyakMahasiswa = 0;

float rata(float a, float b, float c, float d){
    float x = (a+b+c+d)/4;
    return x;
}
struct info tambahMahasiswa(){
    char name[200];
    int mat, indo, ing, kej;
    float mean;

    printf("================================\n");
    printf("INPUT MAHASISWA");
    printf("================================\n");
    fflush(stdin);
    printf("Nama Mahasiswa \t\t : ");
    gets(name);

    printf("Nilai Matematika \t : ");
    scanf("%d", &mat);

    printf("Nilai Bahasa Indonesia \t : ");
    scanf("%d", &indo);
    printf("Nilai Bahasa Inggris \t : ");
    scanf("%d", &ing);
   
    printf("Nilai Kejuruhan \t : ");
    scanf("%d", &kej);

    mean = rata(mat, indo, ing, kej);

    struct info infoBaru = {"",{mat,indo,ing,kej,mean}};
    strcpy(infoBaru.mahasiswa.name, name);

    return infoBaru;
}
void lihatMahasiswa(){
    printf("================================\n");
    printf("Data Mahasiswa Baru");
    printf("================================\n");

    for(int i = 0; i < banyakMahasiswa; i++){
        struct info siswa = infoMahasiswa[i];
        printf("\nMahasiswa ke-%d\n", i+1);
        printf("Nama Mahasiswa \t\t : %s\n", siswa.mahasiswa.name);
        printf("Nilai Matematika \t : %d\n", siswa.nilai.matematika);
        printf("Nilai Bahasa Indonesia\t : %d\n", siswa.nilai.indonesia);
        printf("Nilai Bahasa Inggris\t : %d\n", siswa.nilai.inggris);
        printf("Nilai Kejuruhan \t : %d\n", siswa.nilai.kejuruhan);
        printf("Rata-Rata Nilai \t : %.2f\n", siswa.nilai.mean);
    }
}
int main(){

    int input = 0;
    do{
        system("cls");
        printf("================================\n");
    printf("Program Mahasiswa");
    printf("================================\n");
    printf("1. Input Mahasiswa\n");
    printf("2. Data Mahasiswa\n");
    printf("3. Exit\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &input);
    switch(input){
        case 1 :
            system("cls");
            infoMahasiswa[banyakMahasiswa++] = tambahMahasiswa();
            printf("\nPress any key to continue . . .");
            getch();
        break;
        case 2 :
            system("cls");
            lihatMahasiswa();
            getch();
        break;
        }
    }
    while(input!=3);
    return 0;
}