#include <stdio.h>
#include <math.h>

#include "src/matrix/defs.h"
#include "src/matrix/matrix.h"
#include "src/matrix/operations.h"

int main() {
    Matrix *m = create_matrix(3, 3);
    Matrix *ms = create_matrix(3, 3);
    fill_matrix(m,10);
    fill_matrix(ms, 20);
    print_matrix(m);
    printf("\n");
    print_matrix(ms);
    printf("\n");
    print_matrix(add(m, ms));
    printf("\n");
    print_matrix(subtract(m, ms));
    printf("\n");
    print_matrix(multiply(m, ms));
    printf("\n");
    print_matrix(divide(m, ms));
    printf("\n");
    free_matrix(m);
    free_matrix(ms);
    return 0;
}