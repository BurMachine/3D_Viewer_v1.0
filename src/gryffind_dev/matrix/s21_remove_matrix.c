//
// Created by User on 008 08.07.22.
//

#include "s21_matrix.h"
#include <stdlib.h>
void s21_remove_matrix(matrix_t *const A) {
    if (A) {
        for (int i = 0; i < A->rows; i++)
            free(A->matrix[i]);

        free(A->matrix);
    }
}
