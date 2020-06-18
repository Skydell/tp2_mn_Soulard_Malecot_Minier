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
  printf("Increment 1 :\n");
  for (int i = 0; i < 4; i++) {
    if (g[i] != cor_f_float[i] || f[i] != cor_g_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n",g[i], cor_f_float[i], f[i], cor_g_float[i]);
    }
  }
  printf("->Fin increment 1\n");

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

  printf("Increment 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (g[i] != cor_f_float[i] || f[i] != cor_g_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n",g[i], cor_f_float[i], f[i], cor_g_float[i]);
    }
  }
  printf("->Fin increment 2\n");


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
  printf("Increment 1 :\n");
  for (int i = 0; i < 8; i++) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin Increment 1\n");

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

  printf("Increment 2 :\n");
  for (int i = 0; i < 8; i+=2) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin increment 2\n");


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

  printf("Increment 3 :\n");
  for (int i = 0; i < 8; i+=3) {
    if (gg[i] != cor_ff_float[i] || ff[i] != cor_gg_float[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[i], cor_ff_float[i], ff[i], cor_gg_float[i]);
    }
  }
  printf("->Fin increment 3\n");

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

  printf("Increment i = 4, j = 5 :\n");
  for (int i = 0, j = 0; i < 8 && j < 8; i+=4, j+=5) {
    if (gg[j] != cor_ff_float[i] || ff[i] != cor_gg_float[j]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg[j], cor_ff_float[i], ff[i], cor_gg_float[j]);
    }
  }
  printf("->Fin increment i = 4, j = 5\n");

  printf("\n--- Test swap double : ---\n\n");

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
  printf("Increment 1 :\n");
  for (int i = 0; i < 3; i++) {
    if (g1[i] != cor_f1_double[i] || f1[i] != cor_g1_double[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", g1[i], cor_f1_double[i], f1[i], cor_g1_double[i]);
    }
  }
  printf("->Fin increment 1\n");

  f1[0] = 3.34005;
  f1[1] = 2.01005;
  f1[2] = -4.302900;
  g1[0] = -6.22284;
  g1[1] = -5.09382;
  g1[2] = 22.3452;

  for (int i = 0; i < 3; i++) {
    cor_f1_double[i] = f1[i];
    cor_g1_double[i] = g1[i];
  }

  mncblas_dswap(3, f1, 2, g1, 2);

  printf("Increment 2 :\n");
  for (int i = 0; i < 3; i+=2) {
    if (g1[i] != cor_f1_double[i] || f1[i] != cor_g1_double[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", g1[i], cor_f1_double[i], f1[i], cor_g1_double[i]);
    }
  }
  printf("->Fin increment 2\n");

  double cor_ff1_double[4];
  double cor_gg1_double[4];
  double ff1[4] = {-9.1234, 3.34005, 2.01005, -4.302900};
  double gg1[4] = {-87.2345,-6.22284, -5.09382, 22.3452};

  for (int i = 0; i < 4; i++) {
    cor_ff1_double[i] = ff1[i];
    cor_gg1_double[i] = gg1[i];
  }

  mncblas_dswap(4, ff1, 2, gg1, 2);

  printf("Vecteurs :\n f = {-9.1234, 3.34005, 2.01005, -4.302900}\n g = {-87.2345,-6.22284, -5.09382, 22.3452}\n");
  printf("Increment 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (gg1[i] != cor_ff1_double[i] || ff1[i] != cor_gg1_double[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg1[i], cor_ff1_double[i], ff1[i], cor_gg1_double[i]);
    }
  }
  printf("->Fin increment 2\n");

  ff1[0] = -9.1234;
  ff1[1] = 3.34005;
  ff1[2] = 2.01005;
  ff1[3] = -4.302900;
  gg1[0] = -87.2345;
  gg1[1] = -6.22284;
  gg1[2] = -5.09382;
  gg1[3] = 22.3452;

  for (int i = 0; i < 4; i++) {
    cor_ff1_double[i] = ff1[i];
    cor_gg1_double[i] = gg1[i];
  }

  mncblas_dswap(4, ff1, 3, gg1, 3);

  printf("Increment 3 :\n");
  for (int i = 0; i < 3; i+=3) {
    if (gg1[i] != cor_ff1_double[i] || ff1[i] != cor_gg1_double[i]){
      printf("Error index : %i\n", i);
      printf("%f != %f || %f != %f\n", gg1[i], cor_ff1_double[i], ff1[i], cor_gg1_double[i]);
    }
  }
  printf("->Fin increment 3\n");

  printf("\n--- Test swap Complexe float : ---\n\n");


  complexe_float_t cg1[10];
  complexe_float_t cf1[10];
  for (int i = 0; i < 10; i++) {
    cf1[i].real = i+4 + ((float)i/10);
    cf1[i].imaginary = i+2 + ((float)i/1000);
    cg1[i].real = i+9.2;
    cg1[i].imaginary = i-3.23+ ((float)i/10);
  }
  complexe_float_t cor_cf1[10];
  complexe_float_t cor_cg1[10];
  for (int i = 0; i < 10; i++) {
    cor_cf1[i].real = cf1[i].real;
    cor_cf1[i].imaginary = cf1[i].imaginary;
    cor_cg1[i].real = cg1[i].real;
    cor_cg1[i].imaginary = cg1[i].imaginary;
  }

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 9; i++) {
    printf("%f + i * %f, ", cf1[i].real, cf1[i].imaginary);
  }
  printf("%f + i * %f }\n\n g = {", cf1[9].real, cf1[9].imaginary);
  for (int i = 0; i < 9; i++) {
    printf("%f + i * %f, ", cg1[i].real, cg1[i].imaginary);
  }
  printf("%f + i * %f }\n\n", cg1[9].real, cg1[9].imaginary);

  mncblas_cswap(10, cf1, 1, cg1, 1);

  printf("Increment 1 :\n");
  for (int i = 0; i < 10; i+=1) {
    if (cg1[i].real != cor_cf1[i].real || cg1[i].imaginary != cor_cf1[i].imaginary || cf1[i].real != cor_cg1[i].real || cf1[i].imaginary != cor_cg1[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg1[i].real, cg1[i].imaginary, cor_cf1[i].real, cor_cf1[i].imaginary, cf1[i].real, cf1[i].imaginary, cor_cg1[i].real, cor_cg1[i].imaginary);
    }
  }
  printf("->Fin increment 1\n\n");

  for (int i = 0; i < 10; i++) {
    cf1[i].real = i+4 + ((float)i/10);
    cf1[i].imaginary = i+2 + ((float)i/1000);
    cg1[i].real = i+9.2;
    cg1[i].imaginary = i-3.23+ ((float)i/10);
  }

  mncblas_cswap(10, cf1, 2, cg1, 2);

  printf("Increment 2 :\n");
  for (int i = 0; i < 10; i+=2) {
    if (cg1[i].real != cor_cf1[i].real || cg1[i].imaginary != cor_cf1[i].imaginary || cf1[i].real != cor_cg1[i].real || cf1[i].imaginary != cor_cg1[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg1[i].real, cg1[i].imaginary, cor_cf1[i].real, cor_cf1[i].imaginary, cf1[i].real, cf1[i].imaginary, cor_cg1[i].real, cor_cg1[i].imaginary);
    }
  }
  printf("->Fin increment 2\n\n");

  for (int i = 0; i < 10; i++) {
    cf1[i].real = i+4 + ((float)i/10);
    cf1[i].imaginary = i+2 + ((float)i/1000);
    cg1[i].real = i+9.2;
    cg1[i].imaginary = i-3.23+ ((float)i/10);
  }

  mncblas_cswap(10, cf1, 3, cg1, 3);

  printf("Increment 3 :\n");
  for (int i = 0; i < 10; i+=3) {
    if (cg1[i].real != cor_cf1[i].real || cg1[i].imaginary != cor_cf1[i].imaginary || cf1[i].real != cor_cg1[i].real || cf1[i].imaginary != cor_cg1[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg1[i].real, cg1[i].imaginary, cor_cf1[i].real, cor_cf1[i].imaginary, cf1[i].real, cf1[i].imaginary, cor_cg1[i].real, cor_cg1[i].imaginary);
    }
  }
  printf("->Fin increment 3\n\n");

  for (int i = 0; i < 10; i++) {
    cf1[i].real = i+4 + ((float)i/10);
    cf1[i].imaginary = i+2 + ((float)i/1000);
    cg1[i].real = i+9.2;
    cg1[i].imaginary = i-3.23+ ((float)i/10);
  }

  mncblas_cswap(10, cf1, 6, cg1, 7);

  printf("Increment i = 6, j = 7 :\n");
  for (int i = 0, j = 0; i < 10 && j < 10; i+=6, j+=7)  {
    if (cg1[j].real != cor_cf1[i].real || cg1[j].imaginary != cor_cf1[i].imaginary || cf1[i].real != cor_cg1[j].real || cf1[i].imaginary != cor_cg1[j].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg1[j].real, cg1[j].imaginary, cor_cf1[i].real, cor_cf1[i].imaginary, cf1[i].real, cf1[i].imaginary, cor_cg1[j].real, cor_cg1[j].imaginary);
    }
  }
  printf("->Fin increment i = 6, j = 7\n\n");

  printf("\n--- Test swap Complexe double : ---\n\n");

  complexe_float_t cg2[10];
  complexe_float_t cf2[10];
  for (int i = 0; i < 10; i++) {
    cf2[i].real = i+4 + ((float)i/10000);
    cf2[i].imaginary = i+2 + ((float)i/1000000);
    cg2[i].real = i+9.2;
    cg2[i].imaginary = i-3.23+ ((float)i/100000);
  }
  complexe_float_t cor_cf2[10];
  complexe_float_t cor_cg2[10];
  for (int i = 0; i < 10; i++) {
    cor_cf2[i].real = cf2[i].real;
    cor_cf2[i].imaginary = cf2[i].imaginary;
    cor_cg2[i].real = cg2[i].real;
    cor_cg2[i].imaginary = cg2[i].imaginary;
  }

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 9; i++) {
    printf("%f + i * %f, ", cf2[i].real, cf2[i].imaginary);
  }
  printf("%f + i * %f }\n\n g = {", cf2[9].real, cf2[9].imaginary);
  for (int i = 0; i < 9; i++) {
    printf("%f + i * %f, ", cg2[i].real, cg2[i].imaginary);
  }
  printf("%f + i * %f }\n\n", cg2[9].real, cg2[9].imaginary);

  mncblas_cswap(10, cf2, 1, cg2, 1);

  printf("Increment 1 :\n");
  for (int i = 0; i < 10; i+=1) {
    if (cg2[i].real != cor_cf2[i].real || cg2[i].imaginary != cor_cf2[i].imaginary || cf2[i].real != cor_cg2[i].real || cf2[i].imaginary != cor_cg2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg2[i].real, cg2[i].imaginary, cor_cf2[i].real, cor_cf2[i].imaginary, cf2[i].real, cf2[i].imaginary, cor_cg2[i].real, cor_cg2[i].imaginary);
    }
  }
  printf("->Fin increment 1\n\n");

  for (int i = 0; i < 10; i++) {
    cf2[i].real = i+4 + ((float)i/10000);
    cf2[i].imaginary = i+2 + ((float)i/1000000);
    cg2[i].real = i+9.2;
    cg2[i].imaginary = i-3.23+ ((float)i/100000);
  }

  mncblas_cswap(10, cf2, 2, cg2, 2);

  printf("Increment 2 :\n");
  for (int i = 0; i < 10; i+=2) {
    if (cg2[i].real != cor_cf2[i].real || cg2[i].imaginary != cor_cf2[i].imaginary || cf2[i].real != cor_cg2[i].real || cf2[i].imaginary != cor_cg2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg2[i].real, cg2[i].imaginary, cor_cf2[i].real, cor_cf2[i].imaginary, cf2[i].real, cf2[i].imaginary, cor_cg2[i].real, cor_cg2[i].imaginary);
    }
  }
  printf("->Fin increment 2\n\n");

  for (int i = 0; i < 10; i++) {
    cf2[i].real = i+4 + ((float)i/10000);
    cf2[i].imaginary = i+2 + ((float)i/1000000);
    cg2[i].real = i+9.2;
    cg2[i].imaginary = i-3.23+ ((float)i/100000);
  }

  mncblas_cswap(10, cf2, 3, cg2, 3);

  printf("Increment 3 :\n");
  for (int i = 0; i < 10; i+=3) {
    if (cg2[i].real != cor_cf2[i].real || cg2[i].imaginary != cor_cf2[i].imaginary || cf2[i].real != cor_cg2[i].real || cf2[i].imaginary != cor_cg2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg2[i].real, cg2[i].imaginary, cor_cf2[i].real, cor_cf2[i].imaginary, cf2[i].real, cf2[i].imaginary, cor_cg2[i].real, cor_cg2[i].imaginary);
    }
  }
  printf("->Fin increment 3\n\n");

  for (int i = 0; i < 10; i++) {
    cf2[i].real = i+4 + ((float)i/10000);
    cf2[i].imaginary = i+2 + ((float)i/1000000);
    cg2[i].real = i+9.2;
    cg2[i].imaginary = i-3.23+ ((float)i/100000);
  }

  mncblas_cswap(10, cf2, 6, cg2, 7);

  printf("Increment i = 6, j = 7 :\n");
  for (int i = 0, j = 0; i < 10 && j < 10; i+=6, j+=7)  {
    if (cg2[j].real != cor_cf2[i].real || cg2[j].imaginary != cor_cf2[i].imaginary || cf2[i].real != cor_cg2[j].real || cf2[j].imaginary != cor_cg2[i].imaginary){
      printf("Error index : %i\n", i);
      printf("%f + i * %f != %f + i * %f || %f + i * %f != %f + i * %f\n", cg2[j].real, cg2[j].imaginary, cor_cf2[i].real, cor_cf2[i].imaginary, cf2[i].real, cf2[i].imaginary, cor_cg2[j].real, cor_cg2[j].imaginary);
    }
  }
  printf("->Fin increment i = 6, j = 7\n\n");

  exit (0) ;
}
