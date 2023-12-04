#include <stdlib.h>
#include <math.h>

#include "activation.h"

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double relu(double x) {
    return max(0, x);
}