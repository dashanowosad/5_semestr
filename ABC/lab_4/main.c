#include <stdio.h>
#include "BLAS.h"
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>
void Fill_vector(int*restrict x, int *restrict y, int N){
    for(int i = 0; i < N; i++){
        x[i] = 1 + rand() % 100000;
        y[i] = 1 + rand() % 100000;
    }
}

void Fill_matrix(double *restrict x, double *restrict y, int N){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            x[i * N + j] = 1 + rand() % 10000;
            y[i * N + j] = 1 + rand() % 10000;
        }
}

int main() {
    double *x, *y, *c;
    int *x1, *y1;
    int scalar = 2, N = 695000000;
    FILE *SAXPY, *DEGMM;
    clock_t start1, stop;
    srand(time(NULL));
    /*   printf("Input N: ");
       scanf("%d",&N);*/
    SAXPY = fopen("../SAXPY.txt", "a");
    DEGMM = fopen("../DEGMM.txt", "w");
    fprintf(DEGMM, "[N, \t\t\t T] \n");
     /*for(int i = 0; i < N; i+= 5000000) {
         x1 = calloc(sizeof(int), i);
         y1 = calloc(sizeof(int), i);
         Fill_vector(x1, y1, i);
         start1 = clock();
         SAXPY_int(i, scalar, x1, y1);
         stop = clock();
         fprintf(SAXPY, "[%d ,\t %f ],\n", i, (double) (stop - start1) / CLOCKS_PER_SEC);
         printf("%d complete \n", i);
         free(x1);
         free(y1);
         *//*free(c);*//*
     }*/
    x1 = calloc(sizeof(int), N);
    y1 = calloc(sizeof(int), N);
    Fill_vector(x1, y1, N);
    start1 = clock();
    SAXPY_int(N, scalar, x1, y1);
    stop = clock();
    fprintf(SAXPY, "[%d ,\t %f ],\n", N, (double) (stop - start1) / CLOCKS_PER_SEC);
    printf("%d complete \n", N);
    free(x1);
    free(y1);
    /*free(c);*/
     fclose(DEGMM);
     fclose(SAXPY);
    return 0;
}