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
 float res ;
 int i ;

 init_flop () ;
 
	for (i = 0 ; i < NB_FOIS; i++)
	   {
		 vectorf_init (vec1, 1.0) ;
		 vectorf_init (vec2, 2.0) ;
		 res = 0.0 ;
		 
		 start = _rdtsc () ;
			res = mncblas_sdot (VECSIZE, vec1, 1, vec2, 1) ;
		 end = _rdtsc () ;
		 
		 printf ("mncblas_sdot %d : res = %3.2f nombre de cycles: %Ld \n", i, res, end-start) ;
		 calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	   }
	  
	 for (i = 0 ; i < NB_FOIS; i++)
	   {
		 vectord_init (vec3, 4581.14) ;
		 vectord_init (vec4, 2147.129) ;
		 res = 0.0 ;
		 
		 start = _rdtsc () ;
			res = mncblas_ddot (VECSIZE, vec3, 1, vec4, 1) ;
		 end = _rdtsc () ;
		 
		 printf ("mncblas_ddot %d : res = %3.2f nombre de cycles: %Ld \n", i, res, end-start) ;
		 calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	   }
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_float_t* res = malloc(sizeof(complexe_float_t));
		vectorcs_init (vec5, 3.5, 45.2) ;
		vectorcs_init (vec6, 214.129, 245.2) ;
		
		start = _rdtsc () ;
		mncblas_cdotu_sub(VECSIZE, vec5, 1, vec6, 1, res) ;
		end = _rdtsc () ;

		printf ("mncblas_cdotu_sub %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	}
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_double_t* res = malloc(sizeof(complexe_double_t));
		vectorcd_init (vec7, 4581.14, 457.13) ;
		vectorcd_init (vec8, 2147.129, -468.12) ;

		start = _rdtsc () ;
		mncblas_zdotu_sub (VECSIZE, vec7, 1, vec8, 1, res) ;
		end = _rdtsc () ;

		printf ("mncblas_zdotu_sub %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	}
	
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_float_t* res = malloc(sizeof(complexe_float_t));
		vectorcs_init (vec5, 3.5, 45.2) ;
		vectorcs_init (vec6, 214.129, 245.2) ;
		
		start = _rdtsc () ;
		mncblas_cdotc_sub(VECSIZE, vec5, 1, vec6, 1, res) ;
		end = _rdtsc () ;

		printf ("mncblas_cdotc_sub %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	}
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_double_t* res = malloc(sizeof(complexe_double_t));
		vectorcd_init (vec7, 4581.14, 457.13) ;
		vectorcd_init (vec8, 2147.129, -468.12) ;

		start = _rdtsc () ;
		mncblas_zdotc_sub (VECSIZE, vec7, 1, vec8, 1, res) ;
		end = _rdtsc () ;

		printf ("mncblas_zdotc_sub %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sdot ", 2 * VECSIZE, end-start) ; 
	}
}
