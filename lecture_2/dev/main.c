/*
    mit class: lecture 2 - matrix manipulation assignement
    author: mribeiro
    date:
*/
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("enter filepath...\n");
        exit(EXIT_FAILURE);
    }
    FILE* pfile = fopen(argv[1], "r");
    if(pfile == NULL){
        perror("Error: could not open file...\n");
        exit(EXIT_FAILURE);
    }
    Matrix m, n, p;
    read_matrix(pfile, &m);
    read_matrix(pfile, &n);
    matrix_mult(&m, &n, &p);
    print_matrix(&p);
    fclose(pfile);
}
