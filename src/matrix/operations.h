#pragma once

#include "defs.h"
#include "matrix.h"

void mcos(Matrix *m, int in_deg);
void msin(Matrix *m, int in_deg);
void mtan(Matrix *m, int in_deg);
void mlog(Matrix *m);
void mlog_base(Matrix *m, double base);
void mexp(Matrix *m);

Matrix* transpose(Matrix *m);

Matrix* add(Matrix *m1, Matrix *m2);
Matrix* subtract(Matrix *m1, Matrix *m2);
Matrix* multiply(Matrix *m1, Matrix *m2);
Matrix* divide(Matrix *m1, Matrix *m2);

Matrix* dot(Matrix *m1, Matrix *m2);