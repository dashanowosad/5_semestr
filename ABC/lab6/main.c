#include <stdio.h>
#include "BLAS.h"
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>


void Fill_matrix(double **restrict x, double **restrict y, int N){
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            x[i][j] = 1 + rand() % 10000;
            y[i][j] = 1 + rand() % 10000;
        }

}

void Fill_matrix_line(double *restrict x, double *restrict y, int N){
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            x[i * N + j] = rand() % 10;
            y[i * N + j] = rand() % 10;
        }

}

int main() {
    double **x, **y, **c;
    double *x1, *y1, *c1;
    int scalar = 1, N = 1000, BlockSize = 16;
    FILE *stat;
    stat = fopen("../3.txt", "w");
    clock_t start1, stop;
    srand(time(NULL));

    /*x = (double**)calloc(sizeof(double),N);
    y = (double**)calloc(sizeof(double),N);
    c = (double**)calloc(sizeof(double),N);
    for(int i = 0; i < N; i++){
        x[i] = (double*)calloc(sizeof(double),N);
        y[i] = (double*)calloc(sizeof(double),N);
        c[i] = (double*)calloc(sizeof(double),N);
    }
    Fill_matrix(x,y,N);
    DEGMM_double_v2(N,N,N,scalar,x,N,y,N,scalar,c,N);
    for(int i = 0; i < N; i++){
        free(x[i]);
        free(y[i]);
        free(c[i]);
    }
    free(x);
    free(y);
    free(c);*/


    //for(BlockSize = 1; BlockSize < 16; BlockSize += 2) {
        x1 = (double*)calloc(sizeof(double),N*N);
        y1 = (double*)calloc(sizeof(double),N*N);
        c1 = (double*)calloc(sizeof(double),N*N);
        Fill_matrix_line(x1,y1,N);

        start1 = clock();
        DEGMM_double_v3(N, N, N, scalar, x1, N, y1, N, scalar, c1, N, BlockSize);
        stop = clock();

        free(x1);
        free(y1);
        free(c1);
        fprintf(stat,"Block Size = %d, time = %f\n",BlockSize,(double)(stop-start1)/CLOCKS_PER_SEC);
        printf("Block Size = %d complete\n",BlockSize);

    //}
    fclose(stat);
    //printf("%f",(double)(stop-start1)/CLOCKS_PER_SEC);

    /*for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%.0f ", x1[i * N + j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%.0f ", y1[i * N + j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%.0f ", c1[i * N + j]);
        printf("\n");
    }*/


    return 0;
}