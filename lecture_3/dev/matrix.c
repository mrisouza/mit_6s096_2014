#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void read_matrix(FILE* pfile, Matrix* m){
    fscanf(pfile, "%zu %zu", &m->c, &m->r);
    /* now I have to allocate memory for that */
    size_t chunk = m->c * m->r;
    m->index = (int *) malloc(chunk * sizeof(int));
    for(size_t i = 0; i < chunk; i++){
        fscanf(pfile, "%d", &m->index[i]);
    }
}

void free_chunk(Matrix* m){
    free(m->index);
}

void print_matrix(Matrix* m){
    size_t rows = m->r;
    size_t columns = m->c;

    for(size_t i = 0; i < columns; i++){
        for(size_t j = 0; j < rows; j++){
            printf("%d\t", m->index[i * rows + j]);
        }
        printf("\n");
    }
}

void matrix_mult(Matrix* m, Matrix* n, Matrix* p){
    /* check dimmensions */
    if(m->c != n->r){
        printf("Dimmensional mismatch...\n");
        exit(EXIT_FAILURE);
    }
    /* initialize matrix p */
    size_t rows_p = m->r, cols_p = m->c;
    p->c = n->r;
    p->r = m->c;
    p->index = (int *) malloc(rows_p * cols_p * sizeof(int));
    /* multiply */
    for(size_t i = 0; i < rows_p; i++){
        for(size_t j = 0; j < cols_p; j++){
            p->index[j + i * cols_p] = 0;
            for(size_t k = 0; k < cols_p; k++){
                p->index[j + i * cols_p] += m->index[i * rows_p + k] * n->index[j * cols_p + k];
            }
        }
    }
}
