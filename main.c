#include <stdio.h>

#include "src/matrix/matrix.h"

int main() {
    Matrix *m = create_matrix(5, 5);
    initialize_weights(m, TANH, 2, 223);
    print_matrix(m);
    free_matrix(m);
    return 0;
}