// Нужно дополнительно тестировать
//#include "cuda_runtime.h"
//#include "device_launch_parameters.h"
//#include <stdio.h>
//#include <stdlib.h>
//#define BLOCK_SIZE 16
//// тип, который будут иметь элементы матриц
//#define BASE_TYPE double
//// функция перемножения матриц
//__global__ void matrixMult(const BASE_TYPE *A, const
//BASE_TYPE *B, BASE_TYPE *C, int Acols, int Bcols)
//{
//    int i0 = Acols * (blockDim.y * blockIdx.y +
//                      threadIdx.y);
//    int j0 = blockDim.x * blockIdx.x + threadIdx.x;
//    BASE_TYPE sum = 0;
//    60
//    for (int k = 0; k < Acols; k++)
//        sum += A[i0 + k] * B[k * Bcols + j0];
//    int ind = Bcols * (blockDim.y * blockIdx.y +
//                       threadIdx.y) + blockDim.x * blockIdx.x + threadIdx.x;
//    C[ind] = sum;
//}
//int toMultiple(int a, int b) {
//    int mod = a % b;
//    if (mod != 0) {
//        mod = b - mod;
//        return a + mod;
//    }
//    return a;
//}
//int main()
//{
////start, stop - for Kernel time
//    cudaEvent_t start, stop;
//    cudaEventCreate(&start);
//    cudaEventCreate(&stop);
//    // количество строк и столбцов матрицы
//    int Arows = 100;
//    int Acols = 200;
//    int Brows = Acols;
//    int Bcols = 150;
//
//    Arows = toMultiple(Arows, BLOCK_SIZE);
//    printf("Arows = %d\n", Arows);
//
//    Acols = toMultiple(Acols, BLOCK_SIZE);
//    printf("Acols = %d\n", Acols);
//    61
//
//    Brows = toMultiple(Brows, BLOCK_SIZE);
//    printf("Brows = %d\n", Brows);
//
//    Bcols = toMultiple(Bcols, BLOCK_SIZE);
//    printf("Bcols = %d\n", Bcols);
//
//    size_t Asize = Arows * Acols * sizeof(BASE_TYPE);
//    size_t Bsize = Brows * Bcols * sizeof(BASE_TYPE);
//    size_t Csize = Arows * Bcols * sizeof(BASE_TYPE);
//
//    BASE_TYPE *h_A = (BASE_TYPE *)malloc(Asize);
//    BASE_TYPE *h_B = (BASE_TYPE *)malloc(Bsize);
//    BASE_TYPE *h_C = (BASE_TYPE *)malloc(Csize);
//
//    for (int i = 0; i < Arows * Acols; ++i) {
//        h_A[i] = rand()/(BASE_TYPE)RAND_MAX;
//    }
//    for (int i = 0; i < Brows * Bcols; ++i) {
//        h_B[i] = rand()/(BASE_TYPE)RAND_MAX;
//    }
//
//    BASE_TYPE *d_A = NULL;
//    cudaMalloc((void **)&d_A, Asize);
//
//    BASE_TYPE *d_B = NULL;
//    cudaMalloc((void **)&d_B, Bsize);
//
//    BASE_TYPE * d_C = NULL;
//    cudaMalloc((void **)&d_C, Csize);
//    cudaMemcpy(d_A, h_A, Asize, cudaMemcpyHostToDevice);
//    cudaMemcpy(d_B, h_B, Bsize, cudaMemcpyHostToDevice);
//
//    dim3 threadsPerBlock = dim3(BLOCK_SIZE, BLOCK_SIZE);
//    dim3 blocksPerGrid = dim3(Bcols / BLOCK_SIZE, Arows /
//                                                  BLOCK_SIZE);
//
//    cudaEventRecord( start, 0);
//
//    matrixMult<<<blocksPerGrid, threadsPerBlock>>>(d_A,
//            d_B, d_C, Acols, Bcols);
//
//    cudaEventRecord( stop, 0);
//    cudaEventSynchronize( stop );
//    float KernelTime;
//    cudaEventElapsedTime( &KernelTime, start, stop);
//    printf("KernelTime: %.2f milliseconds\n",
//           KernelTime);
//
//    cudaMemcpy(h_C, d_C, Csize, cudaMemcpyDeviceToHost);
//
//    printf("Test STARTED\n");
//    for (int i = 0; i < Arows; i++) {
//        for (int j = 0; j < Bcols; j++) {
//            BASE_TYPE sum = 0;
//            for (int k = 0; k < Acols; k++)
//                sum += h_A[i * Acols + k] * h_B[k *
//                                                Bcols + j];
//
//            if (fabs(h_C[i * Bcols + j] - sum) > 1e-3)
//            {
//                fprintf(stderr, "Result verification
//                failed at element [%d, %d]!\n", i, j);
//                printf("sum = %f, h_C[i * Bcols + j] =
//                       %f\n", sum, h_C[i * Bcols + j]);
//                exit(EXIT_FAILURE);
//            }
//        }
//    }
//    printf("Test PASSED\n");
//
//    cudaFree(d_A);
//    cudaFree(d_B);
//    cudaFree(d_C);
//    free(h_A);
//    free(h_B);
//    free(h_C);
//    cudaEventDestroy( start );
//    cudaEventDestroy( stop );
//    return 0;
//}
//
//
//
//
//
//////
////__global__ void matrixMult(const BASE_TYPE *A, const
////BASE_TYPE *B, BASE_TYPE *C, int Acols, int Bcols)
////{
////    int i0 = Acols * (blockDim.y * blockIdx.y +
////                      threadIdx.y);
////    int j0 = blockDim.x * blockIdx.x + threadIdx.x;
////    BASE_TYPE sum = 0;
////    for (int k = 0; k < Acols; k++)
////        sum += A[i0 + k] * B[k * Bcols + j0];
////    int ind = Bcols * (blockDim.y * blockIdx.y +
////                       threadIdx.y) + blockDim.x * blockIdx.x + threadIdx.x;
////    C[ind] = sum;
////}