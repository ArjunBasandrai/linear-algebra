#include <stdio.h>

#include "src/matrix/matrix.h"

int main() {
    Matrix *m = create_matrix(3, 3);
    identity_matrix(m);
    m = reshape(m, 9, 1);
    print_matrix(m);
    free_matrix(m);
    return 0;
}