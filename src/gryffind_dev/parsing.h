//
// Created by Gryffindor Dodie on 7/22/22.
//

#ifndef GRYFFIND_DEV_PARSING_H
#define GRYFFIND_DEV_PARSING_H

typedef struct info {
    int count_of_vertex;
    int count_of_polygons;

}data;

typedef struct Matrix {
    double **matrix;
    int rows;
    int cols;
} matrix_t;

int reading_counting(char *file_name, data *inf);
#endif //GRYFFIND_DEV_PARSING_H
