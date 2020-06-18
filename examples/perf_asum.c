#include <stdio.h>
#include <x86intrin.h>

#include "../src/asum.c"

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat [VECSIZE] ;
typedef double vdouble [VECSIZE];
typedef complexe_float_t* vscomplexe[VECSIZE];
typedef complexe_double_t* vdcomplexe[VECSIZE];

vfloat vec1;
vdouble vec2;
vscomplexe vec3;
vdcomplexe vec4;

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
	int i;
	init_flop () ;
 
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectorf_init (vec1, 35.0) ;

		start = _rdtsc () ;
		cblas_sasum(VECSIZE, vec1, 1) ;
		end = _rdtsc () ;

		printf ("cblas_sasum %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("sasum ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	
	for (i = 0 ; i < NB_FOIS; i++)
	{
		vectord_init (vec2, 4891.14) ;

		start = _rdtsc () ;
		cblas_dasum(VECSIZE, vec2, 1) ;
		end = _rdtsc () ;

		printf ("cblas_dasum %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("dasum ", 2 * VECSIZE, end-start) ; 
	 }
	 
	 printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_float_t* ac = malloc(sizeof(complexe_float_t));
		ac->real = 125.223;
		ac->imaginary = 1.56;
		vectorcs_init (vec3, 3.5, 45.2) ;
		
		start = _rdtsc () ;
		cblas_casum(VECSIZE, vec3, 1) ;
		end = _rdtsc () ;

		printf ("cblas_casum %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("casum ", 2 * VECSIZE, end-start) ; 
	}
	
	printf("----------------------------------------\n");
	   
	for (i = 0 ; i < NB_FOIS; i++)
	{
		complexe_double_t* ac = malloc(sizeof(complexe_double_t));
		ac->real = 1205.223;
		ac->imaginary = -61.56;
		vectorcd_init (vec4, 4581.14, 457.13) ;

		start = _rdtsc () ;
		cblas_zasum(VECSIZE, vec4, 1) ;
		end = _rdtsc () ;

		printf ("cblas_zasum %d : nombre de cycles: %Ld \n", i, end-start) ;
		calcul_flop ("zasum ", 2 * VECSIZE, end-start) ; 
	}
}
