#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define cls system("cls")

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
    char NIK[20];
    char place[20];
    char TL[20];
    int umur;

    struct Alamat alamat;
};

int cnt = 0;

void inputKTP(){
    cls;

    FILE *fp;
    struct DataKTP data = 
    {"", "", "", "", "", "", "", "", "", 0, "", "", "", "", "", 0, 0};

    fp = fopen("data.bin", "rb+");
    if(fp  == NULL){
        printf("\nFile could not be opened.\n");
        fclose(fp);
    }
    else{
        char NIKCek[20];
        printf("(Masukkan 0 jika ingin kembali)\n\n");
        printf("INPUT DATA KTP MAHASISWA\n");
        printf("NIK \t\t\t : ");
        fflush(stdin);
        gets(NIKCek);
        int find = 0;
        while(!feof(fp)){
            fread(&data, sizeof(struct DataKTP), 1, fp);
            if (!strcmp(data.NIK, NIKCek)) find++;
        }
        if(!strcmp(NIKCek, "0")) getch();
        else if(find > 0)  printf("NIK Sudah Terdaftar\n");
        else {
            strcpy(data.NIK, NIKCek);
            printf("Nama Mahasiswa \t\t : ");
            gets(data.nama);
            printf("Jenis Kelamin \t\t : ");
            gets(data.gender);
            printf("TTL (Place, dd-mm-yyy) \t : ");
            gets(data.TL);
            printf("Umur \t\t\t : ");
            scanf("%d", &data.umur);
            fflush(stdin);
            printf("Alamat \t\t\t : ");
            gets(data.alamat.jalan);
            printf("\ta) RT \t\t : ");
            scanf("%d", &data.alamat.RT);
            printf("\tb) RW \t\t : ");
            scanf("%d", &data.alamat.RW);
            fflush(stdin);
            printf("\tc) Kelurahan \t : ");
            gets(data.alamat.Kel);
            printf("\td) Kecamatan \t : ");
            gets(data.alamat.Kec);
            printf("\te) Kabupaten \t : ");
            gets(data.alamat.Kab);
            printf("\tf) Provinsi \t : ");
            gets(data.alamat.Prov);
            printf("Agama \t\t\t : ");
            gets(data.agama);
            printf("Pekerjaan \t\t : ");
            gets(data.pekerjaan);
            printf("Golongan Darah \t\t : ");
            gets(data.golDarah);
            printf("Status Perkawinan \t : ");
            gets(data.statusPerkawinan);

            int p=atoi(data.NIK);
            fseek(fp, (p-1) * sizeof(struct DataKTP), SEEK_SET);
            fwrite(&data, sizeof(struct DataKTP), 1, fp);
        }
        fclose(fp);
    }
}

int displayKTP(){
    cnt = 0;
    cls;

    FILE *fp;
    struct DataKTP data = 
    {"", "", "", "", "", "", "", "", "", 0, "", "", "", "", "", 0, 0};

    fp = fopen("data.bin", "rb");
    if(fp == NULL){
        printf("\nFile could not be opened.\n");
        fclose(fp);
    }
    else{
        int find = 0;
        while(!feof(fp)){
            if(fread(&data, sizeof(struct DataKTP), 1, fp)){
                if(strcmp(data.NIK, "000") && strcmp(data.nama, "")){
                    if(find == 0){
                        printf("==================================================\n");
                        printf("==\t\tDATA KTP MAHASISWA\t\t==\n");
                        printf("==================================================\n");
                    }
                    printf("NIK \t\t : %s\n", data.NIK);
                    printf("Nama Mahasiswa \t : %s\n", data.nama);
                    printf("TTL \t\t : %s\n", data.TL);
                    printf("Umur \t\t : %d\n", data.umur);
                    printf("Jenis Kelamin \t : %s\n", data.gender);
                    printf("Golongan Darah \t : %s\n", data.golDarah);
                    printf("Agama \t\t : %s\n", data.agama);
                    printf("Pekerjaan \t : %s\n", data.pekerjaan);
                    printf("Alamat \t\t : %s\n", data.alamat.jalan);
                    printf("   RT/RW \t : %d/%d\n", data.alamat.RT, data.alamat.RW);
                    printf("   Kel/Desa \t : %s\n", data.alamat.Kel);
                    printf("   Kecamatan \t : %s\n", data.alamat.Kec);
                    printf("   Kabupaten \t : %s\n", data.alamat.Kab);
                    printf("   Provinsi \t : %s\n", data.alamat.Prov);
                    printf("Status Perkawinan: %s\n", data.statusPerkawinan);
                    printf("Berlaku Hingga \t : Seumur Hidup\n\n");
                    cnt++;
                    find = 1;
                }
            }
        }
        if(find == 0) printf("Belum ada data KTP mahasiswa.");
        printf("Jumlah Data \t : %d\n", cnt);
        fclose(fp);
    }
}

