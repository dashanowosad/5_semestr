//
// Created by asakujaku on 30.10.2019.
//

#ifndef LAB_4_BLAS_H
#define LAB_4_BLAS_H


void DEGMM_double_v1(const int M, const int N, const int K, const double alpha,  double **A, const int lda,
                   double **B, const int ldb,const double beta, double** C, const int ldc);
void DEGMM_double_v2(const int M, const int N, const int K, const double alpha,  double **A, const int lda,
                     double **B, const int ldb,const double beta, double** C, const int ldc);
void DEGMM_double_v3(const int M, const int N, const int K, const double alpha,  double *A, const int lda,
                     double *B, const int ldb,const double beta, double* C, const int ldc, int BS);

#endif //LAB_4_BLAS_H
