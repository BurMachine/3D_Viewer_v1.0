#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "./matrix/s21_matrix.h"

void copy_obj(data *obj, data *obj_new);
void copy_matrix(matrix_t *A, matrix_t *result);
//void multiple_facets(data *obj)
int main() {
    char filename[100] = "cub.obj";
    data obj;
    data obj_new;
    obj.count_of_polygons = 0;
    obj.count_of_vertex = 0;
    reading_counting(filename, &obj);
    printf("%d\n%d\n", obj.count_of_vertex, obj.count_of_polygons);
    parsing_matrix(filename, &obj);
    print_matrix(obj.matrix);
    poligon_print(obj);
    copy_obj(&obj, &obj_new);
    printf("\n----------\n");
    print_matrix(obj.matrix);
    poligon_print(obj_new);
}


void multiple_facets(data *obj, data *obj_new) {
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

