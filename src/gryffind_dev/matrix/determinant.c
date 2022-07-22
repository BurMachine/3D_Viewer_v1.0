//
// Created by User on 011 11.07.22.
//

#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int code = OK;
    if (A == NULL || A->columns < 1 || A->rows < 1) {
        code = INCORRECT_MATRIX;
    } else if (A->rows != A->columns) {
        code = CALC_ERROR;
    }

    if (code == OK && A->columns == 1) {
        *result = A->matrix[0][0];
    } else if (code == OK && A->columns > 1) {
        *result = determinant_rec(A->matrix, A->rows);
    }
    return code;
}

double determinant_rec(double **mat, int dim) {
    if (dim == 1)
        return mat[0][0];
    double det = 0.0;
    double sign = 1.0;
    for (int i = 0; i < dim; i++) {
        matrix_t tmp = {0};
        int code = s21_create_matrix(dim - 1, dim - 1, &tmp);
        if (code == MALLOC_ERROR)
            error();
        for (int m = 1; m < dim; m++) {
            int p = 0;
            for (int n = 0; n < dim; n++) {
                if (n == i)
                    continue;
                tmp.matrix[m - 1][p] = mat[m][n];
                p++;
            }
        }

        det += sign * mat[0][i] * determinant_rec(tmp.matrix, dim - 1);
        sign = -sign;
        s21_remove_matrix(&tmp);
    }

    return det;
}
