#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"

int main() {
    char fn[10] = "cub.obj";
    data info;
    info.count_of_polygons = 0;
    info.count_of_vertex = 0;
    reading_counting(fn, &info);
    printf("%d\n%d", info.count_of_vertex, info.count_of_polygons);
}
