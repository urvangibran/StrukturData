#include<stdio.h>
#include<string.h>

struct Date{
    char tempat[15];
    int tanggal, bulan, tahun;
};

struct Alamat{
    char jalan[20], Kel[20], Kec[20], Prov[20];
    int RT, RW; 
};

struct DataKTP{
    char nama[100], gender[15], golDarah[5], agama[10], Pekerjaan[20];
    int NIK, umur, statusPerwakinan;

    struct Date TTL;
    struct Alamat alamat;
};

int main(){
    int option;
    struct DataKTP mahasiswa[15];

    int cnt = 0;
    while(1){
    printf("Menu Utama:\n\n");
    printf("1. Entri KTP\t\n");
    printf("2. Lihat KTP\t\n");
    printf("3. Exit\n");
    printf("Pilih Opsi Berapa: ");
    scanf("%d", &option);
    cnt++;
    switch (option){
    case 1:
        printf("Masukkan Entri KTP Anda:\n");
        for(int i=0;i<;i++){
        // printf("Nama\t: ");
        // fgets(mahasiswa[i].nama, 100, stdin);
        printf("NIK\t: ");
        scanf("%d", &mahasiswa[i].NIK);
        printf("Umur\t: ");
        scanf("%d", &mahasiswa[i].umur);
        }
        break;
    case 2:
        printf("Data KTP\t:\n");
            printf("%d\n", cnt);
        for(int i=0;i<cnt;i++){
            //printf("Nama\t: %s", mahasiswa[i].nama);
            printf("NIK\t: %d\n", mahasiswa[i].NIK);
            printf("Umur\t: %d\n", mahasiswa[i].umur);
        }
        break;
    case 3:
        printf("Berhasil Keluar.");
        return 0;
    default:
        printf("Pilih angka yang sesuai!");
        break;
    }
    }





    
}