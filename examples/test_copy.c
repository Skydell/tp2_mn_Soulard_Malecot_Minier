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

  printf("Vecteurs :\n f = {2.48, 7.7, 3.21, 34.2, 9.4, -2.2, -6, 31, -2.98, 9.23}\n");
  printf("Increment 1 :\n");
  for (int i = 0; i < 10; i++) {
    if (f[i] != copy_float1[i]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, i);
      printf("%f != %f \n", f[i], copy_float1[i]);
    }
  }
  printf("->Fin increment 1\n");

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
  printf("->Fin increment 2\n");


  float  copy_float2[5];

  mncblas_scopy(5, f, 2, copy_float2, 1);

  printf("Increment i = 2, j = 1 :\n");
  for (int i = 0, j = 0; i < 10 && j < 5; i+=2, j ++) {
    if (f[i] != copy_float2[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i , j);
      printf("%f != %f \n", f[i], copy_float2[j]);
    }
  }
  printf("->Fin increment i = 2, j = 1\n");

  float copy_float3[20];

  mncblas_scopy(4, f, 3, copy_float3, 5);

  printf("Increment i = 3, j = 5 :\n");
  for (int i = 0, j = 0; i < 10 && j < 20; i+=3, j +=5) {
    if (f[i] != copy_float3[j]){
      printf("Error index :\n");
      printf("f[ %i ]  |  copy_f[ %i ]\n", i, j);
      printf("%f != %f \n", f[i], copy_float3[j]);
    }
  }
  printf("->Fin increment i = 3, j = 5\n");


  exit (0) ;
}
