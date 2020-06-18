#include <stdio.h>
#include <x86intrin.h>

#include "../src/axpy.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test axpy float : ---\n\n");
  float prod_f1[3];
  float f[3] = {3.7, 8.2, -2.98};
  float g[3] = {9.8, 1.22, 9.33};

  for (size_t i = 0; i < 3; i++) {
    prod_f1[i] = 2*f[i] + g[i];
  }

  cblas_saxpy(3, 2.0, f, 1, g, 1);

  printf("Vecteurs :\n f = {3.7, 8.2, -2.98}\n g = {9.8, 1.22, 9.33}\n");
  printf("Increment 1 et A = 2 :\n");
  for (int i = 0; i < 3; i++) {
    if (g[i] != prod_f1[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f \n",g[i], prod_f1[i]);
    }
  }
  printf("->Fin increment 1 et A = 2\n\n");

  float prod_f2[3];

  g[0] = 9.8;
  g[1] = 1.22;
  g[2] = 9.33;

  for (size_t i = 0; i < 3; i+=2) {
    prod_f2[i] = 5*f[i] + g[i];
  }

  cblas_saxpy(3, 5, f, 2, g, 2);

  printf("Increment 2 et A = 5:\n");
  for (int i = 0; i < 3; i+=2) {
    if (g[i] != prod_f2[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f\n",g[i], prod_f2[i]);
    }
  }
  printf("->Fin increment 2 et A = 5\n\n");


  printf("\n--- Test axpy double : ---\n\n");
  double prod_2f1[3];
  double f2[3] = {3.723891, -7.22938, -21.92348};
  double g2[3] = {9.82937, -1.2212, 19.329383};

  for (size_t i = 0; i < 3; i++) {
    prod_2f1[i] = 28.4*f2[i] + g2[i];
  }

  cblas_daxpy(3, 28.4, f2, 1, g2, 1);

  printf("Vecteurs :\n f = {3.723891, -7.22938, -21.92348}\n g = {9.82937, -1.22O12, 19.329383}\n");
  printf("Increment 1 et A = 28.4 :\n");
  for (int i = 0; i < 3; i++) {
    if (g2[i] != prod_2f1[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f \n",g2[i], prod_2f1[i]);
    }
  }
  printf("->Fin increment 1 et A = 28.4\n\n");

  float prod_2f2[3];

  g2[0] = 9.82937;
  g2[1] = -1.2212;
  g2[2] = 19.329383;

  for (size_t i = 0; i < 3; i+=2) {
    prod_2f2[i] = 5.76*f2[i] + g2[i];
  }

  cblas_daxpy(3, 5.76, f2, 2, g2, 2);

  printf("Increment 2 et A = 5.76:\n");
  for (int i = 0; i < 3; i+=2) {
    if (g2[i] != prod_2f2[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f\n",g2[i], prod_2f2[i]);
    }
  }
  printf("->Fin increment 2 et A = 5.76\n\n");

  float prod_2f3[3];

  g2[0] = 9.82937;
  g2[1] = -1.2212;
  g2[2] = 19.329383;

  for (size_t i = 0; i < 3; i+=2) {
    prod_2f3[i] = 3.28*f2[i] + g2[i];
  }

  cblas_daxpy(3, 3.28, f2, 1, g2, 1);

  printf("Increment 1 et A = 3.28:\n");
  for (int i = 0; i < 3; i+=2) {
    if (g2[i] != prod_2f3[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f\n",g2[i], prod_2f2[i]);
    }
  }
  printf("->Fin increment 1 et A = 3.28\n\n");

  printf("\n--- Test axpy Complexe float : ---\n\n");
  complexe_float_t prod_3f1[3];
  complexe_float_t f3[3];
  complexe_float_t g3[3];

  complexe_float_t a[1];
  a[0].real = 3.7;
  a[0].imaginary = 0;

  for (size_t i = 0; i < 3; i++) {
    f3[i].real = i+4.89 + i/100;
    f3[i].imaginary = i -3.78 + i /100;
    g3[i].real = i+32.43 + i/100;
    g3[i].imaginary = i+22 + i/100;
  }

  for (size_t i = 0; i < 3; i++) {
    prod_3f1[i].real = 3.7*f3[i].real + g3[i].real;
    prod_3f1[i].imaginary = 3.7*f3[i].imaginary + g3[i].imaginary;
  }

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 2; i++) {
    printf("%f + i * %f, ", f3[i].real, f3[i].imaginary);
  }
  printf("%f + i * %f }\n\n g = {", f3[2].real, f3[2].imaginary);
  for (int i = 0; i < 2; i++) {
    printf("%f + i * %f, ", g3[i].real, g3[i].imaginary);
  }
  printf("%f + i * %f }\n\n", g3[2].real, g3[2].imaginary);

  cblas_caxpy(3, a, f3, 1, g3, 1);

  printf("Increment 1 et A = 3.7 :\n");
  for (int i = 0; i < 3; i++) {
    if (g3[i].real != prod_3f1[i].real || g3[i].imaginary != prod_3f1[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i* %f != %f + i* %f\n",g3[i].real, g3[i].imaginary, prod_3f1[i].real, prod_3f1[i].imaginary);
    }
  }
  printf("->Fin increment 1 et A = 3.7\n\n");

  complexe_float_t prod_3f2[3];
  complexe_float_t a2[1];
  a2[0].real = 2;
  a2[0].imaginary = 1;


  for (size_t i = 0; i < 3; i++) {
    g3[i].real = i+32.43 + i/100;
    g3[i].imaginary = i-22 + i/100;
  }

  for (size_t i = 0; i < 3; i+=2) {
    prod_3f2[i].real = 2*f3[i].real - f3[i].imaginary + g3[i].real;
    prod_3f2[i].imaginary = 2*f3[i].imaginary - f3[i].real + g3[i].imaginary;
  }

  cblas_caxpy(3, a2, f3, 2, g3, 2);

  printf("Increment 2 et A = 2 + i:\n");
  for (int i = 0; i < 3; i+=2) {
    if (g3[i].real != prod_3f2[i].real || g3[i].imaginary != prod_3f2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i* %f != %f + i* %f\n",g3[i].real, g3[i].imaginary, prod_3f2[i].real, prod_3f2[i].imaginary);
    }
  }
  printf("->Fin increment 2 et A = 2 + i\n\n");

  printf("\n--- Test axpy Complexe double : ---\n\n");
  complexe_float_t prod_4f1[3];
  complexe_float_t f4[3];
  complexe_float_t g4[3];

  complexe_float_t a4[1];
  a4[0].real = 1;
  a4[0].imaginary = 2;

  for (size_t i = 0; i < 3; i++) {
    f4[i].real = i+4.89328 + i/10000;
    f4[i].imaginary = i -3.78111 + i /10000;
    g4[i].real = i+32.43222 + i/10000;
    g4[i].imaginary = i+22.2 + i/10000;
  }

  for (size_t i = 0; i < 3; i++) {
    prod_4f1[i].real = f4[i].real - 2*f4[i].imaginary + g4[i].real;
    prod_4f1[i].imaginary = f4[i].imaginary - 2*f4[i].real + g4[i].imaginary;
  }

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 2; i++) {
    printf("%f + i * %f, ", f4[i].real, f4[i].imaginary);
  }
  printf("%f + i * %f }\n\n g = {", f4[2].real, f4[2].imaginary);
  for (int i = 0; i < 2; i++) {
    printf("%f + i * %f, ", g4[i].real, g4[i].imaginary);
  }
  printf("%f + i * %f }\n\n", g4[2].real, g4[2].imaginary);

  cblas_caxpy(3, a4, f4, 1, g4, 1);

  printf("Increment 1 et A = 1 + 2*i :\n");
  for (int i = 0; i < 3; i++) {
    if (g4[i].real != prod_4f1[i].real || g4[i].imaginary != prod_4f1[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i* %f != %f + i* %f\n",g4[i].real, g4[i].imaginary, prod_4f1[i].real, prod_4f1[i].imaginary);
    }
  }
  printf("->Fin increment 1 et A = 1 + 2*i\n\n");

  complexe_float_t prod_4f2[3];
  complexe_float_t a5[1];
  a5[0].real = -1;
  a5[0].imaginary = 0;


  for (size_t i = 0; i < 3; i++) {
    g4[i].real = i+32.43 + i/100;
    g4[i].imaginary = i-22 + i/100;
  }

  for (size_t i = 0; i < 3; i+=2) {
    prod_4f2[i].real = -1*f4[i].real + g3[i].real;
    prod_4f2[i].imaginary = -1*f4[i].imaginary + g3[i].imaginary;
  }

  cblas_caxpy(3, a5, f4, 2, g4, 2);

  printf("Increment 2 et A = -1:\n");
  for (int i = 0; i < 3; i+=2) {
    if (g4[i].real != prod_4f2[i].real || g4[i].imaginary != prod_4f2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i* %f != %f + i* %f\n",g4[i].real, g4[i].imaginary, prod_4f2[i].real, prod_4f2[i].imaginary);
    }
  }
  printf("Fin increment 2 et 1 = -1\n");

  exit (0) ;
}
