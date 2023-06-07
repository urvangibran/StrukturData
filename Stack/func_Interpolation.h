#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Alamat{  
    char jalan[20], Kel[20], Kec[20], Kab[20], Prov[20];
    int RT, RW; 
};

typedef struct DataKTP{
    char nama[200];
    char gender[15];
    char golDarah[5]; 
    char agama[10]; 
    char pekerjaan[20];
    char statusPerkawinan[30];
    long long NIK;
    char TTL[50];
    int umur;

    struct Alamat alamat;
};

struct DataKTP dataMahasiswa[50];
int cntMahasiswa = 0;

struct DataKTP tambahData(){
    char nama[200], gender[15], golDarah[5], agama[10], pekerjaan[20], statusPerkawinan[30];
    long long NIK;
    char TTL[50];
    int umur;
    char jalan[20], Kel[20], Kec[20], Kab[20], Prov[20];
    int RT, RW; 

    printf("==================================================\n");
    printf("==\t     INPUT DATA KTP MAHASISWA     \t==\n");
    printf("==================================================\n\n");
    printf("NIK \t\t\t : ");
    scanf("%lld", &NIK);
    fflush(stdin);
    printf("Nama Mahasiswa \t\t : ");
    gets(nama);
    printf("Jenis Kelamin \t\t : ");
    gets(gender);
    printf("TTL (Place, dd-mm-yyy) \t : ");
    gets(TTL);
    printf("Umur \t\t\t : ");
    scanf("%d", &umur);
    fflush(stdin);
    printf("Alamat \t\t\t : ");
    gets(jalan);
    printf("\ta) RT \t\t : ");
    scanf("%d", &RT);
    printf("\tb) RW \t\t : ");
    scanf("%d", &RW);
    fflush(stdin);
    printf("\tc) Kelurahan \t : ");
    gets(Kel);
    printf("\td) Kecamatan \t : ");
    gets(Kec);
    printf("\te) Kabupaten \t : ");
    gets(Kab);
    printf("\tf) Provinsi \t : ");
    gets(Prov);
    printf("Agama \t\t\t : ");
    gets(agama);
    printf("Pekerjaan \t\t : ");
    gets(pekerjaan);
    printf("Golongan Darah \t\t : ");
    gets(golDarah);
    printf("Status Perkawinan \t : ");
    gets(statusPerkawinan);
    
    struct DataKTP dataBaru = 
    {"", "", "", "", "", "", NIK, "",umur, "", "", "", "", "", RT, RW};
    strcpy(dataBaru.nama, nama);
    strcpy(dataBaru.gender, gender);
    strcpy(dataBaru.golDarah, golDarah);
    strcpy(dataBaru.agama, agama);
    strcpy(dataBaru.pekerjaan, pekerjaan);
    strcpy(dataBaru.statusPerkawinan, statusPerkawinan);
    strcpy(dataBaru.TTL, TTL);
    strcpy(dataBaru.alamat.jalan, jalan);
    strcpy(dataBaru.alamat.Kel, Kel);
    strcpy(dataBaru.alamat.Kec, Kec);
    strcpy(dataBaru.alamat.Kab, Kab);
    strcpy(dataBaru.alamat.Prov, Prov);

