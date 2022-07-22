#include "underfile.h"

double *translator(double array_coordinat[], int len) {
    // double array_coordinat[] = {
    //     1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000, 1.000000,
    //     -1.000000, -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000,
    //     1.000000,  1.000000,  -0.999999, 0.999999,  1.000000,  1.000001,
    //     -1.000000, 1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000};
    // int len = sizeof(array_coordinat) / sizeof(array_coordinat[0]);
    double *new_array = malloc(len * sizeof(double));
    for (int i = 0; i < len; i++) {
        new_array[i] = array_coordinat[i] / 2;
    }
    // for (int i = 0; i < len; i++) {
    //     printf("\n%lf", new_array[i]);
    // }
    return new_array;
}
// void test_translator() {
//     double array_coordinat[] = {
//         1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000, 1.000000,
//         -1.000000, -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000,
//         1.000000,  1.000000,  -0.999999, 0.999999,  1.000000,  1.000001,
//         -1.000000, 1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000};
//     int len = sizeof(array_coordinat) / sizeof(array_coordinat[0]);
//     double *new_array = translator(array_coordinat, len);
//     for (int i = 0; i < len; i++) {
//         printf("\n%lf,", new_array[i]);
//     }
// }

// GLfloat triangle[] = {
//     0.0,0.8,
//     -0.8, -0.8,
//     0.8, -0.8
// };
// GLfloat triangle_colors[] = {
//     0.0,0.0,1.0,
//     0.0, 1.0, 0.0,
//     1.0, 0.0, 0.0
// };

