//
// Created by asakujaku on 30.10.2019.
//

#include "BLAS.h"
#include <stdio.h>
#include <malloc.h>

void SAXPY_int(int N, int scalar, int* restrict x, int* restrict y){
    for(int i = 0; i < N; i++){
        y[i] = scalar * x[i] + y[i];
    }
}

void DEGMM_double(const int M, const int N, const int K, const double alpha, const double *A, const int lda, const double *B, const int ldb,const double beta, double* c, const int ldc) {
    for (int i = 0; i < lda; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                c[j * N + i] += A[k * K + i] * B[j * N + k];

}