    return dataBaru;    
}
void hapusData(){






























    
}
void displayData(){
        printf("==================================================\n");
        printf("==\t         DATA KTP MAHASISWA       \t==\n");
        printf("==================================================\n");

        int i;
        for(i = 0; i < cntMahasiswa; i++){
        printf("--------------------------------------------------\n");
        printf("DATA KE-%d\n", i+1);
        printf("NIK \t\t : %lld\n", dataMahasiswa[i].NIK);
        printf("Nama Mahasiswa \t : %s\n", dataMahasiswa[i].nama);
        printf("TTL \t\t : %s\n", dataMahasiswa[i].TTL);
        printf("Umur \t\t : %d\n", dataMahasiswa[i].umur);
        printf("Jenis Kelamin \t : %s\n", dataMahasiswa[i].gender);
        printf("Golongan Darah \t : %s\n", dataMahasiswa[i].golDarah);
        printf("Agama \t\t : %s\n", dataMahasiswa[i].agama);
        printf("Pekerjaan \t : %s\n", dataMahasiswa[i].pekerjaan);
        printf("Alamat \t\t : %s\n", dataMahasiswa[i].alamat.jalan);
        printf("   RT/RW \t : %d/%d\n", dataMahasiswa[i].alamat.RT, dataMahasiswa[i].alamat.RW);
        printf("   Kel/Desa \t : %s\n", dataMahasiswa[i].alamat.Kel);
        printf("   Kecamatan \t : %s\n", dataMahasiswa[i].alamat.Kec);
        printf("   Kabupaten \t : %s\n", dataMahasiswa[i].alamat.Kab);
        printf("   Provinsi \t : %s\n", dataMahasiswa[i].alamat.Prov);
        printf("Status Perkawinan: %s\n", dataMahasiswa[i].statusPerkawinan);
        printf("Berlaku Hingga \t : Seumur Hidup\n\n");
        printf("--------------------------------------------------\n");
        }
}
void sortingData(struct DataKTP dataMahasiswa[], int n){
    struct DataKTP temp;
    int i,j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n ; j++){
            if(dataMahasiswa[i].NIK > dataMahasiswa[j].NIK){
                temp = dataMahasiswa[i];
                dataMahasiswa[i] = dataMahasiswa[j];
                dataMahasiswa[j] = temp;
            }
        }
    }
}
int ipSearch(struct DataKTP a[], int n, long long key){
    int low = 0, high = n-1;
    while(low <= high && key >= a[low].NIK && key <= a[high].NIK){
        if(low == high){
            return low;
            return -1;
        }
        int pos =   low + ((double)(key - a[low].NIK) / 
                    (a[high].NIK - a[low].NIK)) * (high-low);
            
            if(a[pos].NIK == key) return pos;
            if(a[pos].NIK > key) high = pos - 1;
            else low = pos + 1;
    }
    return -1;
}
void displaySearch(int i){
        system("cls");
        printf("-----------------------------------------------\n");
        printf("-------\t         DATA DITEMUKAN      \t-------\n");
        printf("-----------------------------------------------\n");
        printf("DATA KE-%d\n", i+1);
        printf("NIK \t\t : %lld\n", dataMahasiswa[i].NIK);
        printf("Nama Mahasiswa \t : %s\n", dataMahasiswa[i].nama);
        printf("TTL \t\t : %s\n", dataMahasiswa[i].TTL);
        printf("Umur \t\t : %d\n", dataMahasiswa[i].umur);
        printf("Jenis Kelamin \t : %s\n", dataMahasiswa[i].gender);
        printf("Golongan Darah \t : %s\n", dataMahasiswa[i].golDarah);
        printf("Agama \t\t : %s\n", dataMahasiswa[i].agama);
        printf("Pekerjaan \t : %s\n", dataMahasiswa[i].pekerjaan);
        printf("Alamat \t\t : %s\n", dataMahasiswa[i].alamat.jalan);
        printf("   RT/RW \t : %d/%d\n", dataMahasiswa[i].alamat.RT, dataMahasiswa[i].alamat.RW);
        printf("   Kel/Desa \t : %s\n", dataMahasiswa[i].alamat.Kel);
        printf("   Kecamatan \t : %s\n", dataMahasiswa[i].alamat.Kec);
        printf("   Kabupaten \t : %s\n", dataMahasiswa[i].alamat.Kab);
        printf("   Provinsi \t : %s\n", dataMahasiswa[i].alamat.Prov);
        printf("Status Perkawinan: %s\n", dataMahasiswa[i].statusPerkawinan);
        printf("Berlaku Hingga \t : Seumur Hidup\n\n");
        printf("-----------------------------------------------\n");
}
