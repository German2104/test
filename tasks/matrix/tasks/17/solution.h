#pragma once

#include <stdint.h>
#include <stdio.h>

typedef int32_t** Matrix;

Matrix CreateMatrix(int32_t n) {
    int32_t** matrix = (int32_t**)malloc(sizeof(int32_t*) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * n);
    }
    return matrix;
}




int Task() {
    // write your solution here
    return 0;
}