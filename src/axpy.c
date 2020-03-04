#include "mnblas.h"
#include "complexe.h"

void cblas_saxpy (const int n, const float a, const float *x, const int incx, float *y, const int incy) {
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		y[j] = a * x[i] + y[j];
	}
}

void cblas_daxpy (const int n, const double a, const double *x, const int incx, double *y, const int incy) {
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		y[j] = a * x[i] + y[j];
	}
}

void cblas_caxpy (const int n, const void *a, const void *x, const int incx, void *y, const int incy) {
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		((complexe_float_t)y[j]).real = a * ((complexe_float_t)x[i]).real + ((complexe_float_t)y[j]).real;
		((complexe_float_t)y[j]).imaginary = a * ((complexe_float_t)x[i]).imaginary + ((complexe_float_t)y[j]).imaginary;
	}
}

void cblas_zaxpy (const int n, const void *a, const void *x, const int incx, void *y, const int incy) {
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		((complexe_double_t)y[j]).real = a * ((complexe_double_t)x[i]).real + ((complexe_double_t)y[j]).real;
		((complexe_double_t)y[j]).imaginary = a * ((complexe_double_t)x[i]).imaginary + ((complexe_double_t)y[j]).imaginary;
	}
}
