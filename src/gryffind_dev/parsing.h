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
}Data;



int reading_counting(char *file_name, Data *obj);
int parsing_matrix(char *file_name, Data *obj);

int is_num(char ex);
void poligon_memory(char *input, Data *obj, int polygons_N);
void poligon_string_parsing(char *input, Data *obj, int polygons_N);
void vertex_filler(char *line, Data *struct_obj, int *row, int *column);

// ---- printers
void print_matrix(matrix_t mat);
void poligon_print(Data obj);

// ---- support
void copy_obj(Data *obj, Data *obj_new);
void copy_matrix(matrix_t *A, matrix_t *result);

#endif //GRYFFIND_DEV_PARSING_H
