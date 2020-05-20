#include <stdio.h>
#include <x86intrin.h>

#include "../src/asum.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test asum entier : ---\n");
  float f[4] = {1.2, 2.33, -3.44, 39.21};
  float res1 = cblas_sasum(4, f, 1);
  double res2 = cblas_sasum(4, f, 2);
  printf("%f\n", res1);
  printf("%f\n", res2);

  exit (0) ;
}
