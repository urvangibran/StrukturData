#include <stdio.h>
#include <string.h>

struct library{
    char judulbuku[100];
};

int main(){
    int jumlahbuku, menu;
    char subjudul[100], *sj;
    char enter;
    printf("masukkan jumlah buku: ");
    scanf("%d", &jumlahbuku);
    scanf("%c", &enter);

    struct library lib[jumlahbuku];

    for(int i=1; i<=jumlahbuku; i++){
        printf("judul %d: ", i);
        gets(lib[i].judulbuku);
    }

    int a=1;
    while(a > 0){
        printf("\nketik nomor menu:\n0. print buku\n1. cari buku\n2. exit\n ketik menu: ");
        scanf("%d", &menu);

    switch(menu){
        case 0:
            printf("Judul buku\n");
            for(int i=1; i<=jumlahbuku; i++){
                printf("\t%d: %s\n", i, lib[i].judulbuku);}
            break;
        case 1:
            printf("\tKetik subjudul buku: ");
            scanf("%s", subjudul);
            for(int i=1; i<=jumlahbuku; i++){
                sj = strstr(lib[i].judulbuku, subjudul);
                if(sj>0){
                    printf("\tbuku ada: %s", lib[i].judulbuku);}}
            break;
        case 2:
            printf("Anda keluar");
            return 0;
        default:
            printf("Anda tidak memilih menu dengan benar");
            break;
    } a++;
}
}