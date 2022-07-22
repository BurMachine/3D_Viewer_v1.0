//
// Created by User on 008 08.07.22.
//
#include "s21_matrix.h"


int s21_transpose(matrix_t *A, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    if (!check(A)) code = OK;
    if ((A->rows < 1 || A->columns < 1) && code != INCORRECT_MATRIX) code = INCORRECT_MATRIX;

    s21_create_matrix(A->columns, A->rows, result);
    if (code == OK) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[j][i] = A->matrix[i][j];
            }
        }
    }
    return code;
}
