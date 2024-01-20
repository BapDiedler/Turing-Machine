#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

int main(int argc, char** argv){

    avl tree = init_avl();
    print_inf_avl(tree);
    printf("\n");

    return EXIT_SUCCESS;
}