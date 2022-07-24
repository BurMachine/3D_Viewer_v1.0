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
