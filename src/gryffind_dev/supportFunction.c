#include "parsing.h"

void copy_obj(Data *obj, Data *obj_new) {
    obj_new->count_of_polygons = obj->count_of_polygons;
    obj_new->count_of_vertex = obj->count_of_vertex;

    s21_create_matrix(obj->count_of_vertex + 1, 3, &obj_new->matrix);
    copy_matrix(&obj->matrix, &obj_new->matrix);

    obj_new->poligons = malloc((obj_new->count_of_polygons + 1) * sizeof(polygon_t));

    for (int i = 0; i < obj_new->count_of_polygons; i++){
        obj_new->poligons[i].numbers_of_vertexes_in_facets = obj->poligons[i].numbers_of_vertexes_in_facets;
    }
    for (int i = 0; i < obj_new->count_of_polygons; i++){
        obj_new->poligons[i].vertexes = calloc(obj_new->poligons[i].numbers_of_vertexes_in_facets,
                                               (obj_new->poligons[i].numbers_of_vertexes_in_facets + 1) *
                                               sizeof(int));
        obj_new->poligons[i].vertexes = obj->poligons[i].vertexes;
    }
}

void copy_matrix(matrix_t *A, matrix_t *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j];
        }
    }
}
