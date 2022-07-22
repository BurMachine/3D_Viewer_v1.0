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
    printf("%s\n", path);
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