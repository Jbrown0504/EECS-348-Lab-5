/*
Name: Jaydee Brown
KUID: 3140576
Lab: Wed, 1PM
Proj Desc: Basic Matrix operations and printing using code-defined inputs*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
void print_matrix(int** matrix){
    for(int i = 0;i<SIZE;i++){
        for(int n = 0;n<SIZE;n++){
            printf("%d\t",matrix[i][n]);
        }
        printf("\n");
    }
}
int** add_matrix(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    // Allocate memory for the matrix
    int** added_matrix = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        added_matrix[i] = (int*)malloc(SIZE * sizeof(int));
    }
    if(SIZE!=SIZE){ //throws error matrix of all 0s if matrix sizes are different; shouldn't be called unless more matrix parameters are added
        for (int i = 0; i < SIZE; i++) {
            for (int n = 0; n < SIZE; n++) {
                added_matrix[i][n] = 0;
            }
        }
    }
    // Add matrices
    for (int i = 0; i < SIZE; i++) {
        for (int n = 0; n < SIZE; n++) {
            added_matrix[i][n] = matrix1[i][n] + matrix2[i][n];
        }
    }
    return added_matrix;
};
int** multiply_matrix(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    // Allocate memory for the added matrix
    int** mult_matrix = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        mult_matrix[i] = (int*)malloc(SIZE * sizeof(int));
    }
    //populates matrix with 0
    for (int i = 0; i < SIZE; i++) {
        for (int n = 0; n < SIZE; n++) {
            mult_matrix[i][n] = 0;
        }
    }
    //error handling if inner size is different
    if(SIZE!=SIZE){ 
        return mult_matrix; //returns matrix with 0
    }
    // multiply matrices
    for (int i = 0; i < SIZE; i++) {
        for (int n = 0; n < SIZE; n++) {
            for(int j = 0;j<SIZE;j++){ //multiplies row of m1 with column of m2
                mult_matrix[i][n] += matrix1[i][j]*matrix2[j][n];
            }
        }
    }
    return mult_matrix;
};

int** transpose_matrix(int matrix[SIZE][SIZE]) {
    // Allocate memory for the matrix
    int** transposed_matrix = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        transposed_matrix[i] = (int*)malloc(SIZE * sizeof(int));
    }
    // transpose matrices
    for (int i = 0; i < SIZE; i++) {
        for (int n = 0; n < SIZE; n++) {
            transposed_matrix[i][n] = matrix[n][i];
        }
    }
    return transposed_matrix;
};
int main() {
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };
    printf("Adding m1 and m2:\n");
    print_matrix(add_matrix(m1,m2));
    printf("Multiplying m1 and m2:\n");
    print_matrix(multiply_matrix(m1,m2));
    printf("Transposing m1:\n");
    print_matrix(transpose_matrix(m1));
    return 0;
}