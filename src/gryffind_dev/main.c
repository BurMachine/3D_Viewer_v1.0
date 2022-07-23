#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "./matrix/s21_matrix.h"



//void multiple_facets(Data *obj, Data *obj_new);
 int main() {
     char filename[50] = "cub.obj";
     Data obj;
     Data obj_new;
     obj.count_of_polygons = 0;
     obj.count_of_vertex = 0;
     reading_counting(filename, &obj);
     printf("%d\n%d\n", obj.count_of_vertex, obj.count_of_polygons);
     parsing_matrix(filename, &obj);


     print_matrix(obj.matrix);
     poligon_print(obj);

 //    multiple_facets(&obj, &obj_new);
 //    printf("\n----------\n");
 //    print_matrix(obj.matrix);
 //    poligon_print(obj_new);
 }


//void multiple_facets(Data *obj, Data *obj_new) {
//    obj_new->count_of_polygons = obj->count_of_polygons;
//    obj_new->count_of_vertex = obj->count_of_vertex;
//
//    s21_create_matrix(obj->count_of_vertex + 1, 3, &obj_new->matrix);
//    copy_matrix(&obj->matrix, &obj_new->matrix);
//
//    obj_new->poligons = malloc((obj_new->count_of_polygons + 1) * sizeof(polygon_t));
//
//    for (int i = 0; i < obj_new->count_of_polygons; i++){
//        obj_new->poligons[i].numbers_of_vertexes_in_facets = obj->poligons[i].numbers_of_vertexes_in_facets;
//    }
//    for (int i = 0; i < obj_new->count_of_polygons; i++){
//        obj_new->poligons[i].vertexes = realloc(obj->poligons[i].vertexes,
//                                               (obj->poligons[i].numbers_of_vertexes_in_facets + 1) * 2 *
//                                               sizeof(int));
//        obj_new->poligons[i].vertexes = obj->poligons[i].vertexes;
//    }
//}

