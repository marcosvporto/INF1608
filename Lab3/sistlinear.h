#ifndef SISTLINEAR_H
#define SISTLINEAR_H


void gauss (int n, double** A, double* b, double* x);


void cholesky (int n, double** A);

void substituicoes (int n, double** A, double* b, double* x);

#endif