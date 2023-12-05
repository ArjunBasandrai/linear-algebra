#pragma once

#define PI 3.14159265358979323846
#define E 2.71828182845904523536

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

enum activation {
    SIGMOID,
    RELU,
    TANH,
    SOFTMAX,
    LINEAR,
    NONE
};

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

void mcos(Matrix *m, int in_deg);
void msin(Matrix *m, int in_deg);
void mtan(Matrix *m, int in_deg);
void mlog(Matrix *m);
void mlog_base(Matrix *m, double base);
void mexp(Matrix *m);

Matrix* transpose(Matrix *m);

Matrix* add(Matrix *m1, Matrix *m2);
Matrix* add_scalar(Matrix *m1, double n);
Matrix* subtract(Matrix *m1, Matrix *m2);
Matrix* multiply(Matrix *m1, Matrix *m2);
Matrix* divide(Matrix *m1, Matrix *m2);
Matrix* scale(Matrix *m1, double n);

Matrix* dot(Matrix *m1, Matrix *m2);