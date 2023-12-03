#include <stdio.h>
#include <math.h>

#include "src/matrix/defs.h"
#include "src/matrix/matrix.h"
#include "src/matrix/operations.h"

int main() {
    Matrix *m = create_matrix(3, 3);

    fill_matrix(m, log(1));
    mexp(m);
    print_matrix(m);

    fill_matrix(m, 9);
    mlog_base(m,3);
    print_matrix(m);

    free_matrix(m);
    return 0;
}