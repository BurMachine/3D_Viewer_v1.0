#include <stdio.h>
#include "s21_matrix.h"
#include <stdlib.h>


//  void printner(matrix_t matrix) {
//    int a = matrix.rows;
//    int b = matrix.columns;
//
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j < b; j++) {
//            printf("%.8lf ", matrix.matrix[i][j]);
//        }
//        printf("\n");
//    }
//}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int code = INCORRECT_MATRIX;

    // if (rows > 0 && columns > 0) {
        result->columns = columns;
        result->rows = rows;
        result->matrix = (double**)calloc(rows, sizeof (double *));
        code = MALLOC_ERROR;

        if (result->matrix) {
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = calloc(columns, sizeof (double));
                if (!result->matrix[i]) break;
            }
            code = OK;
        } else {
            free(result->matrix);
        }
    // }
    return code;
}
