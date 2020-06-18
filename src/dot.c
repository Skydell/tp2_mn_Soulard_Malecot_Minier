#include "../include/mnblas.h"
#include "../include/complexe2.h"
#include <stdio.h>


float mncblas_sdot(const int N, const float *X, const int incX, const float *Y, const int incY) {
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	register float dot = 0.0 ;

	for (; ((i < N) && (j < N)) ; i += incX, j+=incY) {
		dot = dot + X [i] * Y [j] ;
	}
	return dot ;
}

double mncblas_ddot(const int N, const double *X, const int incX, 
                 const double *Y, const int incY)
{
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  register double dot = 0.0 ;
  
  for (; ((i < N) && (j < N)) ; i += incX, j+=incY)
    {
      dot = dot + X [i] * Y [j] ;
    }

  return dot ;
}

void   mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	((complexe_float_t*)dotu)->real = 0;
	((complexe_float_t*)dotu)->imaginary = 0;

	for (; ((i < N) && (j < N)) ; i += incX, j+=incY) {
		((complexe_float_t*)dotu)->real += (*((complexe_float_t**)X)[i]).real * (*((complexe_float_t**)Y)[i]).real;
		((complexe_float_t*)dotu)->imaginary += (*((complexe_float_t**)X)[i]).imaginary * (*((complexe_float_t**)Y)[i]).imaginary;
	}
}


void   mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu)
{
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	((complexe_double_t*)dotu)->real = 0;
	((complexe_double_t*)dotu)->imaginary = 0;

	for (; ((i < N) && (j < N)) ; i += incX, j+=incY) {
		((complexe_double_t*)dotu)->real += (*((complexe_double_t**)X)[i]).real * (*((complexe_double_t**)Y)[i]).real;
		((complexe_double_t*)dotu)->imaginary += (*((complexe_double_t**)X)[i]).imaginary * (*((complexe_double_t**)Y)[i]).imaginary;
	}
}
  
void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	((complexe_float_t*)dotc)->real = 0;
	((complexe_float_t*)dotc)->imaginary = 0;

	for (; ((i < N) && (j < N)) ; i += incX, j+=incY) {
		((complexe_float_t*)dotc)->real += (*((complexe_float_t**)X)[i]).real * (*((complexe_float_t**)Y)[i]).real;
		((complexe_float_t*)dotc)->imaginary += -(*((complexe_float_t**)X)[i]).imaginary * (*((complexe_float_t**)Y)[i]).imaginary;
	}
}
  
void   mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc)
{
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	((complexe_double_t*)dotc)->real = 0;
	((complexe_double_t*)dotc)->imaginary = 0;

	for (; ((i < N) && (j < N)) ; i += incX, j+=incY) {
		((complexe_double_t*)dotc)->real += (*((complexe_double_t**)X)[i]).real * (*((complexe_double_t**)Y)[i]).real;
		((complexe_double_t*)dotc)->imaginary += -(*((complexe_double_t**)X)[i]).imaginary * (*((complexe_double_t**)Y)[i]).imaginary;
	}
}




