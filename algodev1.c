#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "product.bat"

struct product{
    int id;
    char name[20];
    float price;
    int stock;
};

void menu();
void addproducts();
void updateproducts();
void showproducts();     
void deleteproduct();    
void deletefile();
int idcontrol(int id);

int main(){
    menu();
}

void menu(){
    int choice=0;

    do{
        printf("\n--- URUN YONETIMI ---\n");
        printf("1- Urun Ekleme\n");
        printf("2- Stok Guncelleme\n");
        printf("3- Urun Goster\n");
        printf("4- Urun Sil\n");
        printf("5- Dosya Sil\n");
        printf("6- Cikis\n");
        printf("---------------------\n");
        printf("Secim yapin: ");
        scanf("%d",&choice);
        printf("---------------------\n");

        switch(choice){
            case 1:
                addproducts();
            break;
            case 2:
                updateproducts();
            break;
            case 3:
                showproducts();
            break;
            case 4:
                deleteproduct();
            break;
            case 5:
                deletefile();
            break;
            case 6:
                printf("Cikis yapildi\n");
            break;
            default:
                printf("Geçersiz Secim\n");
            break;
        }

    }while(choice!=6);

}

void addproducts(){
    struct product p;
    FILE *file = fopen (FILE_NAME, "ab");

    printf("Urun ID: ");
    scanf("%d",&p.id);

    if (idcontrol(p.id)) {
       printf("Bu ID'ye sahip bir urun zaten var!\n");
       fclose(file);
       return;
    }

    printf("Urun Adi: ");
    scanf("%s", p.name);
    printf("Urun Fiyati: ");
    scanf("%f",&p.price);
    printf("Urun Miktari: ");
    scanf("%d", &p.stock);

    fwrite(&p, sizeof(struct product),1,file);
    fclose(file);
    printf("Urun Eklendi.\n");
}

void updateproducts(){
    struct product p;
    int id, found=0;

    FILE *file =fopen(FILE_NAME, "rb+" );

    printf("Guncellenmek Istenen Urun Id'sini Girin: \n");
    scanf("%d",&id);

       while (fread(&p, sizeof(struct product), 1, file)) {
        if (p.id == id) {
            printf("Mevcut stok: %d\n", p.stock);
            printf("Yeni Urun Stogu: ");
            scanf("%d", &p.stock);

            fseek(file, -sizeof(struct product), SEEK_CUR); // Geri dön
            fwrite(&p, sizeof(struct product), 1, file);
            printf("Stok guncellendi.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Bu ID'ye sahip bir urun bulunamadi.\n");
    }

    fclose(file);
}

void showproducts(){
    struct product p;
    FILE *file = fopen(FILE_NAME, "rb");
    int count=0;
    printf("\n--- URUN BILGISI ---\n");

    while (fread(&p, sizeof(struct  product), 1, file)) {
        if (p.id > 0) {
            printf("ID: %d, Adi: %s, Fiyati: %.2f, Stok: %d\n", p.id, p.name, p.price, p.stock);
            count++;
        }
    }

    if (count == 0){
        printf("Kayit bulunamadi.\n");
    }
        
    fclose(file);
}

void deleteproduct(){
    showproducts();
    struct product p;
    FILE *file = fopen(FILE_NAME, "rb+");
    int id2;
    int found=0;
    printf("\nSilinecek urunun ID'sini girin: ");
    scanf("%d", &id2);

    while (fread(&p, sizeof(struct product), 1, file)) {
        if (p.id == id2) {
            found=1;
            p.id=-1;
            fseek(file, p.id * sizeof(struct product), SEEK_CUR);
            fwrite(&p, sizeof(struct product), 1, file);
            printf("Urun silindi.\n");
            break;
        }
    }

    if(!found){
        printf("Bu ID'ye sahip bir urun bulunamadi.\n");
    }

    fclose(file);
   
}

void deletefile(){
    showproducts();
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("\nDosyadaki veriler silinemedi!\n");
        return;
    }

    fclose(file);
    printf("\nDosyadaki tum veriler silindi.\n");
}

int idcontrol(int id){
    struct product p;
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) 
        return 0;

    while (fread(&p, sizeof(struct product), 1, file)) {
        if (p.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
