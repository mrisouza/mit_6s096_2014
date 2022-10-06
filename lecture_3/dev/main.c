#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(){
    FILE* pfile = fopen("./input/matrix2.1.in", "r");
    if(pfile == NULL){
        perror("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    Matrix m, n, p;
    read_matrix(pfile, &m);
    //print_matrix(&m);
    read_matrix(pfile, &n);
    //print_matrix(&n);
    matrix_mult(&m, &n, &p);
    print_matrix(&p);
    free_chunk(&m);
    free_chunk(&n);
    free_chunk(&p);
    fclose(pfile);
    return EXIT_SUCCESS;
}
