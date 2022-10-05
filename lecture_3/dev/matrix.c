#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void read_matrix(FILE* pfile, Matrix* m){
    fscanf(pfile, "%zu %zu", &m->c, &m->r);
    /* now I have to allocate memory for that */
    size_t chunk = m->c * m->r;
    m->index = malloc(chunk * sizeof(size_t));
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
