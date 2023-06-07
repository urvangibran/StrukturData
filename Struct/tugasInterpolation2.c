#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "func_Interpolation.h"

int main(){
    int option = 0, option2 = 0, option3 = 0, a = 1;
    while(a > 0){
    system("cls");
    printf("Menu Utama:\n\n");
    printf("1. Entri KTP\t\n");
    printf("2. Lihat KTP\t\n");
    printf("3. Exit\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &option);
    switch(option){
        case 1 :
            system ("cls");
            printf("1. Tambah Data\t\n");
            printf("2. Hapus Data\t\n");
            printf("3. Kembali Ke Menu\n");
            printf("Masukkan pilihan : ");
            scanf("%d", &option2);
            switch(option2){
                case 1 :
                    system ("cls");
                    dataMahasiswa[cntMahasiswa] = tambahData();
                    cntMahasiswa++;
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
                case 2 :
                    system ("cls");
                    hapusData();
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
            }
            break;
    case 2 : 
         if(cntMahasiswa == 0){
                system("cls");
                printf("Data Mahasiswa Belum Ada."); 
                printf("\n\n\n\nPress any key to back to the menu . . .");
                getch();
                break;
        }else{
        system("cls");
        printf("1. Lihat Semua Data KTP\n");
        printf("2. Cari Data KTP\n");
        printf("3. Kembali Ke Menu\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &option3);
        switch(option3){
            case 1 :
                system ("cls");
                sortingData(dataMahasiswa, cntMahasiswa);
                displayData();
                printf("\nPress any key to back to the menu . . .");
                getch();
                break;
            case 2 :
                system ("cls");
                long long NIKSearch;
                printf("Masukkan NIK : ");
                scanf("%lld", &NIKSearch);

                int res;
                res = ipSearch(dataMahasiswa, cntMahasiswa, NIKSearch);
                if(res == -1) {
                    system("cls");
                    printf("-------\t     DATA TIDAK DITEMUKAN    \t-------\n");
                }
                else{
                    displaySearch(res);
                }

                    printf("\n\n\nPress any key to back to the menu . . .");
                    getch();
                    break;
                    }
        }
        break;
    case 3 :
        printf("\n\nBERHASIL KELUAR.");
        return 0;
    } a++;
    }
}