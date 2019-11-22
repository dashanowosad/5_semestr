#include "BLAS.h"
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

void fillMatrix(int N, int la, double  *A){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < la; j++)
            A[i * N + j] = -50 + rand() % 100;
}


void printMatrix(int N, int la, double *A){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < la; j++)
            printf("%3g " , A[i * N + j]);
        printf("\n");
    }
}

void printVector(int N, double *A){
    for (int i = 0;i < N; i++) {
        printf("%3lg\n", A[i]);
    }
}


int main(int argc, char* argv[]) {
    int N, la;
    double *A, *B, *C, alpha, beta;
    srand(time(NULL));
    printf("Input number of rows and columns and matrix A \n");
    scanf("%d%d", &N, &la);
    printf("Input scalar for A and B \n");
    scanf("%lg%lg", &alpha, &beta);
    A = calloc(sizeof(double), N*la);
    B = calloc(sizeof(double), la);
    C = calloc(sizeof(double), N);
    fillMatrix(N, la, A);
    fillMatrix(1, la, B);
   // printMatrix(N, la, A);
  //  printVector(la, B);
    DEGMV(N, A, la, alpha, beta, B, C);
    printf("\n");
    printVector(N, C);
    return 0;
}