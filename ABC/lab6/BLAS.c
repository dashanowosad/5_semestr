//
// Created by asakujaku on 30.10.2019.
//

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

