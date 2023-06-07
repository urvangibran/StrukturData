#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fungsi.h"
#define cls system("cls")

int main(){
    int option = 0, option2 = 0, option3 = 0, a = 1;    
    while(a > 0){
    cls;
    printf("Menu Utama:\n\n");
    printf("1. Entri KTP\t\n");
    printf("2. Lihat KTP\t\n");
    printf("3. Exit\n");
    printf("Masukkan pilihan : ");
    scanf("%d", &option);
    switch(option){
        case 1 : 
            cls;
            printf("1. Tambah Data\t\n");
            printf("2. Hapus Data\t\n");
            printf("3. Kembali Ke Menu\n");
            printf("Masukkan pilihan : ");
            scanf("%d", &option2);
            switch(option2){
                case 1 : 
                    cls;
                    inputKTP();
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
                case 2 :
                    cls;
                    hapusData();
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
            }
            break;
        case 2 :
            cls;
            printf("1. Lihat Semua Data KTP\n");
            printf("2. Cari Data KTP\n");
            printf("3. Kembali Ke Menu\n");
            printf("Masukkan pilihan : ");
            scanf("%d", &option3);
            switch(option3){
                case 1 : 
                    cls;
                    displayKTP();
                    printf("\nPress any key to back to the menu . . .");
                    getch();
                    break;
                case 2 :
                    cls;
                    cariKTP();

                    printf("\n\nPress any key to back to the menu . . .");
                    getch();
                    break;
            }
            break;
        case 3 : 
            printf("\n\nBerhasil Keluar.");
            return 0;
    }a++;
    }
}