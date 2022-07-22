#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "./matrix/s21_matrix.h"

void print_matrix(matrix_t mat);
void pol_print(data inf);

int main() {
    char fn[100] = "uploads_files_2787791_Mercedes+Benz+GLS+580.obj";
    data info;
    info.count_of_polygons = 0;
    info.count_of_vertex = 0;
    reading_counting(fn, &info);
    printf("%d\n%d\n", info.count_of_vertex, info.count_of_polygons);
//    matrix_t matrix;
    parsing_matrix(fn, &info);
    print_matrix(info.matrix);
    pol_print(info);
}


void print_matrix(matrix_t mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.columns; j++) {
            printf("%f ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

void pol_print(data inf) {
    for (int i = 0;i < inf.count_of_polygons ; i++) {
        for (int j = 0; j < inf.poligons[i].numbers_of_vertexes_in_facets; j++) {
            printf("%d ", inf.poligons[i].vertexes[j]);
        }
        printf("\t\t%d", inf.poligons->numbers_of_vertexes_in_facets);
        printf("\n");
    }
}