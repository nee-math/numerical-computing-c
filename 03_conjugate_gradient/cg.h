#ifndef CG_H
#define CG_H

#include <math.h>

typedef void (*MatVec_func)(const double *x, double *y,
                            int n, void *data);

typedef struct
{
    int iterations;
    double final_residual;
    int converged;
} CG_Result;

CG_Result cg_solve(MatVec_func matvec,
                   const double *b,
                   double *x,
                   int n,
                   int max_iter,
                   double tol,
                   void *data);

double dot(const double *a, const double *b, int n);

double vec_norm(const double *v, int n);

void axpy(double alpha, const double *x, double *y, int n);

void vec_copy(double *dst, const double *src, int n);

#endif