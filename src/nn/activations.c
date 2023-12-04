#include <stdlib.h>
#include <math.h>

#include "activation.h"

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double swish(double x) {
    return x * sigmoid(x);
}

double relu(double x) {
    return max(0, x);
}

double leaky_relu(double x) {
    return max(0.01 * x, x);
}