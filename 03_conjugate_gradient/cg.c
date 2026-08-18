#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cg.h"

double dot(const double *a, const double *b, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

double vec_norm(const double *v, int n)
{
    return sqrt(dot(v, v, n));
}

void axpy(double alpha, const double *x, double *y, int n)
{
    for (int i = 0; i < n; i++)
        y[i] += alpha * x[i];
}

void vec_copy(double *dst, const double *src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

CG_Result cg_solve(MatVec_func matvec,
                   const double *b,
                   double *x,
                   int n,
                   int max_iter,
                   double tol,
                   void *data)
{
    CG_Result result;
    result.converged = 0;

    double *r = (double *)malloc(n * sizeof(double));
    double *p = (double *)malloc(n * sizeof(double));
    double *Ap = (double *)malloc(n * sizeof(double));

    if (!r || !p || !Ap)
    {
        printf("CG: memory allocation failed\n");
        exit(1);
    }

    vec_copy(r, b, n);
    vec_copy(p, r, n);

    double r_dot_r = dot(r, r, n);
    double r0_norm = sqrt(r_dot_r);
    double r_dot_r_new = 0.0;

    if (r0_norm < 1e-14)
    {
        result.iterations = 0;
        result.final_residual = 0.0;
        result.converged = 1;
        free(r);
        free(p);
        free(Ap);
        return result;
    }

    int iter;
    for (iter = 0; iter < max_iter; iter++)
    {

        matvec(p, Ap, n, data);

        double pAp = dot(p, Ap, n);
        double alpha = r_dot_r / pAp;

        axpy(alpha, p, x, n);

        axpy(-alpha, Ap, r, n);

        r_dot_r_new = dot(r, r, n);
        double rel_res = sqrt(r_dot_r_new) / r0_norm;

        if (rel_res < tol)
        {
            result.converged = 1;
            iter++;
            break;
        }

        double beta = r_dot_r_new / r_dot_r;
        for (int i = 0; i < n; i++)
            p[i] = r[i] + beta * p[i];

        r_dot_r = r_dot_r_new;
    }

    result.iterations = iter;
    result.final_residual = sqrt(r_dot_r_new) / r0_norm;

    free(r);
    free(p);
    free(Ap);

    return result;
}