#include "parsing.h"
void print_matrix(matrix_t mat) {

    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.columns; j++) {
            printf("%f, ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

// принт массива полигонов
void poligon_print(Data obj) {
    for (int i = 0;i < obj.count_of_polygons ; i++) {
        for (int j = 0; j < obj.poligons[i].numbers_of_vertexes_in_facets; j++) { // убрал умножение на два!
            printf("%d, ", obj.poligons[i].vertexes[j]);
        }
//        printf("\t\t%d", obj.poligons->numbers_of_vertexes_in_facets);
        printf("\n");
    }
}
