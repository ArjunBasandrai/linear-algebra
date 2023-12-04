#include <stdio.h>
#include <math.h>

#include "src/matrix/defs.h"
#include "src/matrix/matrix.h"
#include "src/matrix/operations.h"

int main() {
    Matrix *m = create_matrix(1, 2);
    Matrix *ms = create_matrix(2, 3);
    fill_matrix(m, 1.5);
    fill_matrix(ms, 4);
    print_matrix(m);
    print_matrix(ms);
    print_matrix(dot(m, ms));
    free_matrix(m);
    free_matrix(ms);
    return 0;
}