#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;
node* head = NULL;

void yazdir();
void basaekle(int veri);
void arayaekle(int veri, int sira);
void sonaekle(int veri);
void dugumsil(int sira);

int main(){
    int secim;
    int veri;
    int sira;

    while(1){
        printf("\n-----MENU-----\n");
        printf("1- Listeyi Goruntule\n");
        printf("2- Basa Eleman Ekle\n");
        printf("3- Araya Eleman Ekle\n");
        printf("4- Sona Eleman Ekle\n");
        printf("5- Dugum Sil\n");
        printf("6- Cikis\n");
        printf("--------------\n");
        printf("Secim Yapin: ");
        scanf("%d",&secim);

        switch (secim){
            case 1:
                yazdir();
            break;
            case 2:
                printf("Eleman girin: ");
                scanf("%d",&veri);
                basaekle(veri);
            break;
            case 3:
                printf("Eleman girin: ");
                scanf("%d",&veri);
                printf("Hangi indekse ekleme yapilsin: ");
                scanf("%d",&sira);
                arayaekle(veri,sira);
            break;
            case 4:
                printf("Eleman girin: ");
                scanf("%d", &veri);
                sonaekle(veri);
            break;
            case 5:
                printf("Silinecek dugumun indeksini girin: ");
                scanf("%d", &sira);
                dugumsil(sira);
            break;
            case 6:
                printf("Cikis yapiliyor");
                exit(0);
            break;
            default :
                printf("Geçersiz seçim");
            break;
        }
    }
}

void yazdir(){
    node* temp=head;
    printf("Liste: ");

    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void basaekle(int veri){
    node* yeni = (node*)malloc(sizeof(node));

    yeni->data= veri;
    yeni->next= head;
    head=yeni;
}

void arayaekle(int veri,int sira){
    node* yeni =(node*)malloc(sizeof(node));

    yeni->data =veri;
    yeni->next =NULL;

    if(sira ==0){
        basaekle(veri);
        return;
    }

    node* temp=head;
    for(int i=0;i<sira-1; i++){
        if(temp==NULL){
            printf("Girilen değer, liste boyutundan buyuktur!\nEkleme yapilamadi.\n");
            free(yeni);
        }
        temp=temp->next;
    }

    yeni->next=temp->next;
    temp->next= yeni;

    printf("%d. indekse %d degeri eklendi.\n",sira,veri);
}

void sonaekle(int veri){
    node* yeni=(node*)malloc(sizeof(node));
    if (yeni == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return;
    }
    yeni->data = veri;
    yeni->next = NULL;

    if (head == NULL) {
        head = yeni;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = yeni;
}

void dugumsil(int sira){
    if(head==NULL){
        printf("Liste Bos\n");
        return;
    }
    node*temp=head;
    node* prev= NULL;

    for (int i = 0; i < sira; i++) {
        if (temp == NULL) {
            printf("Gecersiz indeks! Silme yapilamadi.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Gecersiz indeks! Silinecek dugum yok.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Indeks %d'de bulunan %d degerli dugum silindi.\n", sira, temp->data);
    free(temp);
    yazdir();
}
