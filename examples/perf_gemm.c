#include <stdio.h>
#include <x86intrin.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE];
typedef complexe_float_t* vscomplexe[VECSIZE];
typedef complexe_double_t* vdcomplexe[VECSIZE];

vfloat mat1, mat2, mat3 ;
vdouble mat4, mat5, mat6;
vscomplexe mat7, mat8, mat9 ;
vdcomplexe mat10, mat11, mat12 ;

void vectorf_init (vfloat V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vectord_init (vdouble V, double x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void vectorcs_init (vscomplexe V, float r, float im)
{
	register unsigned int i ;

	for (i = 0; i < VECSIZE; i++) {
		V[i] = malloc(sizeof(complexe_float_t));
		V[i]->real = r;
		V[i]->imaginary = im;
	}
 
  return ;
}

void vectorcd_init (vdcomplexe V, double r, double im)
{
	register unsigned int i ;

	for (i = 0; i < VECSIZE; i++) {
		V[i] = malloc(sizeof(complexe_double_t));
		V[i]->real = r;
		V[i]->imaginary = im;
	}

  return ;
}

void vector_print (vfloat V)
{
  register unsigned int i ;
  
  for (i = 0; i < VECSIZE; i++)
  printf ("%f ", V[i]) ;
  printf ("\n") ;
  
  return ;
}

int main (int argc, char **argv)
{
	unsigned long long start, end ;
	int i, m, n, k;
	m = 256;
	n = 256;
	k = 256;
	init_flop () ;
 
	for (i = 0 ; i < NB_FOIS; i++)
	{
		float alpha = 12;
		float beta = 14.2;
		vectorf_init (mat1, 149.25);
		vectorf_init (mat2, 154.087) ;
		vectorf_init (mat3, 4545.0545) ;

		start = _rdtsc () ;
		cblas_sgemm(101, 111, 111, m, n, k, alpha, mat1, 0, mat2, 1, beta, mat3, 1) ;
		end = _rdtsc () ;

		printf ("cblas_sgemm %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sgemm ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	
	for (i = 0 ; i < NB_FOIS; i++)
	{
		double alpha = 121.154658;
		double beta = -14.4782;
		vectord_init (mat4, 124.5556);
		vectord_init (mat5, 4581.14) ;
		vectord_init (mat6, 45896.12) ;

		start = _rdtsc () ;
		cblas_dgemm(101, 111, 111, m, n, k, alpha, mat4, 0, mat5, 1, beta, mat6, 1) ;
		end = _rdtsc () ;

		printf ("cblas_dgemm %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("degemm ", 2 * VECSIZE, end-start) ; 
	 }
	 
	 printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_float_t* alpha = malloc(sizeof(complexe_float_t));
		complexe_float_t* beta = malloc(sizeof(complexe_float_t));
		alpha->real = 124.12;
		beta->real = 44542.13;
		alpha->imaginary = 214.379;
		beta->imaginary = 1897.1;
		vectorcs_init (mat7, 1254.15, 78.1548);
		vectorcs_init (mat8, 3.5, 45.2) ;
		vectorcs_init (mat9, 87236.0, 2.15656) ;
		
		start = _rdtsc () ;
		cblas_cgemm(101, 111, 111, m, n, k, alpha, mat7, 0, mat8, 1, beta, mat9, 1) ;
		end = _rdtsc () ;

		printf ("cblas_cgemm %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("cgemm ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_double_t* alpha = malloc(sizeof(complexe_double_t));
		complexe_double_t* beta = malloc(sizeof(complexe_double_t));
		alpha->real = 124.12;
		beta->real = -44542.13;
		alpha->imaginary = -214.379;
		beta->imaginary = 1897.1;
		vectorcd_init (mat10, 9812.124, -4567.24);
		vectorcd_init (mat11, 4581.14, 457.13) ;
		vectorcd_init (mat12, 716.0, -712493.57) ;

		start = _rdtsc () ;
		cblas_zgemm(101, 111, 111, m, n, k, alpha, mat10, 0, mat11, 1, beta, mat12, 1) ;
		end = _rdtsc () ;

		printf ("cblas_zgemm %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("zgemm ", 2 * VECSIZE, end-start) ; 
	}
}
