#include<stdio.h>
using namespace std;

int main(int argc,char *argv[]){
 FILE *file,*copy;
 if(argc!=3){
  printf("Invalide numbers of arguments.");
  return 1;}

 file=fopen(argv[1],"rb");
 if(file==NULL){
  printf("Can't find the source file.");
  return 1;}

 copy=fopen(argv[2],"wb");
 if(copy==NULL) {
  printf("Can't open target file.");
  fclose(file);
  return 1;}

 int ch;
 while(1){
  ch=fgetc(file);
  if (feof(file)) break;
  fputc(ch,copy);
 }
 fclose(file);
 fclose(copy);
 return 0;
}


