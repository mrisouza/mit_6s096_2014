#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("no input given...\n");
        exit(EXIT_FAILURE);
    }
    char* name = argv[1];
    printf("Hello, %s!\n", name);
    return EXIT_SUCCESS;
}
