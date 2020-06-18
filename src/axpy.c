#include "../include/mnblas.h"
#include "../include/complexe2.h"
#include <stdio.h>

void cblas_saxpy (const int n, const float a, const float *x, const int incx, float *y, const int incy) {
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		y[j] = a * x[i] + y[j];
	}
}

void cblas_daxpy (const int n, const double a, const double *x, const int incx, double *y, const int incy) {
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
  
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		y[j] = a * x[i] + y[j];
	}
}

void cblas_caxpy (const int n, const void *a, const void *x, const int incx, void *y, const int incy) {
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	complexe_float_t mult;
  
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		mult = mult_complexe_float((*(complexe_float_t *)a), (((complexe_float_t *)x)[i]));
		(((complexe_float_t *)y)[i]).real = mult.real + (((complexe_float_t *)y)[j]).real;
		(((complexe_float_t *)y)[j]).imaginary = mult.imaginary + (((complexe_float_t *)y)[j]).imaginary;
	}
}

void cblas_zaxpy (const int n, const void *a, const void *x, const int incx, void *y, const int incy) {
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	complexe_double_t mult;
	
	for(; (i < n) && (j < n); i +=  incx, j += incy) {
		mult = mult_complexe_double(*((complexe_double_t *)a), (((complexe_double_t *)x)[i]));
		(((complexe_double_t *)y)[i]).real = mult.real + (((complexe_double_t *)y)[j]).real;
		(((complexe_double_t *)y)[j]).imaginary = mult.imaginary + (((complexe_double_t *)y)[j]).imaginary;
	}
}
