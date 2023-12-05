#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "src/matrix/linear_algebra.h"
#include "src/nn/activations.h"

int main() {
    Matrix* m = create_matrix(3,3);
    fill_matrix(m, 1.0);
    print_matrix(m);
    free_matrix(m);
    return 0;
}