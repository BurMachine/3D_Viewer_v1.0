#include "parsing.h"

void copy_obj(Data *obj, Data *obj_new) {
    obj_new->count_of_polygons = obj->count_of_polygons;
    obj_new->count_of_vertex = obj->count_of_vertex;

    s21_create_matrix(obj->count_of_vertex + 1, 3, &obj_new->matrix);
    copy_matrix(&obj->matrix, &obj_new->matrix);

    obj_new->poligons =
        malloc((obj_new->count_of_polygons + 1) * sizeof(polygon_t));

    for (int i = 0; i < obj_new->count_of_polygons; i++) {
        obj_new->poligons[i].numbers_of_vertexes_in_facets =
            obj->poligons[i].numbers_of_vertexes_in_facets;
    }
    for (int i = 0; i < obj_new->count_of_polygons; i++) {
        obj_new->poligons[i].vertexes =
            calloc(obj_new->poligons[i].numbers_of_vertexes_in_facets,
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

void get_max_min_frustum(int *max, int *min, Data obj) {
    double min_vertex = obj.matrix.matrix[0][0];
    double max_vertex = obj.matrix.matrix[0][1];
    for (int i = 0; i < obj.count_of_vertex; i++) {
        for (int j = 0; j < 3; j++) {
            if (min_vertex > obj.matrix.matrix[i][j]) {
                min_vertex = obj.matrix.matrix[i][j];
            }
            if (max_vertex < obj.matrix.matrix[i][j]) {
                max_vertex = obj.matrix.matrix[i][j];
            }
        }
    }
    *max = max_vertex;
    *min = min_vertex;
}

// функция записывает в файл объект obj
int deparse(Data obj, char *filename) {
    int code = 0;
    char path[100] = "";
    path_parse(filename, path);
    FILE *file;
    // получать эту строку из фронта
    // char path_2[200] = strcat(path, "/DEPARSE.obj");
    // file = fopen(path "w");
    // fprintf(file, "Это файл который сохраняет состояние модели\n");
    if (file) {
        for (int i = 0; i < obj.matrix.rows; i++) {
            fprintf(file, "v ");
            for (int j = 0; j < obj.matrix.columns; j++) {
                fprintf(file, "%f ", obj.matrix.matrix[i][j]);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
        int arr_f[3] = {0, 1, 3};
        for (int i = 0; i < obj.count_of_polygons; i++) {
            fprintf(file, "f ");
            for (int j = 0; j < 3; j++) {
                fprintf(file, "%d ", obj.poligons[i].vertexes[arr_f[j]] + 1);
            }
            fprintf(file, "\n");
        }

        fclose(file);
    } else {
        code = 1;
    }

    return code;
}
void path_parse(char *filename, char *result_str) {
    //    char filename[100] =
    //    "/Users/corkiudy/C8_3DViewer_v1.0-0/1_OBJECTS/hand.obj";
    int len = strlen(filename);
    int j = 0;
    for (int i = 0; i < len && j < 5; i++) {
        if (filename[i] == '/') {
            j++;
        }
        if (j < 5) {
            result_str[i] = filename[i];
        } else {
            break;
        }
    }
}
