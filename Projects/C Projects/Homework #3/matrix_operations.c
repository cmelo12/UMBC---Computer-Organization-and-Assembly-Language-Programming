#include <stdio.h>

void matmult(int result [3][3], int first[3][3], int second[3][3]);
void matadd(int result [3][3], int first[3][3], int second[3][3]);
void printMatrix(char* name, int matrix[3][3]);

int main(){
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{1, 2, 0}, {3, 4, 5}, {0, 6, 7}};
    int AB[3][3];
    int result[3][3];

    printMatrix("A", A);
    printf("\n");

    printMatrix("B", B);
    printf("\n");

    matmult(AB, A, B);

    matadd(result, AB, A);

    printMatrix("A*B+A", result);

    return 0;
}//end main

void matmult(int result[3][3], int first[3][3], int second[3][3]){
    int i, j, k;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            for(k = 0; k < 3; k++){
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

}//end matmult

void matadd(int result[3][3], int first[3][3], int second[3][3]){
    int i, j;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            result[i][j] = first[i][j] + second[i][j];
        }
    }

}//end matadd

void printMatrix(char* name, int matrix[3][3]){
    printf("    [%d %d %d]\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("%s = |%d %d %d|\n", name, matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("    [%d %d %d]\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    
}//end printMatrix