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

vfloat vec1, vec2 ;
vdouble vec3, vec4;
vscomplexe vec5, vec6;
vdcomplexe vec7, vec8;

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
	int i ;
	init_flop () ;
 
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectorf_init (vec1, 1.0) ;
		vectorf_init (vec2, 0.0) ;

		start = _rdtsc () ;
		mncblas_sswap(VECSIZE, vec1, 1, vec2, 1) ;
		end = _rdtsc () ;

		printf ("mncblas_sswap %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sswap ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectord_init (vec3, 4581.14) ;
		vectord_init (vec4, 0.0) ;

		start = _rdtsc () ;
		mncblas_dswap(VECSIZE, vec3, 1, vec4, 1) ;
		end = _rdtsc () ;

		printf ("mncblas_dswap %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("dswap ", 2 * VECSIZE, end-start) ; 
	 }
	 
	 printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectorcs_init (vec5, 3.5, 45.2) ;
		vectorcs_init (vec6, 0.0, 0.0) ;
		
		start = _rdtsc () ;
		mncblas_cswap(VECSIZE, vec5, 1, vec6, 1) ;
		end = _rdtsc () ;

		printf ("mncblas_cswap %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("cswap ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectorcd_init (vec7, 4581.14, 457.13) ;
		vectorcd_init (vec8, 0.0, 0.0) ;

		start = _rdtsc () ;
		mncblas_zswap(VECSIZE, vec7, 1, vec8, 1) ;
		end = _rdtsc () ;

		printf ("mncblas_zswap %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("zswap ", 2 * VECSIZE, end-start) ; 
	}
}
