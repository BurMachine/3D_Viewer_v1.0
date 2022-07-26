#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./matrix/s21_matrix.h"
#include "afinn_translation.h"
#include "parsing.h"

START_TEST(s21) {
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
END_TEST
START_TEST(s212) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
}
END_TEST
START_TEST(s213) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
}
END_TEST
START_TEST(s214) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
}
END_TEST
START_TEST(s215) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
}
END_TEST
START_TEST(s216) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
}
END_TEST
int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, s21);
    tcase_add_test(tc1_1, s212);
    tcase_add_test(tc1_1, s213);
    tcase_add_test(tc1_1, s214);
    tcase_add_test(tc1_1, s215);
    tcase_add_test(tc1_1, s216);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
