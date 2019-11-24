//
// Created by asakujaku on 24.11.2019.
//

#include "BLAS.h"

void* mulrow(void *arg) {
    argMatrix_t *mrx = (argMatrix_t*) arg;
    int  j, row_index;
    for (row_index = mrx->from; row_index < mrx->to; row_index++)
        for(j = 0; j < mrx->cols; j++)
            mrx->c[row_index] += mrx->alpha * mrx->a[row_index * mrx->rows + j] * mrx->beta *mrx->b[j];
    return 0;
}


void fillMatrix(int N, int la, double  *A){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < la; j++)
            A[i * N + j] = (double)(rand())/RAND_MAX*(100 + 50) - 50 ;
}


void printMatrix(int N, int la, double *A){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < la; j++)
            std::cout << std::setprecision(10) << A[i * N + j];
        std::cout << "\n";
    }
}

void printVector(int N, double *A){
    for (int i = 0;i < N; i++)
        std::cout << std::setprecision(10) << A[i] << "\n";

}