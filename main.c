#include <stdio.h>

#include "src/matrix/matrix.h"

int main() {
    Matrix *m = create_matrix(2, 2);
    fill_matrix(m, 1);

    print_matrix(flatten(m, 1));

    free_matrix(m);
    return 0;
}