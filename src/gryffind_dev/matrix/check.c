//
// Created by Gryffindor Dodie on 7/13/22.
//
#include "s21_matrix.h"

int check(matrix_t *A) {
    int code = INCORRECT_MATRIX;
    if (A != NULL) if (A->matrix != NULL) if (A->rows > 0 && A->columns > 0) code = OK;
    return code;
}
