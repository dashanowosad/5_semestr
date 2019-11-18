#include "BLAS.h"
#include <iostream>
#include <thread>
#include <ctime>
#include <iomanip>

void fillMatrix(int N, int la, double  *A){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < la; j++)
            A[i * N + j] = -100 + rand() % 1000;
}

void printMatrix(int N, int la, double *A){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < la; j++)
            std::cout << std::setw(3) << A[i * N + j] << " ";
        std::cout << std::endl;
    }
}


int main(int argc, char* argv[]) {
    int N, la;
    double *A, *B, *C, alpha, beta;
    srand(time(NULL));
    std::cout << "Input number of rows and columns and matrix A \n";
    std::cin >> N >> la;
    std::cout << "Input scalar for A and B";
    std::cin >> alpha >> beta;
    A = new double [N*la];
    B = new double [N];
    C = new double [N];
    fillMatrix(N, la, A);
    fillMatrix(N, 1, B);
    printMatrix(N, la, A);
    printMatrix(N, 1, B);
    return 0;
}

