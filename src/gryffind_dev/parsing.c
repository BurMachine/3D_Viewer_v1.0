//
// Created by Gryffindor Dodie on 7/22/22.
//

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reading_counting(char *file_name, data *inf) {
    int code = 0;
    int counter_v = 0;
    int counter_f = 0;
    FILE *stream;
    char *line = NULL;
    char path[200] = "/Users/gryffind/C8_3DViewer_v1.0-1/src/gryffind_dev/obj/";
    strcat(path, file_name);
    size_t len = 0;
    ssize_t read;
//    printf("%s\n", path);
    stream = fopen(path, "r");
    if (stream == NULL)
        code = 1;
    if (code == 0) {
        while ((read = getline(&line, &len, stream)) != -1) {
            if (line[0] == 'v') counter_v++;
            if (line[0] == 'f') counter_f++;
        }
        inf->count_of_vertex = counter_v;
        inf->count_of_polygons = counter_f;
    }
    free(line);
    fclose(stream);
    return code;
}

int parsing_matrix(char *file_name, data *inf) {
    int code = 0;
    int counter_v = 0;
    int counter_f = 0;
    FILE *stream;
    char *line = NULL;
    char path[200] = "/Users/gryffind/C8_3DViewer_v1.0-1/src/gryffind_dev/obj/";
    strcat(path, file_name);
    size_t len = 0;
    size_t read;
//    printf("%s\n", path);
    stream = fopen(path, "r");
    s21_create_matrix(inf->count_of_vertex + 1, 3, &inf->matrix);
    inf->poligons = malloc((inf->count_of_polygons + 1)*sizeof(polygon_t));
    int row = 0;
    int column = 0;
    int sign = 0;
    int polygons = 0;

    if (stream == NULL)
        code = 1;
    if (code == 0) {
        while ((read = getline(&line, &len, stream)) != -1) {
            column = 0;
            if (line[0] == 'v' && line[1] == ' ') {
                for (int i = 0;line[i] != '\n'; i++) {
                    if (line[i] == '-') {i++; sign = 1;}
                    if (line[i] >= 48 && line[i] <= 57) {
                        char *start_num = &line[i];
                        while (is_num(line[i]) == 0) {
                            i++;
                        }
                        char *finish = &line[--i];
                        double num = strtod(start_num, &finish);
                        if (sign) num *= (-1);
                        inf->matrix.matrix[row][column] = num;
                        column++;
                    }
                    if (column == 3) break;
                    sign = 0;
                }
            }
            if (line[0] == 'f') {
                poligon_memory(line, inf, polygons);
                poligon_string_parsing(line, inf, polygons);
                polygons++;
            }
            row++;
        }

    }
    free(line);
    fclose(stream);
    return code;
}
int is_num(char ex) {
    int errror = 1;
    if ((ex >= '0' && ex <= '9') || ex == '.') {
        errror = 0;
    }
    return errror;
}

void poligon_string_parsing(char *input, data *inf, int polygons_N) {
    int poligon;
    int count = 0;
    inf->poligons[polygons_N].vertexes = calloc(inf->poligons[polygons_N].numbers_of_vertexes_in_facets, (inf->poligons[polygons_N].numbers_of_vertexes_in_facets + 1)*sizeof(int));
    for (int i = 0; input[i] != '\n'; i++) {
        if ((is_num(input[i]) == 0) && input[i - 1] == ' ') {
            char *start_num = &input[i];
            while (is_num(input[i]) == 0) {
                i++;
            }
            char *finish = &input[--i];
            double num = strtod(start_num, &finish);
            poligon = (int)num;
            inf->poligons[polygons_N].vertexes[count] = poligon;
            count++;
        }
    }
}

void poligon_memory(char *input, data *inf, int polygons_N) {
    int count = 0;
    for (int i = 0; input[i] != '\n'; i++) {
        if ((is_num(input[i]) == 0) && input[i - 1] == ' ') {
            count++;
        }
    }
    inf->poligons[polygons_N].numbers_of_vertexes_in_facets = count;
}
