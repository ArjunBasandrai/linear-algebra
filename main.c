#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#include "src/matrix/defs.h"
#include "src/matrix/matrix.h"
#include "src/matrix/operations.h"

int main() {
    Matrix *m = create_matrix(3, 2);
    for (int i=0; i<m->rows; i++) {
        for (int j=0; j<m->cols; j++) {
            scanf("%lf", &m->data[i][j]);
        }
    }
    print_matrix(m);
    m = reshape(m, 6, 1);
    printf("%d\n", argmax(m));
    free_matrix(m);
    return 0;
}