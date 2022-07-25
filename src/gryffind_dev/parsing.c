//
// Created by Gryffindor Dodie on 7/22/22.
//
// привет мир
#include "parsing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reading_counting(char *file_name, Data *obj) {
    int code = 0;
    int counter_v = 0;
    int counter_f = 0;
    FILE *stream;
    char *line = NULL;
    //    char path[200] =
    //    "/Users/gryffind/C8_3DViewer_v1.0-1/src/gryffind_dev/obj/";
    char path[200] = "/Users/corkiudy/C8_3DViewer_v1.0-0/src/gryffind_dev/obj/";
    strcat(path, file_name);
    size_t len = 0;
    ssize_t read;
    stream = fopen(path, "r");
    if (stream == NULL) code = 1;
    if (code == 0) {
        while ((read = getline(&line, &len, stream)) != -1) {
            if (line[0] == 'v' && line[1] != 't' && line[1] != 'n') counter_v++;
            if (line[0] == 'f') counter_f++;
        }
        obj->count_of_vertex = counter_v;
        obj->count_of_polygons = counter_f;
    }
    free(line);
    fclose(stream);
    return code;
}

int parsing_matrix(char *file_name, Data *obj) {
    int code = 0;
    FILE *stream;
    char *line = NULL;
    char path[200] = "/Users/corkiudy/C8_3DViewer_v1.0-0/src/gryffind_dev/obj/";
    strcat(path, file_name);
    size_t len = 0;
    int read;
    //    printf("%s\n", path);
    stream = fopen(path, "r");
    // УБРАЛ ЛИШНЮЮ ЕДИНИЦУ ТАК ОНА ПРИВОДИЛА К ЛИШНЕЙ СТРОКЕ В ВЫВОДЕ
    s21_create_matrix(obj->count_of_vertex, 3, &obj->matrix);
    obj->poligons = malloc((obj->count_of_polygons + 1) * sizeof(polygon_t));
    int row = 0;
    int column = 0;
    int polygons = 0;

    if (stream == NULL) code = 1;
    if (code == 0) {
        while ((read = getline(&line, &len, stream)) != -1) {
            column = 0;
            if (line[0] == 'v' && line[1] == ' ') {
                int sign = 0;
                for (int i = 0; line[i] != '\n'; i++) {
                    if (line[i] == '-') {
                        i++;
                        sign = 1;
                    }
                    if (line[i] >= 48 && line[i] <= 57) {
                        char *start_num = &line[i];
                        while (is_num(line[i]) == 0) {
                            i++;
                        }
                        char *finish = &line[--i];
                        double num = strtod(start_num, &finish);
                        if (sign) num *= (-1);
                        obj->matrix.matrix[row][column] = num;
                        column++;
                    }
                    if (column == 3) break;
                    sign = 0;
                }
                row++;
            }
            if (line[0] == 'f') {
                poligon_memory(line, obj, polygons);
                poligon_string_parsing(line, obj, polygons);
                polygons++;
            }

        }
    }
    free(line);
    fclose(stream);
    return code;
}

void vertex_filler(char *line, Data *obj, int *row, int *column) {
     int sign = 0;
    for (int i = 0; line[i] != '\n'; i++) {
        if (line[i] == '-') {
            i++;
            sign = 1;
        }
        if (line[i] >= 48 && line[i] <= 57) {
            char *start_num = &line[i];
            while (is_num(line[i]) == 0) {
                i++;
            }
            char *finish = &line[--i];
            double num = strtod(start_num, &finish);
            if (sign) num *= (-1);
            obj->matrix.matrix[*row][*column] = num;
            column++;
        }
        if (*column == 3) break;
        sign = 0;
    }
}
void poligon_string_parsing(char *input, Data *obj, int polygons_N) {
    int poligon;
    int count = 0;
    obj->poligons[polygons_N].vertexes =
        calloc(obj->poligons[polygons_N].numbers_of_vertexes_in_facets*2, sizeof(int));
    for (int i = 0; input[i] != '\n'; i++) {
        if ((is_num(input[i]) == 0) && input[i - 1] == ' ') {
            char *start_num = &input[i];
            while (is_num(input[i]) == 0) {
                i++;
            }
            char *finish = &input[--i];
            double num = strtod(start_num, &finish);
            poligon = (int)num - 1;
            obj->poligons[polygons_N].vertexes[count] = poligon;
            count++;
        }
//        ДОБАВИЛ ЧТО БЫ СДЕЛАТЬ ИЗ 3 6 ШТУК
        if (count == 2){
            obj->poligons[polygons_N].vertexes[count] = poligon;
            count++;
        }
        if (count == 4){
            obj->poligons[polygons_N].vertexes[count] = poligon;
            count++;
            obj->poligons[polygons_N].vertexes[count] = obj->poligons[polygons_N].vertexes[0];
        }
    }

//    int poligon;
//    int count = 0;
//    obj->poligons[polygons_N].vertexes = calloc(obj->poligons[polygons_N].numbers_of_vertexes_in_facets, (obj->poligons[polygons_N].numbers_of_vertexes_in_facets + 1)*sizeof(int));
//    for (int i = 0; input[i] != '\n'; i++) {
//        if ((is_num(input[i]) == 0) && input[i - 1] == ' ') {
//            char *start_num = &input[i];
//            while (is_num(input[i]) == 0) {
//                i++;
//            }
//            char *finish = &input[--i];
//            double num = strtod(start_num, &finish);
//            poligon = (int)num;
//            obj->poligons[polygons_N].vertexes[count] = poligon;
//            count++;
//        }
//    }

}
// смотрит сколько полигонов будет в facets

void poligon_memory(char *input, Data *obj, int polygons_N) {
    int count = 0;
    for (int i = 0; input[i] != '\n'; i++) {
        if ((is_num(input[i]) == 0) && input[i - 1] == ' ') {
            count++;
        }
    }
    obj->poligons[polygons_N].numbers_of_vertexes_in_facets = count;
}

int is_num(char ex) {
    int flag_error = 1;
    if ((ex >= '0' && ex <= '9') || ex == '.') {
        flag_error = 0;
    }
    return flag_error;
}
