cmake_minimum_required(VERSION 3.21)
project(gryffind_dev C)

set(CMAKE_C_STANDARD 11)

add_executable(gryffind_dev ./matrix/s21_calc_complements.c ./matrix/s21_create_matrix.c ./matrix/s21_eq_matrix.c ./matrix/s21_inverse_matrix.c ./matrix/s21_mult.c ./matrix/s21_remove_matrix.c ./matrix/s21_sum_sub.c ./matrix/s21_transpon.c ./matrix/determinant.c ./matrix/check.c parsing.c main.c)
