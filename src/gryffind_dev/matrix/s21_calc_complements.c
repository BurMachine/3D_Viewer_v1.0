//
// Created by User on 011 11.07.22.
//
#include "s21_matrix.h"
#include "stdio.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int error_code = OK;
    if (!s21_check_matrix(A)) {
        if (A->rows == A->columns) {
            error_code = s21_create_matrix(A->rows, A->columns, result);

            if (error_code == OK) {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        double determinant = 0.0;
                        matrix_t minor;
                        error_code = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
                        // Нахождение алгебраического дополнения
                        if (error_code == OK) {
                            s21_fill_minor(A, &minor, i, j);
                            s21_determinant(&minor, &determinant);

                            result->matrix[i][j] = pow(-1, i + j) * determinant;

                            s21_remove_matrix(&minor);
                        } else {
                            error_code = INCORRECT_MATRIX;
                        }
                    }
                }
            } else {
                error_code = INCORRECT_MATRIX;
            }
        } else {
            s21_create_matrix(A->rows, A->columns, result);
            error_code = CALC_ERROR;
        }
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        error_code = INCORRECT_MATRIX;
    }
    return error_code;
}
int s21_check_matrix(matrix_t *A) {
    int error_code = OK;

    if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
        error_code = INCORRECT_MATRIX;
    }

    return error_code;
}

void s21_fill_minor(matrix_t *A, matrix_t *minor, int i, int j) {
    int minor_row_index = 0;
    int minor_column_index = 0;
    for (int m = 0; m < A->rows; m++) {
        for (int n = 0; n < A->columns; n++) {
            if (m != i && n != j) {
                minor->matrix[minor_row_index][minor_column_index] = A->matrix[m][n];

                if (minor_column_index + 1 != minor->columns) {
                    minor_column_index++;
                } else {
                    minor_row_index++;
                    minor_column_index = 0;
                }
            }
        }
    }
}

noreturn void error(void) {
    fprintf(stderr, "Malloc error\n");
    errno = ENOMEM;
    perror("Memory error");
    exit(0);
}
