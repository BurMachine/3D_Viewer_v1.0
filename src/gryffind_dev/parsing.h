//
// Created by Gryffindor Dodie on 7/22/22.
//

#ifndef GRYFFIND_DEV_PARSING_H
#define GRYFFIND_DEV_PARSING_H

#include "./matrix/s21_matrix.h"

typedef struct facets {
    int *vertexes;
    int numbers_of_vertexes_in_facets;
} polygon_t;

typedef struct info {
    int count_of_vertex;
    int count_of_polygons;
    matrix_t matrix;
    polygon_t *poligons;
}data;



int reading_counting(char *file_name, data *inf);
int parsing_matrix(char *file_name, data *inf);

int is_num(char ex);
void poligon_memory(char *input, data *inf, int polygons_N);
void poligon_string_parsing(char *input, data *inf, int polygons_N);

#endif //GRYFFIND_DEV_PARSING_H
