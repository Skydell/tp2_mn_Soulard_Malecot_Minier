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

  f[0] = 3.7;
  f[1] = 8.2;
  f[2] = -2.98;
  f[3] = 9.23;
  g[0] = 9;
  g[1] = 1.22;
  g[2] = 9.33;
  g[3] = 1.2;

  for (int i = 0; i < 4; i++) {
    cor_f_float[i] = f[i];
    cor_g_float[i] = g[i];
  }

  mncblas_sswap(4, f, 2, g, 2);

  printf("Index 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (g[i] != cor_f_float[i] || f[i] != cor_g_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n",g[i], cor_f_float[i], f[i], cor_g_float[i]);
    }
  }
  printf("->Fin index 2\n");


  float cor_ff_float[8];
  float cor_gg_float[8];
  float ff[8] = {-98, 8.21, -87.23, -5.38, 43.1, -89.1, 2.35, 6.71};
  float gg[8] = {-2.2, 87.23, -22.5, 90, 55, 34.22, -35.1, -97.3};

  for (int i = 0; i < 8; i++) {
    cor_gg_float[i] = gg[i];
    cor_ff_float[i] = ff[i];
  }

  mncblas_sswap(8, ff, 1, gg ,1);

  printf("Vecteurs :\n i = {-98, 8.21, -87.23, -5.38, 43.1, -89.1, 2.35, 6.71}\n j = {-2.2, 87.23, -22.5, 90, 55, 34.22, -35.1, -97.3}\n");
  printf("Index 1 :\n");
  for (int i = 0; i < 8; i++) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin index 1\n");

  ff[0] = -98;
  ff[1] = 8.21;
  ff[2] = -87.23;
  ff[3] = -5.38;
  ff[4] = 43.1;
  ff[5] = -89.1;
  ff[6] = 2.35;
  ff[7] = 6.71;
  gg[0] = -2.2;
  gg[1] = 87.23;
  gg[2] = -22.5;
  gg[3] = 90;
  gg[4] = 55;
  gg[5] = 34.22;
  gg[6] = -35.1;
  gg[7] = -97.3;

  for (int i = 0; i < 8; i++) {
    cor_gg_float[i] = gg[i];
    cor_ff_float[i] = ff[i];
  }

  mncblas_sswap(8, ff, 2, gg, 2);

  printf("Index 2 :\n");
  for (int i = 0; i < 8; i+=2) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin index 2\n");


  ff[0] = -98;
  ff[1] = 8.21;
  ff[2] = -87.23;
  ff[3] = -5.38;
  ff[4] = 43.1;
  ff[5] = -89.1;
  ff[6] = 2.35;
  ff[7] = 6.71;
  gg[0] = -2.2;
  gg[1] = 87.23;
  gg[2] = -22.5;
  gg[3] = 90;
  gg[4] = 55;
  gg[5] = 34.22;
  gg[6] = -35.1;
  gg[7] = -97.3;

  for (int i = 0; i < 8; i++) {
    cor_gg_float[i] = gg[i];
    cor_ff_float[i] = ff[i];
  }

  mncblas_sswap(8, ff, 3, gg, 3);

  printf("Index 3 :\n");
  for (int i = 0; i < 8; i+=3) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin index 3\n");

  ff[0] = -98;
  ff[1] = 8.21;
  ff[2] = -87.23;
  ff[3] = -5.38;
  ff[4] = 43.1;
  ff[5] = -89.1;
  ff[6] = 2.35;
  ff[7] = 6.71;
  gg[0] = -2.2;
  gg[1] = 87.23;
  gg[2] = -22.5;
  gg[3] = 90;
  gg[4] = 55;
  gg[5] = 34.22;
  gg[6] = -35.1;
  gg[7] = -97.3;

  for (int i = 0; i < 8; i++) {
    cor_gg_float[i] = gg[i];
    cor_ff_float[i] = ff[i];
  }

  mncblas_sswap(8, ff, 4, gg, 5);

  printf("Index i = 4, j = 5 :\n");
  for (int i = 0, j = 0; i < 8 && j < 8; i+=4, j+=5) {
    if (gg[j] != cor_ff_float[i] || ff[i] != cor_gg_float[j]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[j], cor_ff_float[i], ff[i], cor_gg_float[j]);
    }
  }
  printf("->Fin index i = 4, j = 5\n");

  printf("\n--- Test asum double : ---\n");

  double cor_f1_double[3];
  double cor_g1_double[3];
  double f1[3] = {3.34005, 2.01005, -4.302900};
  double g1[3] = {-6.22284, -5.09382, 22.3452};

  for (int i = 0; i < 3; i++) {
    cor_f1_double[i] = f1[i];
    cor_g1_double[i] = g1[i];
  }

  mncblas_dswap(3, f1, 1, g1, 1);

  printf("Vecteurs :\n f = {3.34005, 2.01005, -4.302900}\n g = {-6.22284, -5.09382, 22.3452}\n");
  printf("Index 1 :\n");
  for (int i = 0; i < 3; i++) {
    if (g1[i] != cor_f1_double[i] || f1[i] != cor_g1_double[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", g1[i], cor_f1_double[i], f1[i], cor_g1_double[i]);
    }
  }
  printf("->Fin index 1\n");

  exit (0) ;
}
