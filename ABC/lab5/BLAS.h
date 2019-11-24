//
// Created by asakujaku on 24.11.2019.
//

#ifndef LAB5_BLAS_H
#define LAB5_BLAS_H

#include <iostream>
#include <iomanip>
#include <ctime>

typedef struct argMatrix_tag {
    int id;
    int rows;
    int cols;
    int from;
    int to;
    double alpha;
    double beta;
    double *a;
    double *b;
    double *c;
} argMatrix_t;


void* mulrow(void *arg);
void fillMatrix(int N, int la, double  *A);
void printMatrix(int N, int la, double *A);
void printVector(int N, double *A);

#endif //LAB5_BLAS_H
