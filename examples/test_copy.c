#include <stdio.h>
#include <x86intrin.h>

#include "../src/asum.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test copy float : ---\n\n");

  float copy_float1[10];
  float f[10] = {2.48, 7.7, 3.21, 34.2, 9.4, -2.2, -6, 31, -2.98, 9.23};

  mncblas_scopy(10, f, 1, copy_float1, 1);

  printf("Vecteurs :\n f = {2.48, 7.7, 3.21, 34.2, 9.4, -2.2, -6, 31, -2.98, 9.23}\n\n");
  printf("Increment 1 :\n");
  for (int i = 0; i < 10; i++) {
    if (f[i] != copy_float1[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f[i], copy_float1[i]);
    }
  }
  printf("->Fin increment 1\n\n");

  float  copy_float1_2[10];

  mncblas_scopy(10, f, 2, copy_float1_2, 2);

  printf("Increment 2:\n");
  for (int i = 0; i < 10; i+=2) {
    if (f[i] != copy_float1_2[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f[i], copy_float1_2[i]);
    }
  }
  printf("->Fin increment 2\n\n");


  float  copy_float2[5];

  mncblas_scopy(10, f, 2, copy_float2, 1);

  printf("Increment i = 2, j = 1 :\n");
  for (int i = 0, j = 0; i < 10 && j < 5; i+=2, j ++) {
    if (f[i] != copy_float2[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i , j);
      printf("%f != %f \n", f[i], copy_float2[j]);
    }
  }
  printf("->Fin increment i = 2, j = 1\n\n");

  float copy_float3[20];

  mncblas_scopy(20, f, 3, copy_float3, 5);

  printf("Increment i = 3, j = 5 :\n");
  for (int i = 0, j = 0; i < 10 && j < 20; i+=3, j +=5) {
    if (f[i] != copy_float3[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, j);
      printf("%f != %f \n", f[i], copy_float3[j]);
    }
  }
  printf("->Fin increment i = 3, j = 5\n\n");

  printf("\n--- Test copy double : ---\n\n");

  double copy_double1[8];
  double f2[8] = {2.48392, 7.129837, 3.299221, 34.121342, -6.29830, 31.32010, -2.98192, 9.23122};

  mncblas_dcopy(8, f2, 1, copy_double1, 1);

  printf("Vecteurs :\n f = {2.48392, 7.129837, 3.299221, 34.121342, -6.29830, 31.32010, -2.98192, 9.23122}\n\n");
  printf("Increment 1 :\n");
  for (int i = 0; i < 8; i++) {
    if (f2[i] != copy_double1[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f2[i], copy_double1[i]);
    }
  }
  printf("->Fin increment 1\n\n");

  double  copy_double1_2[8];

  mncblas_dcopy(8, f2, 2, copy_double1_2, 2);

  printf("Increment 2:\n");
  for (int i = 0; i < 8; i+=2) {
    if (f2[i] != copy_double1_2[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f2[i], copy_double1_2[i]);
    }
  }
  printf("->Fin increment 2\n\n");

  double copy_double1_3[8];

  mncblas_dcopy(8, f2, 3, copy_double1_3, 3);

  printf("Increment 3:\n");
  for (int i = 0; i < 8; i+=3) {
    if (f2[i] != copy_double1_3[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f2[i], copy_double1_3[i]);
    }
  }
  printf("->Fin increment 3\n\n");

  double copy_double2[4];

  mncblas_dcopy(8, f2, 2, copy_double2, 1);

  printf("Increment i = 2, j = 1 :\n");
  for (int i = 0, j = 0; i < 8 && j < 4; i+=2, j ++) {
    if (f2[i] != copy_double2[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i , j);
      printf("%f != %f \n", f2[i], copy_double2[j]);
    }
  }
  printf("->Fin increment i = 2, j = 1\n\n");

  double copy_double3[16];

  mncblas_dcopy(16, f2, 3, copy_double3, 6);

  printf("Increment i = 3, j = 6 :\n");
  for (int i = 0, j = 0; i < 8 && j < 16; i+=3, j +=6) {
    if (f2[i] != copy_double3[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, j);
      printf("%f != %f \n", f2[i], copy_double3[j]);
    }
  }
  printf("->Fin increment i = 3, j = 6\n\n");

  printf("\n--- Test copy Complexe float : ---\n\n");

  complexe_float_t cf1[4];
  for (int i = 0; i < 4; i++) {
    cf1[i].real = i+12.4 + ((float)i/10);
    cf1[i].imaginary = i-2 + ((float)i/100);
  }
  complexe_float_t copy_cf1[4];

  mncblas_ccopy(4, cf1, 1, copy_cf1, 1);

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 3; i++) {
    printf("%f + i * %f, ", cf1[i].real, cf1[i].imaginary);
  }
  printf("%f + i * %f }\n\n", cf1[3].real, cf1[3].imaginary);

  printf("Increment 1 :\n");
  for (int i = 0; i < 4; i++) {
    if (cf1[i].real != copy_cf1[i].real || cf1[i].imaginary != copy_cf1[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cf1[i].real, cf1[i].imaginary, copy_cf1[i].real, copy_cf1[i].imaginary);
    }
  }
  printf("->Fin increment 1\n\n");

  complexe_float_t copy_cf2[4];

  mncblas_ccopy(4, cf1, 2, copy_cf2, 2);

  printf("Increment 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (cf1[i].real != copy_cf2[i].real || cf1[i].imaginary != copy_cf2[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cf1[i].real, cf1[i].imaginary, copy_cf2[i].real, copy_cf2[i].imaginary);
    }
  }
  printf("->Fin increment 2\n\n");

  complexe_float_t copy_cf3[4];

  mncblas_ccopy(4, cf1, 3, copy_cf3, 3);

  printf("Increment 3 :\n");
  for (int i = 0; i < 4; i+=3) {
    if (cf1[i].real != copy_cf3[i].real || cf1[i].imaginary != copy_cf3[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cf1[i].real, cf1[i].imaginary, copy_cf3[i].real, copy_cf3[i].imaginary);
    }
  }
  printf("->Fin increment 3\n\n");

  complexe_float_t copy_cf4[4];

  mncblas_ccopy(4, cf1, 2, copy_cf4, 3);

  printf("Increment i = 2, j = 3 :\n");
  for (int i = 0, j = 0; i < 4 && j < 4; i+=2, j +=3) {
    if (cf1[i].real != copy_cf4[j].real || cf1[i].imaginary != copy_cf4[j].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cf1[i].real, cf1[i].imaginary, copy_cf4[j].real, copy_cf4[j].imaginary);
    }
  }
  printf("->Fin increment i = 2, j = 3\n\n");


  printf("\n--- Test copy Complexe double : ---\n\n");

  complexe_double_t cd[4];
  for (int i = 0; i < 4; i++) {
    cd[i].real = i+8.4123 + ((float)i/10000);
    cd[i].imaginary = i-2.39482 + ((float)i/100000);
  }
  complexe_double_t copy_cd1[4];

  mncblas_zcopy(4, cd, 1, copy_cd1, 1);

  printf("Vecteurs :\n");
  printf(" f = { ");
  for (int i = 0; i < 3; i++) {
    printf("%f + i * %f, ", cd[i].real, cd[i].imaginary);
  }
  printf("%f + i * %f }\n\n", cd[3].real, cd[3].imaginary);

  printf("Increment 1 :\n");
  for (int i = 0; i < 4; i++) {
    if (cd[i].real != copy_cd1[i].real || cd[i].imaginary != copy_cd1[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cd[i].real, cd[i].imaginary, copy_cd1[i].real, copy_cd1[i].imaginary);
    }
  }
  printf("->Fin increment 1\n\n");

  complexe_double_t copy_cd2[4];

  mncblas_zcopy(4, cd, 2, copy_cd2, 2);

  printf("Increment 2 :\n");
  for (int i = 0; i < 4; i+=2) {
    if (cd[i].real != copy_cd2[i].real || cd[i].imaginary != copy_cd2[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cd[i].real, cd[i].imaginary, copy_cd2[i].real, copy_cd2[i].imaginary);
    }
  }
  printf("->Fin increment 2\n\n");

  complexe_double_t copy_cd3[4];

  mncblas_zcopy(4, cd, 3, copy_cd3, 3);

  printf("Increment 3 :\n");
  for (int i = 0; i < 4; i+=3) {
    if (cd[i].real != copy_cd3[i].real || cd[i].imaginary != copy_cd3[i].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cd[i].real, cd[i].imaginary, copy_cd3[i].real, copy_cd3[i].imaginary);
    }
  }
  printf("->Fin increment 3\n\n");

  complexe_double_t copy_cd4[4];

  mncblas_zcopy(4, cd, 2, copy_cd4, 3);

  printf("Increment i = 2, j = 3 :\n");
  for (int i = 0, j = 0; i < 4 && j < 4; i+=2, j +=3) {
    if (cd[i].real != copy_cd4[j].real || cd[i].imaginary != copy_cd4[j].imaginary){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f + i * %f != %f + i * %f \n", cd[i].real, cd[i].imaginary, copy_cd4[j].real, copy_cd4[j].imaginary);
    }
  }
  printf("->Fin increment i = 2, j = 3\n\n");

  exit (0) ;
}
