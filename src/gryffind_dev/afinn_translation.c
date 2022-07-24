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

void change_of_size_x(Data *obj, double coefficient) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][0] = obj->matrix.matrix[i][0]*coefficient;
            result.matrix[i][1] = obj->matrix.matrix[i][1];
            result.matrix[i][2] = obj->matrix.matrix[i][2];
        }
    }
    (*obj).matrix = result;
}
void change_of_size_y(Data *obj, double coefficient) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][1] = obj->matrix.matrix[i][1]*coefficient;
            result.matrix[i][0] = obj->matrix.matrix[i][0];
            result.matrix[i][2] = obj->matrix.matrix[i][2];
        }
    }
    (*obj).matrix = result;
}

void change_of_size_z(Data *obj, double coefficient) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][2] = obj->matrix.matrix[i][2]*coefficient;
            result.matrix[i][1] = obj->matrix.matrix[i][1];
            result.matrix[i][0] = obj->matrix.matrix[i][0];
        }
    }
    (*obj).matrix = result;
}

void move_x(Data *obj, double constant) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][0] = obj->matrix.matrix[i][0] + constant;
            result.matrix[i][1] = obj->matrix.matrix[i][1];
            result.matrix[i][2] = obj->matrix.matrix[i][2];
        }
    }
    (*obj).matrix = result;
}
void move_y(Data *obj, double constant) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][1] = obj->matrix.matrix[i][1] + constant;
            result.matrix[i][0] = obj->matrix.matrix[i][0];
            result.matrix[i][2] = obj->matrix.matrix[i][2];
        }
    }
    (*obj).matrix = result;
}

void move_z(Data *obj, double constant) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t result;
    s21_create_matrix(obj->count_of_vertex, 3, &result);
    for (int i = 0; i < obj->count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][2] = obj->matrix.matrix[i][2] + constant;
            result.matrix[i][1] = obj->matrix.matrix[i][1];
            result.matrix[i][0] = obj->matrix.matrix[i][0];
        }
    }
    (*obj).matrix = result;
}

void tern_x(Data *obj, double corner) {
    matrix_t tmp;
    tmp  = (*obj).matrix;
    matrix_t turn_matrix;
    s21_create_matrix(3, 3, &turn_matrix);
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =
    turn_matrix.matrix[][] =

            matrix_t result;
}
