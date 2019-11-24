#include "BLAS.h"
#include <pthread.h>
#include <cstdlib>
#include <chrono>



int main(int argc, char* argv[]) {
    int N_max = 20000;
    int THREADS_MAX = 10;
    int THREADS, i;
    int rows_per_thread;
    double *A, *B, *C, alpha = 1.0, beta = 1.0;
    argMatrix_t *mrx;
    pthread_t *threads;
    FILE *file = NULL;
    srand(time(NULL));
    file = fopen("../stat.txt", "w");
    for(i = 0; i <= N_max; i += 1000){
        printf("Start %d elem \n", i);
        fprintf(file, "\t\t\t N = %d\n", i);
        A = (double*)calloc(sizeof(double), i*i);
        B = (double*)calloc(sizeof(double), i);
        fillMatrix(i, i, A);
        fillMatrix(1, i, B);

        for (THREADS = 1; THREADS <= THREADS_MAX; THREADS++) {
            C = (double*)calloc(sizeof(double), i);
            printf("\tSettlement started for %d threads \n", THREADS);
            mrx = (argMatrix_t *) malloc(sizeof(argMatrix_t) * THREADS);
            threads = (pthread_t *) malloc(sizeof(pthread_t) * THREADS);
            rows_per_thread = i / THREADS;
            int residue = i % THREADS;
            for (int j = 0; j < THREADS; j++) {
                mrx[j].id = j;
                mrx[j].a = A;
                mrx[j].b = B;
                mrx[j].c = C;
                mrx[j].from = rows_per_thread * j;
                mrx[j].to = (j + 1) * rows_per_thread;
                mrx[j].cols = i;
                mrx[j].rows = i;
                mrx[j].alpha = alpha;
                mrx[j].beta = beta;
            }
            mrx[THREADS - 1].to += residue;
            double Min = 10000000;
            for(int p = 0; p < 20; p++) {
                auto start = std::chrono::system_clock::now();
                for (int k = 0; k < THREADS; k++) {
                    pthread_create(&threads[k], NULL, mulrow, (void *) &mrx[k]);
                }
                for (int z = 0; z < THREADS; z++) {
                    pthread_join(threads[z], NULL);
                }
                std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
                if (Min > dur.count())
                    Min = dur.count();
            }
            free(C);
            free(threads);
            free(mrx);
            fprintf(file, "[ %d , \t\t  %.10f],\n", THREADS, (double) Min);
            printf("\tSuccessfully completed, time elapsed - %f   \n", Min);
        }
        printf("\n");
        free(A);
        free(B);
    }
    fclose(file);
    return 0;
}