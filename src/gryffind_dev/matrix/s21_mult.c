//
// Created by User on 008 08.07.22.
//
#include "s21_matrix.h"


int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    if (!check(A)) code = OK;
    if (A->rows < 1 || A->columns < 1) code = INCORRECT_MATRIX;
    s21_create_matrix(A->rows, A->columns, result);
    if (code == OK) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = number * A->matrix[i][j];
            }
        }
    }
    return code;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    if (!check(A) && !check(B)) code = OK;

    if (A->columns != B->rows && code != INCORRECT_MATRIX) code = CALC_ERROR;
    s21_create_matrix(A->rows, B->columns, result);
    if (code == OK) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                result->matrix[i][j] = 0;
                for (int k = 0; k < B->rows; k++) {
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    }
    return code;
}
