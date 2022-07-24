//
// Created by Gryffindor Dodie on 7/24/22.
//

#include "afinn_translation.h"
#include "parsing.h"


void change_of_size(Data *obj, double coefficient) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_mult_number(&tmp, coefficient, &result);
    (*obj).matrix = result;
//    s21_remove_matrix(&result);  // не чистится память???
}

void move(Data *obj, double constant) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->matrix.rows, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = obj->matrix.matrix[i][j] + constant;
        }
    }
    (*obj).matrix = result;
}