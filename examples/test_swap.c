#include <stdio.h>
#include <x86intrin.h>

#include "../src/asum.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test swap float : ---\n\n");

  float cor_f_float[4];
  float cor_g_float[4];
  float f[4] = {3.7, 8.2, -2.98, 9.23};
  float g[4] = {9, 1.22, 9.33, 1.2};

  for (int i = 0; i < 4; i++) {
    cor_f_float[i] = f[i];
    cor_g_float[i] = g[i];
  }

  mncblas_sswap(4, f, 1, g ,1);

  printf("Vecteurs :\n f = {3.7, 8.2, -2.98, 9.23}\n g = {9, 1.22, 9.33, 1.2}\n");
  printf("Index 1 :\n");
  for (int i = 0; i < 4; i++) {
    if (g[i] != cor_f_float[i] || f[i] != cor_g_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n",g[i], cor_f_float[i], f[i], cor_g_float[i]);
    }
  }
  printf("->Fin index 1\n");

  mncblas_sswap(4, f, 2, g, 2);

  printf("Index 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (g[i] != cor_f_float[i] || f[i] != cor_g_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n",g[i], cor_f_float[i], f[i], cor_g_float[i]);
    }
  }
  printf("->Fin index 2\n");


/*
  float cor_k_float[8];
  float cor_j_float[8];
  float k[8] = {-98, 8.21, -87.23, -5.38, 43.1, -89.1, 2.35, 6.71};
  float j[8] = {-2.2, 87.23, -22.5, 90, 55, 34.22, -35.1, -97.3};

  for (int i = 0; i < 8; i++) {
    cor_k_float[i] = k[i];
    cor_j_float[i] = j[i];
  }

  mncblas_sswap(8, k, 1, j ,1);

  printf("Vecteurs :\n i = {-98, 8.21, -87.23, -5.38, 43.1, -89.1, 2.35, 6.71}\n j = {-2.2, 87.23, -22.5, 90, 55, 34.22, -35.1, -97.3}\n");
  printf("Index 1 :\n");
  for (int i = 0; i < 8; i++) {
    if (j[i] != cor_k_float[i] || k[i] != cor_j_float[i]){
      printf("Error index : %i\n", i);
    }
  }
  printf("->Fin index 1\n");

  mncblas_sswap(8, k, 2, j, 2);

  printf("Index 2 :\n");
    if (j[i] != cor_k_float[i] || k[i] != cor_j_float[i]){
      printf("Error index : %i\n", i);
    }
  }
  printf("->Fin index 2\n");

  mncblas_sswap(8, k, 3, j, 3);

  printf("Index 3 :\n");
  for (int i = 0; i < 8; i+=3) {
    if (j[i] != cor_k_float[i] || k[i] != cor_j_float[i]){
      printf("Error index : %i\n", i);
    }
  }
  printf("->Fin index 3\n");

  mncblas_sswap(8, k, 3, j, 3);

  printf("Index 3 :\n");
  for (int i = 0; i < 8; i+=3) {
    if (j[i] != cor_k_float[i] || k[i] != cor_j_float[i]){
      printf("Error index : %i\n", i);
    }
  }
  printf("->Fin index 3\n");

  mncblas_sswap(8, k, 4, j, 5);

  printf("Index i = 4, j = 5 :\n");
  for (int i = 0, j = 0; i < 8 && j < 8; i+=4, j+=5) {
    if (j[i] != cor_k_float[i] || k[i] != cor_j_float[i]){
      printf("Error index : %i\n", i);
    }
  }
  printf("->Fin index i = 4, j = 5\n");

  printf("End of test float\n");

  exit (0) ;
*/
}
