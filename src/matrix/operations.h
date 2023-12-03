#pragma once

#include "matrix.h"

void mcos(Matrix *m, int in_deg);
void msin(Matrix *m, int in_deg);
void mtan(Matrix *m, int in_deg);
void mlog(Matrix *m);
void mlog_base(Matrix *m, double base);
void mexp(Matrix *m);