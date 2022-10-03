#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void read_matrix(FILE* pfile, Matrix* matrix){
    fscanf(pfile, "%zu %zu", &matrix->r, &matrix->c);
    for(size_t i = 0; i < matrix->r; i++){
        for(size_t j = 0; j < matrix->c; j++){
            fscanf(pfile, "%d", &matrix->index[i][j]);
        }
    }
}

void print_matrix(Matrix* matrix){
    for(size_t i = 0; i < matrix->r; i++){
        for(size_t j = 0; j < matrix->c; j++){
            printf("%d\t", matrix->index[i][j]);
        }
        printf("\n");
    }
}

void matrix_mult(Matrix* m, Matrix* n, Matrix *p){
    if(m->c != n->r){
        printf("The matrices are not dimmensionally compatible...\n");
        exit(EXIT_FAILURE);
    }
    p->r = m->r;
    p->c = n->c;
    for(size_t i = 0; i < p->r; i++){
        for(size_t j = 0; j < p->c; j++){
            p->index[i][j] = 0;
            for(size_t k = 0; k < p->r; k++){
                p->index[i][j] += m->index[i][k] * n->index[k][j];
            }
        }
    }
}
