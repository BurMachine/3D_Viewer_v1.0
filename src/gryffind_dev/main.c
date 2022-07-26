#include <stdio.h>
#include <stdlib.h>

#include "./matrix/s21_matrix.h"
#include "afinn_translation.h"
#include "parsing.h"

int main() {
    //     char filename[50] = "cub.obj";
    char filename[100] = "/Users/corkiudy/C8_3DViewer_v1.0-0/1_OBJECTS/cub.obj";
    //    char filename[50] = "cat.obj";

    Data obj;
    obj.count_of_polygons = 0;
    obj.count_of_vertex = 0;
    reading_counting(filename, &obj);
    printf("%d\n%d\n", obj.count_of_vertex, obj.count_of_polygons);
    parsing_matrix(filename, &obj);

    print_matrix(obj.matrix);
    poligon_print(obj);
    s21_remove_matrix(&obj.matrix);
}
