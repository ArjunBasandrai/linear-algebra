#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <float.h>

#include "numc.h"

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double** )malloc(rows * sizeof(double*));
    for (int i=0; i<rows; i++) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i=0; i<matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* copy_matrix(Matrix* matrix) {
    Matrix* copy = create_matrix(matrix->rows, matrix->cols);
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            copy->data[i][j] = matrix->data[i][j];
        }
    }
    return copy;
}

void fill_matrix(Matrix* matrix, double value) {
    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            matrix->data[i][j] = value;
        }
    }
}

void zeros_matrix(Matrix* matrix) {
    fill_matrix(matrix, 0.0);
}

int is_square_matrix(Matrix* matrix) {
    return matrix->rows == matrix->cols;
}

void identity_matrix(Matrix* matrix) {
    if (!is_square_matrix(matrix)) {
        fprintf(stderr, "ERROR: Cannot create identity matrix for non-square matrix of size (%d, %d)\n", matrix->rows, matrix->cols);
        exit(EXIT_FAILURE);
    }

    assert(is_square_matrix(matrix));

    zeros_matrix(matrix);
    for (int i=0; i<matrix->rows; i++) {
        matrix->data[i][i] = 1.0;
    }
}

void save_matrix(const Matrix *matrix, const char* filename) {
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d %d\n", matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            fprintf(f, "%.6f ", matrix->data[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

Matrix* load_matrix(const char* filename) {
    FILE *f = fopen(filename, "r");
    int rows, cols;
    fscanf(f, "%d %d\n", &rows, &cols);
    Matrix* matrix = create_matrix(rows, cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fscanf(f, "%lf", &matrix->data[i][j]);
        }
        fscanf(f, "\n");
    }
    fclose(f);
    return matrix;
}

Matrix *flatten(Matrix *matrix, int axis) {
    if (axis != 0 && axis != 1) {
        fprintf(stderr, "ERROR: Invalid axis: %d\n", axis);
        exit(EXIT_FAILURE);
    }

    assert(axis == 0 || axis == 1);

    Matrix *flat; 
    if (axis == 0) {
        flat = create_matrix(1, matrix->rows * matrix->cols);
    } else if (axis == 1) {
        flat = create_matrix(matrix->rows * matrix->cols, 1);
    } 

    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            if (axis == 0) {
                flat->data[0][i * matrix->cols + j] = matrix->data[i][j];
            } else if (axis == 1) {
                flat->data[i * matrix->cols + j][0] = matrix->data[i][j];
            }
        }
    }
    return flat;
}

Matrix* reshape(Matrix *matrix, int rows, int cols) {
    
    if (rows * cols != matrix->rows * matrix->cols) {
        fprintf(stderr, "ERROR: Invalid reshape dimensions (%d, %d) for matrix of size (%d, %d)\n", rows, cols, matrix->rows, matrix->cols);
        exit(EXIT_FAILURE);
    }

    assert(rows * cols == matrix->rows * matrix->cols);

    Matrix *flat = flatten(matrix, 0);
    Matrix* m = create_matrix(rows, cols);

    int k = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            m->data[i][j] = flat->data[0][k++];
        }
    }

    free_matrix(flat);

    return m;
}

double random_uniform(double min, double max) {
    assert(min <= max);
    return (double)rand() / RAND_MAX * (max - min) + min;
}

void initialize_weights(Matrix* matrix, int activation, int n, ...) {
    if (n <= 0) {
        fprintf(stderr, "ERROR: Invalid size specified for (n=%d)\n",n);
        exit(EXIT_FAILURE);
    }
    assert(n > 0);

    va_list args;
    va_start(args, n);
    
    double min, max;
    if (activation == RELU) {
        min = -sqrt(2.0 / n);
        max = sqrt(2.0 / n);

    } else if (activation == SIGMOID) {
        int m = va_arg(args, int);
        if (m <= 0) {
            fprintf(stderr, "ERROR: Invalid size specified for (m=%d)\n",m);
            exit(EXIT_FAILURE);
        }
        assert(m > 0);

        min = -sqrt(6.0 / (n + m));
        max = sqrt(6.0 / (n + m));

    } else {
        min = -1.0 / sqrt(n);
        max = 1.0 / sqrt(n);
    }

    va_end(args);

    for (int i=0; i<matrix->rows; i++) {
        for (int j=0; j<matrix->cols; j++) {
            matrix->data[i][j] = random_uniform(min, max);
        }
    }
}

int argmax(Matrix *m) {
    if (m->cols != 1) {
        fprintf(stderr, "\nERROR: Cannot find argmax of non-vector matrix of size (%d, %d)\n  >> argmax fucntion expects vector of size Mx1\n  >> use reshape function to reshape this matrix to (%d, 1)\n\n", m->rows, m->cols, m->rows * m->cols);
        exit(EXIT_FAILURE);
    }
    double max_val = -DBL_MAX;
    int max_idx = 0;
    for (int i = 0; i < m->rows; i++) {
        if (m->data[i][0] > max_val) {
            max_val = m->data[i][0];
            max_idx = i;
        }
    }
    return max_idx;
}