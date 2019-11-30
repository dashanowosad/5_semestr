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

int main() {
    double **x, **y, **c;
    int *x1, *y1;
    int scalar = 1, N = 500;
    clock_t start1, stop;
    srand(time(NULL));
    x = (double**)calloc(sizeof(double),N);
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
    free(c);
    /*free(c);*/

    return 0;
}