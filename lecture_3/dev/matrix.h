#pragma once

#define MAXN 300

typedef struct Matrix_s {
    size_t r, c;
    int* index;
} Matrix;

void read_matrix(FILE* pfile, Matrix* m);
void free_chunk(Matrix* m);
void print_matrix(Matrix* m);
