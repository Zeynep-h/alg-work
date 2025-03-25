#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS1 2
#define COLS1 3
#define ROWS2 3
#define COLS2 2

int matrix1[ROWS1][COLS1];
int matrix2[ROWS2][COLS2];
int result[ROWS1][COLS2];

void rnd(int rows, int cols, int matrix[rows][cols]);
void prt(int rows, int cols, int matrix[rows][cols]);
void sum(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2]);
void car(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2]);

int main(){
    srand(time(NULL));

    printf("1. martrix\n");
    rnd(ROWS1, COLS1, matrix1);
    prt(ROWS1, COLS1, matrix1);

    printf("\n2. matrix\n");
    rnd(ROWS2, COLS2, matrix2);
    prt(ROWS2, COLS2, matrix2);

    sum(matrix1, matrix2);
    car(matrix1, matrix2);

    return 0;
}

void rnd(int rows, int cols, int matrix[rows][cols]){
    for(size_t i=0;i<rows;i++){

        for(size_t j=0; j<cols;j++){
            matrix[i][j]=rand()%100+1;
        }
    }
}

void prt(int rows, int cols, int matrix[rows][cols]){
    for(size_t i=0;i<rows;i++){

        for(size_t j=0; j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void sum(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2]){
    if(ROWS1 == ROWS2 && COLS1 == COLS2){

        printf("\nToplam\n");
        for(size_t i=0;i<ROWS1;i++){

            for(size_t j=0; j<COLS1;j++){
                printf("%d ",matrix1[i][j]+matrix2[i][j]);
            }
            printf("\n");
        }
        
    }else{

        printf("\nToplama islemi yapilamaz.\n");
    }
}

void car(int matrix1[ROWS1][COLS1], int matrix2[ROWS2][COLS2]){
    
    if(ROWS2 == COLS1){
        printf("\nCarpim\n");
        for(size_t i=0;i<ROWS1;i++){
            for(size_t j=0;j<COLS2;j++){
                result[i][j] = 0;
                for(size_t k=0;k<ROWS2;k++){
                    result[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }

        for(size_t i = 0; i < ROWS1; i++){
            for(size_t j = 0; j < COLS2; j++){
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

    }else{
        printf("\nMatrisler carpilamaz.\n");
    }
}
