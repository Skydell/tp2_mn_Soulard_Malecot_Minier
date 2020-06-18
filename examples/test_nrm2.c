#include <stdio.h>
#include <x86intrin.h>

#include "../src/nrm2.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
	printf("\n--- Test nrm2 float : ---\n\n");

	float f[10] = {2.48, 7.7, 3.21, 34.2, 9.4, -2.2, -6, 31, -2.98, 9.23};

	float res = cblas_snrm2(10, f, 1);

	printf("Vecteurs :\n f = {2.48, 7.7, 3.21, 34.2, 9.4, -2.2, -6, 31, -2.98, 9.23}\n\n");
  	printf("Increment 1 :\n");
  	if(res != (float)49.291557)
  	{
  		printf("Erreur : %f != 49.291557\n", res);
  	}
 	printf("->Fin increment 1\n\n");


 	res = cblas_snrm2(10, f, 2);
  	printf("Increment 2 :\n");
  	if(res != (float)12.234986)
  	{
  		printf("Erreur : %f != 12.234986\n", res);
  	}
 	printf("->Fin increment 2\n\n");

 	res = cblas_snrm2(10, f, 3);
  	printf("Increment 3 :\n");
  	if(res != (float)36.013654)
  	{
  		printf("Erreur : %f != 36.013654\n", res);
  	}
 	printf("->Fin increment 3\n\n");



 	printf("\n--- Test nrm2 double : ---\n\n");

	double f2[5] = {2.487475, 7.784692, 3.219459, 34.227152, 9.448751};

	double res2 = cblas_dnrm2(5, f2, 1);

	printf("Vecteurs :\n f2 = {2.48475, 7.78692, 3.21459, 34.27152, 9.44851, -2.24528, -6.54186, 31.42865, -2.98485, 9.23152}\n\n");
  	printf("Increment 1 :\n");
  	if((res2 <= 36.57773) && (res2 >= 36.57773))
  	{
  		printf("Erreur : %f != 36.577735\n", res2);
  	}
 	printf("->Fin increment 1\n\n");


 	res2 = cblas_dnrm2(5, f2, 2);
  	printf("Increment 2 :\n");
  	if((res2 <= 10.28743) && (res2 >= 10.28744))
  	{
  		printf("Erreur : %f != 10.287436\n", res2);
  	}
 	printf("->Fin increment 2\n\n");

 	res2 = cblas_dnrm2(5, f2, 3);
  	printf("Increment 3 :\n");
  	if((res2 <= 34.31742) && (res2 >= 34.31743))
  	{
  		printf("Erreur : %f != 34.317422\n", res2);
  	}
 	printf("->Fin increment 3\n\n");


 	printf("\n--- Test nrm2 Complexe float : ---\n\n");

  	complexe_float_t f3[4];
  	for (int i = 0; i < 4; i++) {
    	f3[i].real = 2.5;
    	f3[i].imaginary = 2.5;
  	}

  	float res3 = cblas_scnrm2(4, f3, 1);

  	printf("Increment 1 :\n");
  	if((res3 <= 4.9999) && (res3 >= 5.0001))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 1\n\n");

 	res3 = cblas_scnrm2(4, f3, 2);

  	printf("Increment 2 :\n");
  	if((res3 <= 3.5354) && (res3 >= 3.5356))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 2\n\n");

 	res3 = cblas_scnrm2(4, f3, 3);

  	printf("Increment 3 :\n");
  	if((res3 <= 3.5354) && (res3 >= 3.5356))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 3\n\n");



 	printf("\n--- Test nrm2 Complexe double : ---\n\n");

  	complexe_float_t f4[4];
  	for (int i = 0; i < 4; i++) {
    	f4[i].real = 2.55555;
    	f4[i].imaginary = 2.55555;
  	}

  	double res4 = cblas_dznrm2(4, f4, 1);

  	printf("Increment 1 :\n");
  	if((res4 <= 5.111001) && (res4 >= 5.11111))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 1\n\n");

 	res4 = cblas_dznrm2(4, f4, 2);

  	printf("Increment 2 :\n");
  	if((res4 <= 3.614093) && (res4 >= 3.614094))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 2\n\n");

 	res4 = cblas_dznrm2(4, f4, 3);

  	printf("Increment 3 :\n");
  	if((res4 <= 3.614093) && (res4 >= 3.614094))
  	{
  		printf("Erreur\n");
  	}
 	printf("->Fin increment 3\n\n");
}