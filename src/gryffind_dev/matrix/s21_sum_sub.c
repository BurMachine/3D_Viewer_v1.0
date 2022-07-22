#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    if (!check(A) && !check(B)) code = OK;
    if (A->rows != B->rows || A->columns != B->columns)
        return CALC_ERROR;
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == OK) {
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    if (!check(A) && !check(B)) code = OK;
    if (A->rows != B->rows || A->columns != B->columns)
        return CALC_ERROR;
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == OK) {
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
    return OK;
}
