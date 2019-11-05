//
// Created by asakujaku on 30.10.2019.
//

#ifndef LAB_4_BLAS_H
#define LAB_4_BLAS_H

void SAXPY_int(int N, int scalar, int* restrict x, int* restrict y);
void SAXPY_float(int N, float scalar, float* restrict x, float* restrict y);
void DEGMM_double(const int M, const int N, const int K, const double alpha, const double *A, const int lda,
        const double *B, const int ldb,const double beta, double* C, const int ldc);

#endif //LAB_4_BLAS_H
