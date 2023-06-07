#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};
   
// main menu
int pergiToMain() {
    printf("Lanjut ke main ? ( ketik 1)\n");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int mainMenu() {
    system("cls");
    printf("PILIH FUNGSI - FUNGSI BERIKUT :\n");
    printf("(ketik 1) Masukkan data ke Linked list\n");
    printf("(ketik 2) Lihat data Linked list\n");
    printf("(ketik 3) Delete data Linked List\n");
    printf("(ketik 4) Keluar\n");

    int opsi;
    scanf("%d", &opsi);
    if (opsi == 4) {
        exit(1);
    }
    return opsi;
}


void pilihMetodeInsertData(){
     printf("Masukkan data dari :\n");
        printf("(ketik 1) Depan\n");
        printf("(ketik 2) Belakang\n");
        printf("(ketik 3) Posisi tertentu\n");
}

void pilihMetodeLihatData(){
    printf("Lihat :\n");
    printf("(ketik 1) Semua data\n");
    printf("(ketik 2) Data tertentu\n");
}

void pilihMetodeDeleteData() {
    printf("Delete :\n");
    printf("(ketik 1) Semua data\n");
    printf("(ketik 2) Data tertentu\n");
}

void inputDataFront(struct node **head, struct node **tail) {

    int n, i;
    i = 0;
    printf("Masukkan banyak n input ke node\n");
   
    scanf("%d", &n);
    printf("Masukkan data ke node\n");
    while ( i<n) {
        int x;
        scanf("%d", &x);
        insertFront(head, tail, x );
        i++;
    }
   // pergiToMain();
}

// insert new node (dari belakang)
void insertFront(struct node **head, struct node **tail, int dataBaru){

    struct node *newNode = (struct node *) malloc (sizeof (struct node));

    // jika list masih kosong, artinya head->next = NULL
    if (*head == NULL) {
        *tail = newNode;
    }

    newNode->data = dataBaru;
    newNode->next = *head;

    *head = newNode;
}

void insertBack(struct node **tail, struct node **head, int dataBaru) {

    struct node *newNode = (struct node *) malloc (sizeof(struct node));

    newNode->data = dataBaru;
    newNode->next = NULL;
    if (*tail == NULL) {
        *tail = newNode;
    }
    if ( *head == NULL) {
        *head = newNode;
    }
    else {
        (*tail)->next = newNode;
        *tail = newNode;
    }

}

void inputDataBack(struct node **tail, struct node **head){

    int n, i;
    i = 0;
    printf("Masukkan banyak n input ke node\n");
   
    scanf("%d", &n);
     printf("Masukkan data ke node\n");
    while ( i<n) {
        int x;
        scanf("%d", &x);
        insertBack(tail, head, x);
        i++;
    }
   // pergiToMain();
}

void inputDataSomewhere(struct node **head, struct node **tail) {
    int x;
    printf("Masukkan isi node baru\n");
    scanf("%d", &x);
    insertSomewhere(head, tail, x);

}

void insertSomewhere(struct node **head, struct node **tail, int dataBaru ) {

    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    struct node *temp = *head;

    newNode->data = dataBaru;

    printf("Dimana anda ingin meletakkan data ?\n");
    printf("Setelah bilangan: ");
    int angkaPosisi;
    scanf("%d", &angkaPosisi);
   printf("\nDi alamat:");
  int nextPosisi;
   scanf("%d", &nextPosisi);

    while (temp!=NULL) {
        if ( temp->data == angkaPosisi && temp->next == nextPosisi) {
            // jika setelah tail, maka data baru dijadikan tail
            if (temp->next == NULL) {
                *tail = newNode;
            } 
            newNode->next = temp->next;
            temp->next = newNode;
            printf("\n%d Berhasil disisipkan\n", dataBaru);
            break;
        }
        temp = temp->next;
    }
}

void searchData(struct node **head) {

    struct node *temp = *head;
    printf("Masukkan data yang anda ingin cari ?\n");
    int dataDicari;
    scanf("%d", &dataDicari);

    while (temp!=NULL) {
        if (temp->data == dataDicari) {
            if ( temp->next == NULL) {
                printf("%d ada di linked list, terletak di ujung belakang linked list\n", dataDicari);
            }
            else {
            temp = temp->next;
            printf("%d ada di linked list, terletak sebelum %d\n", dataDicari, temp->data);
            break;
            }
        }

        temp = temp->next;
    }    


}

 

void display ( struct node *node) {
    printf("Linked List : \n");

    if (isEmpty(node) == 1) {
        printf("/////\n/////\nEMPTY\n/////\n/////\n");
        return;
    }

    while (node!=NULL) {
        printf("[value: %d]-> [next: %d]\n", node->data, node->next);
        node = node->next;
    }
}

void deleteData(struct node **head) {
    struct node* temp = *head;

    if (*head == NULL) {
        printf("Linked list is empty, nothing to delete\n");
        return;
    }

    *head = (*head)->next; // Menggeser node paling belakang ke node selanjutnya
    printf("\nData %d sudah dihapus", temp->data);
    free(temp); // Menghilangkan alokasi data node yang dihapus

}



void deleteSomeData(struct node **head){

    
    struct node *temp = *head;
    struct node *belakang = *head;

    int dataYgdihapus;
    printf("Masukkan data yang ingin dihapus ?\n");
    scanf("%d", &dataYgdihapus);

    if ( temp->data == dataYgdihapus) {
        temp = temp->next;
        return;
    }
    
    temp = temp->next;

    while(temp!=NULL){
        if ( temp->data == dataYgdihapus){ 
            // jika node selanjutnya dari node yg sedang diperiksa  == data yang akan dihapus, maka
        // sambungkan node yg sedang diperiksa ke next data yg akan dihapus
            temp = temp->next;
            belakang->next = temp;

            printf("\nData %d sudah dihapus\n", dataYgdihapus);
           // free(temp);
            //free(belakang);
            break; 
        }
       //else {printf("tes\n");}
       belakang = belakang->next;
        temp = temp->next;
    }
}

int isEmpty(struct node **head){
    if (head == NULL) {
        return 1;
    }
    else {return 0;}
}


int main() {
    
    struct node *head = NULL; // di awal head selalu nunjuk NULL
    struct node *tail = NULL;


    int opsi;
    
    while (1) {
     opsi =  mainMenu();
    if ( opsi == 1) {
       pilihMetodeInsertData();
        int opsiInsertData;
        scanf("%d", &opsiInsertData);

        if ( opsiInsertData == 1) {
            inputDataFront(&head, &tail);
        }
        else if (opsiInsertData == 2) {
            inputDataBack(&tail, &head);
        }
        else if (opsiInsertData == 3) {
            display(head);
            inputDataSomewhere(&head, &tail);
        }

        int k = pergiToMain();
        if ( k == 1) {
            continue;
        }else {break;}
    }
    else if ( opsi == 2) {
      //  display(head);
      pilihMetodeLihatData();
      int opsiLihatData;
      scanf("%d", &opsiLihatData);

      if (opsiLihatData == 1) {
        display(head);
      }
      else {
        searchData(&head);
      }

        int k = pergiToMain();
        if ( k == 1) {
            continue;
        }
    }
    else if ( opsi == 3) {
       // while ( head!=NULL) {
        //deleteData(&head);
        //}
        pilihMetodeDeleteData();
        int opsiHapusData;
        scanf("%d", &opsiHapusData);

        if (opsiHapusData == 1){
            while (head!=NULL){
                deleteData(&head);
            }
        }
        else {
            display(head);
            deleteSomeData(&head);
            printf("\n");
            display(head);
        }
       
        int k = pergiToMain();
        if ( k == 1) 
        {continue;} else {break;}
    }
    }

    

   // printf("\n\n\nData akan didelete.....\n");
 //   while ( head != NULL) {
   //     deleteNode(&head);
 //   }
    



    return 0;
}