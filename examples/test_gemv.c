#include <stdio.h>
#include <x86intrin.h>

#include "../src/gemv.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
	printf("\n--- Test gemv float : ---\n\n");

	float f[4] = {1.2, 2.2, 3.2, 4.2};
	float x[2] = {1.2, 6.2};
	float y[2] = {-1.2, 8.2};

	printf("Début du test :\n");

	cblas_sgemv(2, 2, 2, f, 0, x, 1, 6, y, 1);

	if(y[0] != (float)22.96){
		printf("Erreur dans y[0]\n");
	} else if (y[1] <= (float)108.95 && y[1] >= (float)108.96){
		printf("Erreur dans y[1]\n");
	} else {
		printf("->Test réussi\n\n");
	}


	printf("\n--- Test gemv double : ---\n\n");

	double f2[4] = {1.48525, 2.48575, 3.42523, 4.63541};
	double x2[2] = {1, 6};
	double y2[2] = {-1, 8};

	printf("Début du test :\n");

	double* beta = malloc(1);
	beta[0] = 6.45869;

	cblas_dgemv(2, 2, 2.47158, f2, 0, x2, 1, beta, y2, 1);

	if(y2[0] <= (float)34.0746 && y2[0] >= (float)34.0747){
		printf("Erreur dans y[0]\n");
	} else if (y2[1] <= (float)128.87605 && y2[1] >= (float)128.87606){
		printf("Erreur dans y[1]\n");
	} else {
		printf("->Test réussi\n\n");
	}


	printf("\n--- Test gemv Complexe float : ---\n\n");

	complexe_float_t x3[2];
	complexe_float_t y3[2];

	x3[0].real = 45.85;
	x3[0].imaginary = 0;
	x3[1].real = 2.43;
	x3[1].imaginary = 3;

	y3[0].real = 1.35;
	y3[0].imaginary = 0;
	y3[1].real = 10.4;
	y3[1].imaginary = 2;


	complexe_float_t f3[4];
  	f3[0].real = 1.45;
	f3[0].imaginary = 2.3;
	f3[1].real = 2.3;
	f3[1].imaginary = 0;
	f3[2].real = 5.7;
	f3[2].imaginary = 4.8;
	f3[3].real = 7;
	f3[3].imaginary = 9.7;

	printf("Début du test :\n");

	float* beta2 = malloc(1);
	beta2[0] = 10;
	float* alpha = malloc(1);
	alpha[0] = 5;

	cblas_cgemv(2, 2, alpha, f3, 0, x3, 1, beta2, y3, 1);

	if((y3[0].real < (float)373.8575 && y3[0].real >= (float)373.8576) || (y3[0].imaginary < (float)56.1775 && y3[0].imaginary >= (float)56.1776)){
		printf("Erreur dans y[0]\n");
	} else if ((y3[1].real < (float)1350.275 && y3[1].real >= (float)1350.276) || (y3[1].imaginary < (float)1343.255 && y3[1].imaginary >= (float)1343.256)){
		printf("Erreur dans y[1]\n");
	} else {
		printf("->Test réussi\n\n");
	}



	printf("\n--- Test gemv Complexe double : ---\n\n");

	complexe_double_t x4[2];
	complexe_double_t y4[2];

	x4[0].real = 4.325612;
	x4[0].imaginary = 0;
	x4[1].real = 0;
	x4[1].imaginary = 10.52897;

	y4[0].real = 2.38759;
	y4[0].imaginary = 3.56431;
	y4[1].real = 10.68251;
	y4[1].imaginary = 4.365;


	complexe_double_t f4[4];
  	f4[0].real = 3.57836;
	f4[0].imaginary = 10.49728;
	f4[1].real = 10.15556;
	f4[1].imaginary = 0;
	f4[2].real = 20.34682;
	f4[2].imaginary = 5.15796;
	f4[3].real = 2.15689;
	f4[3].imaginary = 4.53261;

	printf("Début du test :\n");

	double* beta3 = malloc(1);
	beta3[0] = 10;
	double* alpha2 = malloc(1);
	alpha2[0] = 5;

	cblas_zgemv(2, 2, alpha2, f4, 0, x4, 1, beta3, y4, 1);

	if((y4[0].real < (double)101.26888 && y4[0].real >= (double)101.26889) || (y4[0].imaginary < (double)797.31683 && y4[0].imaginary >= (double)797.31684)){
		printf("Erreur dans y[0]\n");
	} else if ((y4[1].real < (double)308.26877 && y4[1].real >= (double)308.26878) || (y4[1].imaginary < (double)268.75582 && y4[1].imaginary >= (double)268.75583)){
		printf("Erreur dans y[1]\n");
	} else {
		printf("->Test réussi\n\n");
	}
}