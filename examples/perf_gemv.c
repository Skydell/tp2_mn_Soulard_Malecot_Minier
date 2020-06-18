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

vfloat vec1, vec2, mat1 ;
vdouble vec3, vec4, mat2;
vscomplexe vec5, vec6, mat3;
vdcomplexe vec7, vec8, mat4;

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
	int i, m, n;
	m = 256;
	n = 256;
	init_flop () ;
 
	for (i = 0 ; i < NB_FOIS; i++)
	{
		float alpha = 12;
		float beta = 14.2;
		vectorf_init (mat1, 149.25);
		vectorf_init (vec1, 1.0) ;
		vectorf_init (vec2, 0.0) ;

		start = _rdtsc () ;
		cblas_sgemv(101, 111, m, n, alpha, mat1, 0, vec1, 1, beta, vec2, 1) ;
		end = _rdtsc () ;

		printf ("cblas_sgemv %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sgemv ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	
	for (i = 0 ; i < NB_FOIS; i++)
	{
		double alpha = 121.154658;
		double beta = -14.4782;
		vectord_init (mat2, 124.5556);
		vectord_init (vec3, 4581.14) ;
		vectord_init (vec4, 0.0) ;

		start = _rdtsc () ;
		cblas_dgemv(101, 111, m, n, alpha, mat2, 0, vec3, 1, beta, vec4, 1) ;
		end = _rdtsc () ;

		printf ("cblas_dgemv %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("dgemv ", 2 * VECSIZE, end-start) ; 
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
		vectorcs_init (mat3, 1254.15, 78.1548);
		vectorcs_init (vec5, 3.5, 45.2) ;
		vectorcs_init (vec6, 0.0, 0.0) ;
		
		start = _rdtsc () ;
		cblas_cgemv(101, 111, m, n, alpha, mat3, 0, vec5, 1, beta, vec6, 1) ;
		end = _rdtsc () ;

		printf ("cblas_cgemv %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("cgemv ", 2 * VECSIZE, end-start) ; 
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
		vectorcd_init (mat4, 9812.124, -4567.24);
		vectorcd_init (vec7, 4581.14, 457.13) ;
		vectorcd_init (vec8, 0.0, 0.0) ;

		start = _rdtsc () ;
		cblas_zgemv(101, 111, m, n, alpha, mat4, 0, vec7, 1, beta, vec8, 1) ;
		end = _rdtsc () ;

		printf ("cblas_zgemv %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("zgemv ", 2 * VECSIZE, end-start) ; 
	}
}
