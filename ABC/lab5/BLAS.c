//
// Created by asakujaku on 22.11.2019.
//

#include "BLAS.h"


// N - число строк
// la - число столбцов




void DEGMV(int N, double* A, int la, double alpha, double beta, double *B, double* C){
    for (int i = 0; i <  N; i++){
        for (int j = 0; j < la; j++) {
           // printf(" i = %d, j = %d, A = %lg, B = %lg, mul = %lg \n", i , j, A[i * N + j], B[j], alpha * A[i * N + j] * beta * B[j]);
            C[i] += alpha * A[i * N + j] * beta * B[j];
        }
    }
}

