#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

Matrix InputMatrix(int32_t size) {
    int32_t** input_matrix = (int32_t**)malloc(sizeof(int32_t*) * size);
    for (int32_t i = 0; i < size; ++i) {
        input_matrix[i] = (int32_t*)malloc(sizeof(int32_t) * size);
    }
    return input_matrix;
}

Matrix ReadMatrix(int32_t* n) {
    int32_t size = 0;
    FILE* file = fopen("test.txt", "r");
    fscanf(file, "%d", &size);
    *n = size;
    Matrix input_matrix = InputMatrix(size);
    printf("Input matrix\n");
    printf("---------------\n");
    for (int32_t i = 0; i < size && !feof(file); ++i) {
        for (int32_t j = 0; j < size && !feof(file); ++j) {
            fscanf(file, "%d", &input_matrix[i][j]);
            printf("%d ", input_matrix[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return input_matrix;
}

int32_t MaxElement(Matrix input_matrix, int32_t size) {
    int32_t max = input_matrix[0][0];
    for (int32_t line = 1; line < size; ++line) {
        for (int32_t collumn = 0; collumn <= line; ++collumn) {
            if (max < input_matrix[line][collumn]) {
                max = input_matrix[line][collumn];
            }
        }
    }
    return max;
}

Matrix SubmatrixMul(Matrix input_matrix, int32_t size, int32_t max) {
    for (int32_t line = 0; line < size; ++line) {
        for (int32_t collumn = line; collumn < size; ++collumn) {
            input_matrix[line][collumn] = input_matrix[line][collumn] * max;
        }
    }
    return input_matrix;
}

void PrintResult(Matrix result, int32_t size) {
    printf("---------------\n");
    printf("Result matrix\n");
    printf("---------------\n");
    for (int32_t i = 0; i < size; ++i) {
        for (int32_t j = 0; j < size; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int Task() {
    int32_t size = 0;
    int32_t* n = &size;
    Matrix input_matrix = ReadMatrix(n);
    int32_t max = MaxElement(input_matrix, size);
    Matrix result = SubmatrixMul(input_matrix, size, max);
    PrintResult(result, size);
    for (int32_t i = 0; i < size; ++i) {
        free(input_matrix[i]);
    }
    free(input_matrix);
    return 0;
}