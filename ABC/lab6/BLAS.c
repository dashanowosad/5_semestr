//
// Created by asakujaku on 30.10.2019.
//
//я люблю Тимура

#include "BLAS.h"
#include <stdio.h>
#include <malloc.h>



void DEGMM_double_v1(const int M, const int N, const int K, const double alpha,  double **A, const int lda,  double **B, const int ldb,const double beta, double **c, const int ldc) {
    for (int i = 0; i < lda; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                c[i][j] += A[i][k] * B[k][j];

}

void DEGMM_double_v2(const int M, const int N, const int K, const double alpha,  double **A, const int lda,  double **B, const int ldb,const double beta, double **c, const int ldc){
    for (int i = 0; i < lda; i++)
        for (int k = 0; k < M; k++)
            for (int j = 0; j < N; j++)
                c[i][j] += A[i][k] * B[k][j];
}

void DEGMM_double_v3(const int M, const int N, const int K, const double alpha,  double *A, const int lda,  double *B, const int ldb,const double beta, double *c, const int ldc, int BS){
    int i0, k0, j0;
    double *a0, *c0, *b0;
    for (int i = 0; i < lda; i+=BS)
        for (int j = 0; j < M; j+=BS)
            for (int k = 0; k < N; k+=BS)
                for(i0 = 0, c0 = (c + i * N + j), a0 = (A + i * N + k); i0 < BS; ++i0, c0+=N, a0+=N)
                    for (k0 = 0, b0 = (B + k * N + j); k0 < BS; ++k0, b0+=N)
                        for (j0 = 0; j0 < BS; ++j0)
                            c0[j0] += a0[k0] * b0[j0];

}