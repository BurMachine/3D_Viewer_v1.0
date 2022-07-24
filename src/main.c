#include "underfile.h"
// прототип функции
int parser();
int main() {
    parser();
    return 0;
}


int parser() {
    FILE *fp;
    char *filename = "cub.obj";
    fp = fopen(filename, "r");
    char *str = NULL;
    size_t l_buf_size = 0;
    while ((getline(&str, &l_buf_size, fp)) != EOF) printf("%s", str);
    fclose(fp);
    return 0;
}

//puk