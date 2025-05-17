#include <stdio.h>
#include <stdlib.h>

char filename[30]="file.txt";

int filecontrol();
void printfile();
void filedel();

int main(){

    printf("Silmek istediginiz dosyanin ismini girin: ");
    scanf("%29s", filename);

    printfile();
    filedel();

    return 0;
}

int filecontrol() {
    FILE *file = fopen(filename, "r");

    if (file) {
        printf("Dosya mevcut: %s\n", filename);
        fclose(file);
        return 1;
    } else {
        printf("Dosya bulunamadi: %s\n", filename);
        return 0;
    }

}

void filedel() {
    if (filecontrol()==0) {
        printf("Silme islemi basarisiz.\n");
        return;
    }

    if (remove(filename) == 0) {
        printf("Dosya basariyla silindi!\n");
    } else {
        printf("Dosya silinemedi!\n");
    }
}

void printfile(){
    FILE *file=fopen(filename, "r");

    if(file!=NULL){
        
        printf("\n---DOSYA ICERIGI---\n");
        int a;

        while((a=fgetc(file)) != EOF){
            putchar(a);
        }
        fclose(file);
    }
}
