#pragma once

#define MAXN 300

typedef struct Matrix_s {
    size_t r, c;
    int index[MAXN][MAXN];
} Matrix;

void read_matrix(FILE* pfile, Matrix* matrix);
void print_matrix(Matrix* matrix);
void matrix_mult(Matrix* m, Matrix* n, Matrix *p);