void cariKTP(){
    cls;

    FILE *fp;
    struct DataKTP data = 
    {"", "", "", "", "", "", "", "", "", 0, "", "", "", "", "", 0, 0};
    fp = fopen("data.bin", "rb+");

    if(fp == NULL){
        printf("\nFile could not be opened.\n");
        fclose(fp);
    }else{
    printf("Masukkan NIK yang dicari \t : ");
    char cariNIK[20];
    scanf("%s", cariNIK);

    int p = atoi(cariNIK);
    fseek(fp, p*sizeof(struct DataKTP), SEEK_SET);
    if(fread(&data, sizeof(struct DataKTP), 1, fp) == 0){
        printf("GAADA");
    }else{
    printf("NAMA : %s", data.nama);
    printf("NIK : %d", data.NIK);
    }
}
    fclose(fp);
}

void hapusData(){
    
    // cls;

    // FILE *fp;
    // struct DataKTP data = 
    // {"", "", "", "", "", "", "", "", "", 0, "", "", "", "", "", 0, 0};

    // fp = fopen("data.bin", "rb+");
    // if(fp == NULL){
    //     printf("\nFile could not be opened.\n");
    //     fclose(fp);
    // }
    // else{
    //     printf("Masukkan NIK yang ingin dihapus : ");
    //     char cariNIK[20];
    //     scanf("%s", cariNIK);

    //     while(!feof(fp)){
    //         fread(&data, sizeof(struct DataKTP), 1, fp);
    //         if(!strcmp(data.NIK, cariNIK)){
    //             strcpy(data.NIK, "");
    //             strcpy(data.nama, "");
    //             strcpy(data.TL, "");
    //             data.umur = 0;
    //             strcpy(data.gender, "");
    //             strcpy(data.golDarah, "");
    //             strcpy(data.agama, "");
    //             strcpy(data.pekerjaan, "");
    //             strcpy(data.alamat.jalan, "");
    //             data.alamat.RT = 0;
    //             data.alamat.RW = 0;
    //             strcpy(data.alamat.Kel, "");
    //             strcpy(data.alamat.Kec, "");
    //             strcpy(data.alamat.Kab, "");
    //             strcpy(data.alamat.Prov, "");
    //             strcpy(data.statusPerkawinan, "");
    //             break;
    //         }
    //     }
    // }
    // fclose(fp);

    cls;

    FILE *fp;
    struct DataKTP data = 
    {"", "", "", "", "", "", "", "", "", 0, "", "", "", "", "", 0, 0};

    printf("Apakah Anda Ingin Menghapus Data?\n");
    printf("1. Ya\n");
    printf("2. Tidak\n");
    printf("Masukkan pilihan : ");
    int op;
    scanf("%d", &op);

    switch(op){
        case 1 : 
            fp = fopen("data.bin", "wb+");
            fputs("", fp);
            printf("\nData berhasil dihapus.\n");
            break;
        case 2 : 
            printf("\nData tidak jadi dihapus.\n");
            break;
    
    fclose(fp);
}
}
