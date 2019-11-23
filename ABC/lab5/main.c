
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

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
            printf("%3.10lg " , A[i * N + j]);
        printf("\n");
    }
}

void printVector(int N, double *A){
    for (int i = 0;i < N; i++) {
        printf("%3.10lg\n", A[i]);
    }
}


int main(int argc, char* argv[]) {
    int N, la;
    clock_t start1, stop;
    int N_max = 10000;
    int THREADS_MAX = 4;
    int THREADS;
    int rows_per_thread;
    double *A, *B, *C, alpha = 1.0, beta = 1.0;
    argMatrix_t *mrx;
    pthread_t *threads;
    FILE *file = NULL;
    int i;
    srand(time(NULL));
    file = fopen("../stat.txt", "w");
   /* printf("Input number of rows and columns and matrix A \n");
    scanf("%d%d", &N, &la);
    printf("Input scalar for A and B \n");
    scanf("%lg%lg", &alpha, &beta);*/
    for( i = 20000; i <= 20000; i += 250){
        printf("Start %d elem \n", i);
        fprintf(file, "\t\t\t N = %d\n", i);
        A = calloc(sizeof(double), i*i);
        B = calloc(sizeof(double), i);
        C = calloc(sizeof(double), i);

        ///Заполнение и вывод начальной матриц и вектора
        fillMatrix(i, i, A);
        fillMatrix(1, i, B);
      //  printMatrix(N, la, A);
     //   printf("\n");
      //  printVector(la, B);
        ///

        for (THREADS = 1; THREADS <= THREADS_MAX; THREADS++) {
            printf("\tSettlement started for %d threads \n", THREADS);
            mrx = (argMatrix_t *) malloc(sizeof(argMatrix_t) * THREADS);
            threads = (pthread_t *) malloc(sizeof(pthread_t) * THREADS);
            printf("i = %d\n", i);
            rows_per_thread = i / THREADS;
            printf("rows_per_thread = %d\n", i);
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
            printf("%d %d %d", mrx[0].from, mrx[0].to, THREADS);
            mrx[THREADS - 1].to += residue;
            start1 = clock();
            for (int i = 0; i < THREADS; i++) {
                pthread_create(&threads[i], NULL, mulrow, (void *) &mrx[i]);
            }
            for (int i = 0; i < THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            stop = clock();
            fprintf(file, "Thread = %d \t\t Time = %.30f\n", THREADS, (double) ((stop - start1) / CLOCKS_PER_SEC));
            printf("\tSuccessfully completed, time elapsed - %f   \n", (double) ((stop - start1) / CLOCKS_PER_SEC));
        }
        printf("\n");
   //     printVector(i, C);
        free(threads);
        free(mrx);
        free(A);
        free(B);
        free(C);
    }
    fclose(file);
    return 0;
}