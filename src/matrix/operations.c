#include "operations.h"
#include "defs.h"

#include <stdio.h>
#include <stdlib.h>
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

Matrix* transpose(Matrix *m) {
    Matrix *new = create_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            new->data[j][i] = m->data[i][j];
        }
    }
    return new;
}

Matrix* add(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fprintf(stderr, "ERROR: Cannot add matrices of different sizes (%d, %d) and (%d, %d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(EXIT_FAILURE);
    }

    assert(m1->rows == m2->rows && m1->cols == m2->cols);

    Matrix* sum = create_matrix(m1->rows, m1->cols);
    for (int i=0; i<m1->rows; i++) {
        for (int j=0; j<m1->cols; j++) {
            sum->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return sum;
}

Matrix* subtract(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fprintf(stderr, "ERROR: Cannot subtract matrices of different sizes (%d, %d) and (%d, %d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(EXIT_FAILURE);
    }

    assert(m1->rows == m2->rows && m1->cols == m2->cols);

    Matrix* diff = create_matrix(m1->rows, m1->cols);
    for (int i=0; i<m1->rows; i++) {
        for (int j=0; j<m1->cols; j++) {
            diff->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return diff;
}

Matrix* multiply(Matrix* m1, Matrix* m2) {
    if (m1->cols != m2->rows) {
        fprintf(stderr, "ERROR: Cannot multiply matrices of sizes (%d, %d) and (%d, %d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(EXIT_FAILURE);
    }

    assert(m1->cols == m2->rows);

    Matrix* product = create_matrix(m1->rows, m2->cols);
    for (int i=0; i<m1->rows; i++) {
        for (int j=0; j<m2->cols; j++) {
            for (int k=0; k<m1->cols; k++) {
                product->data[i][j] = m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return product;
}

Matrix* divide(Matrix* m1, Matrix* m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fprintf(stderr, "ERROR: Cannot divide matrices of different sizes (%d, %d) and (%d, %d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(EXIT_FAILURE);
    }

    assert(m1->rows == m2->rows && m1->cols == m2->cols);

    Matrix* quotient = create_matrix(m1->rows, m1->cols);
    for (int i=0; i<m1->rows; i++) {
        for (int j=0; j<m1->cols; j++) {
            if (m2->data[i][j] == 0) {
                fprintf(stderr, "ERROR: Cannot divide by zero\n");
                exit(EXIT_FAILURE);
            }
            quotient->data[i][j] = m1->data[i][j] / m2->data[i][j];
        }
    }
    return quotient;
}

Matrix* dot(Matrix* m1, Matrix* m2) {
    if (m1->cols != m2->rows) {
        fprintf(stderr, "ERROR: Cannot dot matrices of sizes (%d, %d) and (%d, %d)\n", m1->rows, m1->cols, m2->rows, m2->cols);
        exit(EXIT_FAILURE);
    }

    assert(m1->cols == m2->rows);

    Matrix* product = create_matrix(m1->rows, m2->cols);
    for (int i = 0; i<m1->rows; i++) {
        for (int j = 0; j<m2->cols; j++) {
            for (int k = 0; k<m2->rows; k++) {
                product->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return product;
}