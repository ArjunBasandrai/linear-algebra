#pragma once 

#include "defs.h"

Matrix *create_matrix(int rows, int cols);
void free_matrix(Matrix *m);
void print_matrix(Matrix *m);
Matrix* copy_matrix(Matrix* m);
void fill_matrix(Matrix* m, double value);
void zeros_matrix(Matrix* m);

int is_square_matrix(Matrix* m);
void identity_matrix(Matrix* m);

void save_matrix(const Matrix* m, const char* filename);
Matrix* load_matrix(const char* filename);

Matrix *flatten(Matrix *m, int axis);
Matrix* reshape(Matrix *m, int rows, int cols);

void initialize_weights(Matrix* matrix, int activation, int n, ...);

int argmax(Matrix *m);