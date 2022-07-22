//
// Created by User on 011 11.07.22.
//
#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int code = INCORRECT_MATRIX;
    double det = 0.0;

    if (!check(A)) code = OK;

    if ((!A || (A->rows < 1 || A->columns < 1)) && code != INCORRECT_MATRIX) {
        code = INCORRECT_MATRIX;
    } else if (A->rows != A->columns) {
        code = CALC_ERROR;
    }
    if (code == OK) {
        s21_determinant(A, &det);
        if (det == 0 || fabs(det) < EPS) code = CALC_ERROR;
    }


    matrix_t tmp;
    matrix_t tmp1;
    s21_create_matrix(A->columns, A->rows, result);
//    s21_create_matrix(A->rows, A->columns, &tmp);
//    if (tmp.matrix != NULL) s21_create_matrix(tmp.columns, tmp.rows, &tmp1); else code = CALC_ERROR;
//    int a, b;
    if (code == OK) {
        s21_calc_complements(A, &tmp);
        s21_transpose(&tmp, &tmp1);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->rows; j++) {
                result->matrix[i][j] = tmp1.matrix[i][j] / det;
            }
        }
        s21_remove_matrix(&tmp);
        s21_remove_matrix(&tmp1);
    }

    return code;
}


