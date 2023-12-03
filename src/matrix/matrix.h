#pragma once 

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

void initialize_weights(Matrix* matrix, int activation, int n, ...);