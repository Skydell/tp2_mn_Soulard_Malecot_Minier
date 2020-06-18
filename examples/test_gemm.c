#include <stdio.h>
#include <x86intrin.h>

#include "../src/gemm.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test gemm float : ---\n\n");

  float a1[4];
  float b1[4];
  float c1[4];
  float alpha = 3.2;
  float beta = 4.5;

  for (size_t i = 0; i < 4; i++) {
    a1[i] = 1;
    b1[i] = 1;
    c1[i] = 1;
  }

  cblas_sgemm(2, 2, 2, alpha, a1, 0, b1, 0, beta, c1, 0);

  printf("Test matrice :\n A = (1 1) B = (1 1) C = (1 1)\n     (1 1)     (1 1)     (1 1)\net alpha = 3.2 et beta = 4.5 :\n");
  for (int i = 0; i < 4; i++) {
    if (c1[i] != 2* alpha + beta){
      printf("Error index : %i \n", i);
    }
  }
  printf("-> Fin du test\n\n");

  for (size_t i = 0; i < 4; i++) {
    if (i%2 == 0){
      a1[i] = 0;
      b1[i] = 1;
      c1[i] = 1;
    } else {
      a1[i] = 1;
      b1[i] = 0;
      c1[i] = 1;
    }
  }

  cblas_sgemm(2, 2, 2, alpha, a1, 0, b1, 0, beta, c1, 0);

  printf("Test matrice :\n A = (0 1) B = (1 0) C = (0 1)\n     (1 0)     (0 1)     (1 0)\net alpha = 3.2 et beta = 4.5 :\n");
  for (int i = 0; i < 4; i++) {
    if (i%2 == 0){
      if (c1[i] != beta + alpha) {
        printf("Error index : %i\n", i);
        printf("%f != %f\n", c1[i], beta + alpha);
      }
    } else {
      if (c1[i] != beta){
        printf("Error index : %i \n", i);
        printf("%f != %f\n", c1[i], beta);
      }
    }
  }
  printf("-> Fin du test\n\n");

  printf("\n--- Test gemm double : ---\n\n");

  double a2[4];
  double b2[4];
  double c2[4];
  double alpha2 = 3.229180;
  double beta2 = 4.52314;

  for (size_t i = 0; i < 4; i++) {
    a2[i] = 0;
    b2[i] = 1.29389;
    c2[i] = 2.00001;
  }

  cblas_dgemm(2, 2, 2, alpha2, a2, 0, b2, 0, beta2, c2, 0);

  printf("Test matrice :\n A = (0 0) B = (1.29389 1.29389) C = (2.00001 2.00001)\n     (0 0)     (1.29389 1.29389)     (2.00001 2.00001)\net alpha = 3.229180 et beta = 4.52314 :\n");
  for (int i = 0; i < 4; i++) {
    if (c2[i] != 2.00001 * beta2){
      printf("Error index : %i \n", i);
      printf("%f != %f\n", c2[i], 2.00001 * beta2);
    }
  }
  printf("-> Fin du test\n\n");

  for (size_t i = 0; i < 4; i++) {
    a2[i] = 2.39389;
    b2[i] = 1;
    c2[i] = 4.83949;
  }

  cblas_dgemm(2, 2, 2, alpha2, a2, 0, b2, 0, beta2, c2, 0);

  printf("Test matrice :\n A = (2.39389 2.39389) B = (1 1) C = (4.83949  4.83949)\n     (2.39389 2.39389)     (1 1)     (4.83949  4.83949)\net alpha = 3.2 et beta = 4.5 :\n");
  for (int i = 0; i < 4; i++) {
    if (c2[i] > 4.83949 * beta2 + 2* 2.39389* alpha2+ 0.001 || c2[i] < 4.83949 * beta2 + 2* 2.39389 *alpha2 - 0.001){
      printf("Error index : %i \n", i);
      printf("%f != %f\n", c2[i], 4.83949 * beta2 + 2*2.39389* alpha2);
    }
  }
  printf("-> Fin du test\n\n");

  printf("\n--- Test gemm Complexe float : ---\n\n");

  complexe_float_t a3[4];
  complexe_float_t b3[4];
  complexe_float_t c3[4];
  complexe_float_t alpha3[1];
  complexe_float_t beta3[1];

  alpha3[0].real = 2.5;
  alpha3[0].imaginary = 0;

  beta3[0].real = 0;
  beta3[0].imaginary = 2;

  for (size_t i = 0; i < 4; i++) {
    a3[i].real = 1.5;
    a3[i].imaginary = 1;
    b3[i].real = 1;
    b3[i].imaginary = 0;
    c3[i].real = 2.01;
    c3[i].imaginary = 3.2;
  }
/*
  cblas_cgemm(2, 2, 2, alpha3, a3, 0, b3, 0, beta3, c3, 0);
*/
  printf("Test matrice :\n A = (1.5+i 1.5+i) B = (1 1) C = (2.01+3.2i 2.01+3.2i)\n     (1.5+i 1.5+i)     (1 1)     (2.01+3.2i 2.01+3.2i)\net alpha = 2.5 et beta = 2i :\n");
  for (int i = 0; i < 4; i++) {
    if (c3[i].real != 3*alpha3[0].real - 2*3.2 || c3[i].imaginary != alpha3[0].real + 2*2.01){
      printf("Error index : %i \n", i);
      printf("%f + i* %f != %f + i* %f\n", c3[i].real, c3[i].imaginary, 3*alpha3[0].real - 2*3.2, alpha3[0].real + 2*2.01);
    }
  }
  printf("-> Fin du test\n\n");

  printf("\n--- Test gemm Complexe double : ---\n\n");

  complexe_double_t a4[4];
  complexe_double_t b4[4];
  complexe_double_t c4[4];
  complexe_double_t alpha4[1];
  complexe_double_t beta4[1];

  alpha4[0].real = 2.050505;
  alpha4[0].imaginary = 0;

  beta4[0].real = 0;
  beta4[0].imaginary = 1.050505;

  for (size_t i = 0; i < 4; i++) {
    a4[i].real = 1.000000;
    a4[i].imaginary = 1;
    b4[i].real = 1.00000;
    b4[i].imaginary = 1;
    c4[i].real = 2.23871;
    c4[i].imaginary = 3.22174;
  }
/*
  cblas_zgemm(2, 2, 2, alpha4, a4, 0, b4, 0, beta4, c4, 0);
*/
  printf("Test matrice :\n A = (1.000000+i 1.000000+i) B = (1.000000+i 1.000000+i) C = (2.23871+3.22174i 2.23871+3.22174i)\n     (1.000000+i 1.000000+i)     (1.000000+i 1.000000+i)     (2.23871+3.22174i 2.23871+3.22174i)\net alpha = 2.050505 et beta = 1.050505i :\n");
  for (int i = 0; i < 4; i++) {
    if (c4[i].real != -3.22174*beta4[0].imaginary || 4*alpha4[0].real + 2.23871*beta4[0].imaginary){
      printf("Error index : %i \n", i);
      printf("%f + i* %f != %f + i* %f\n", c4[i].real, c4[i].imaginary, -3.22174*beta4[0].imaginary , 4*alpha4[0].real + 2.23871*beta4[0].imaginary);
    }
  }
  printf("-> Fin du test\n\n");


}
