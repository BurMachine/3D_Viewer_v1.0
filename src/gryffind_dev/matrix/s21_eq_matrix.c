//
// Created by User on 008 08.07.22.
//
#include "s21_matrix.h"
#include <math.h>

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int code = SUCCESS;

    if (A->rows != B->rows) code = FAIL;
    if (A->columns != B->columns) code = FAIL;
    if (code != FAIL) {
        for (int i = 0; (i < A->rows) && code != FAIL; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) code = FAIL;
            }
        }
    }
    return code;
}
