#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#include "src/matrix/defs.h"
#include "src/matrix/matrix.h"
#include "src/matrix/operations.h"

int main() {
    Matrix *m = create_matrix(3, 3);
    identity_matrix(m);
    m = scale(m, 10.5);
    print_matrix(m);
    free_matrix(m);
    return 0;
}