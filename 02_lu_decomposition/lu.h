#ifndef LU_H
#define LU_H

int lu_decompose(double *A, int *piv, int n);

void lu_solve(const double *LU, const int *piv,
              const double *b, double *x, int n);

double residual_norm(const double *A_orig, const double *x,
                     const double *b, int n);

void print_matrix(const char *label, const double *A, int n);

void print_vector(const char *label, const double *v, int n);

#endif