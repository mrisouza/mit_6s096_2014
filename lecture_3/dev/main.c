#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(){
    FILE* pfile = fopen("./input/matrix2.3.in", "r");
    if(pfile == NULL){
        perror("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    Matrix m, n;
    read_matrix(pfile, &m);
    print_matrix(&m);
    read_matrix(pfile, &n);
    print_matrix(&n);
    free_chunk(&m);
    free_chunk(&n);
    fclose(pfile);
    return EXIT_SUCCESS;
}
