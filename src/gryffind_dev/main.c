#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "./matrix/s21_matrix.h"

#include "afinn_translation.h"



 int main() {
//     char filename[50] = "cub.obj";
//     char filename[50] = "easyCube.obj";
    char filename[50] = "cat.obj";
     
     Data obj;
     obj.count_of_polygons = 0;
     obj.count_of_vertex = 0;
     reading_counting(filename, &obj);
//     printf("%d\n%d\n", obj.count_of_vertex, obj.count_of_polygons);
     parsing_matrix(filename, &obj);


     change_of_size(&obj, (double)2);
     move(&obj, (double)2);

     print_matrix(obj.matrix);
     poligon_print(obj);
//     s21_remove_matrix(&obj.matrix);
////     obj->poligons[polygons_N].vertexes = calloc(obj->poligons[polygons_N].numbers_of_vertexes_in_facets, (obj->poligons[polygons_N].numbers_of_vertexes_in_facets + 1)*sizeof(int));
//     for (int i = 0; i < obj.poligons->numbers_of_vertexes_in_facets + 1; i++) {
//         free(&obj.poligons[i]);
//     }
//    free(obj.poligons);
 }


void move_x(matrix_t *A, double a) {
    for (int i = 0; i < A->rows; i++) A->matrix[i][0] += a;
}
