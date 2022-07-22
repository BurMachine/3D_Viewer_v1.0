#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2
#define MALLOC_ERROR 3

#define FAIL 0
// #define SUCCESS 1
#define ERROR 2

#define EPS 1e-7
enum {
    FAILURE = 0,
    SUCCESS = 1
};

#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

//  void printner(matrix_t matrix);
int check_for_add_sub(matrix_t a, matrix_t b);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
double determinant_rec(double **mat, int dim);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int check(matrix_t *A);

int s21_check_matrix(matrix_t *A);
void s21_fill_minor(matrix_t *A, matrix_t *minor, int i, int j);
int s21_calc_complements(matrix_t *A, matrix_t *result);

noreturn void error(void);

#endif  //  SRC_S21_MATRIX_H_
