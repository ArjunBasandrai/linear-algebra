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