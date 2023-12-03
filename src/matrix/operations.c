#include "operations.h"
#include "defs.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

void msin(Matrix* matrix, int in_deg) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            double arg = (in_deg) ? PI * matrix->data[i][j] / 180 : matrix->data[i][j];
            matrix->data[i][j] = sin(arg);
        }
    }
}
void mcos(Matrix* matrix, int in_deg) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            double arg = (in_deg) ? PI * matrix->data[i][j] / 180 : matrix->data[i][j];
            matrix->data[i][j] = cos(arg);
        }
    }
}
void mtan(Matrix* matrix, int in_deg) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            double arg = (in_deg) ? PI * matrix->data[i][j] / 180 : matrix->data[i][j];
            matrix->data[i][j] = tan(arg);
        }
    }
}
void mlog(Matrix* matrix) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            if (matrix->data[i][j] < 0) {
                printf("ERROR: cannot take log of negative number %f\n",matrix->data[i][j]);
                assert(0);
            }
            matrix->data[i][j] = log(matrix->data[i][j]);
        }
    }
}
void mlog_base(Matrix* matrix,double base) {
    if (base <= 0) {
        fprintf(stderr,"ERROR: cannot take log of negative number %f\n",base);
        assert(0);
    }
    double b = log(base);
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            if (matrix->data[i][j] < 0) {
                fprintf(stderr,"ERROR: cannot take log of negative number %f\n",matrix->data[i][j]);
                assert(0);
            }
            matrix->data[i][j] = (log(matrix->data[i][j])/b);
        }
    }
}
void mexp(Matrix* matrix) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            matrix->data[i][j] = exp(matrix->data[i][j]);
        }
    }
}

