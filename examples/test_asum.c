#include <stdio.h>
#include <x86intrin.h>

#include "../src/asum.c"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
  printf("\n--- Test asum float : ---\n");

  float cor_res1_float = 0;
  float cor_res2_float = 0;
  float f[4] = {1.2, 2.33, -3.44, 39.21};

  for (int i = 0; i < 4; i++) {
    if (f[i]>=0) {
      if (i%2 == 0){
        cor_res2_float += f[i];
      }
      cor_res1_float += f[i];
    } else {
      if (i%2 == 0) {
        cor_res2_float += -f[i];
      }
      cor_res1_float += -f[i];
    }
  }

  float res1_float= cblas_sasum(4, f, 1);
  float res2_float= cblas_sasum(4, f, 2);

  printf("Test vecteur {1.2, 2.33, -3.44, 39.21} :\n");
  if (res1_float< cor_res1_float-0.01 || res1_float> cor_res1_float+0.01){
    printf("Test failed for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res2_float< cor_res2_float-0.01 || res2_float> cor_res2_float + 0.01){
    printf("Test failed for index 2\n\n");
  } else {
    printf("Test index 2 Success\n\n");
  }


  float cor_res3_float = 0;
  float cor_res4_float = 0;
  float cor_res5_float = 0;
  float f2[6] = {3.43, 30.42, 2, 5.1, 4.4, 7.2};
  for (int j = 0; j < 6; j++) {
    if (f2[j]>=0) {
      if (j%2 == 0){
        cor_res4_float += f2[j];
      }
      if (j%3 == 0){
        cor_res5_float += f2[j];
      }
      cor_res3_float += f2[j];
    } else {
      if (j%2 == 0) {
        cor_res4_float += -f2[j];
      }
      if (j%3 == 0) {
        cor_res5_float += -f2[j];
      }
      cor_res3_float += -f2[j];
    }
  }

  float res3_float= cblas_sasum(6, f2, 1);
  float res4_float= cblas_sasum(6, f2, 2);
  float res5_float= cblas_sasum(6, f2, 3);

  printf("Test vecteur {3.43, 30.42, 2, 5.1, 4.4, 7.2} :\n");
  if (res3_float< cor_res3_float-0.01 || res3_float> cor_res3_float+0.01){
    printf("Test failes for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res4_float< cor_res4_float-0.01 || res4_float> cor_res4_float+0.01){
    printf("Test failed for index 2\n");
  } else {
    printf("Test index 2 Success\n");
  }
  if (res5_float< cor_res5_float-0.01 || res5_float> cor_res5_float+0.01){
    printf("Test failed for index 3\n\n");
  } else {
    printf("Test index 3 Success\n\n");
  }

  printf("\n--- Test asum double : ---\n");

  double cor_res1_double = 0;
  double cor_res2_double = 0;
  double d[3] = {3.34005, 2.01005, -4.302900};

  for (int i = 0; i < 3; i++) {
    if (d[i]>= 0){
      if (i%2 == 0){
        cor_res2_double += d[i];
      }
      cor_res1_double += d[i];
    } else {
      if (i%2 == 0){
        cor_res2_double += -d[i];
      }
      cor_res1_double += -d[i];
    }
  }

  double res1_double= cblas_dasum(3, d, 1);
  double res2_double= cblas_dasum(3, d, 2);

  printf("Test vecteur {3.34005, 2.01005, -4.302900} :\n");
  if (res1_double< cor_res1_double-0.01 || res1_double> cor_res1_double+0.01){
    printf("Test failed for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res2_double< cor_res2_double-0.01 || res2_double> cor_res2_double + 0.01){
    printf("Test failed for index 2\n\n");
  } else {
    printf("Test index 2 Success\n\n");
  }

  double cor_res3_double = 0;
  double cor_res4_double = 0;
  double cor_res5_double = 0;
  double d2[7] = {3.67845, 8.31205, 4.112900, 6.2930, 7.999, 8.293, 7.0908};

  for (int i = 0; i < 7; i++) {
    if (d2[i]>= 0){
      if (i%2 == 0){
        cor_res4_double += d2[i];
      }
      if (i%3 == 0){
        cor_res5_double += d2[i];
      }
      cor_res3_double += d2[i];
    } else {
      if (i%2 == 0){
        cor_res4_double += -d2[i];
      }
      if (i%3 == 0){
        cor_res5_double += -d2[i];
      }
      cor_res3_double += -d2[i];
    }
  }

  double res3_double= cblas_dasum(7, d2, 1);
  double res4_double= cblas_dasum(7, d2, 2);
  double res5_double= cblas_dasum(7, d2, 3);

  printf("Test vecteur {3.67845, 8.31205, 4.112900, 6.2930, 7.999, 8.293, 7.0908} :\n");
  if (res3_double< cor_res3_double-0.01 || res1_double> cor_res3_double+0.01){
    printf("Test failed for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res4_double< cor_res4_double-0.01 || res4_double> cor_res4_double + 0.01){
    printf("Test failed for index 2\n");
  } else {
    printf("Test index 2 Success\n");
  }
  if (res5_double< cor_res5_double-0.01 || res5_double> cor_res5_double+0.01){
    printf("Test failed for index 3\n\n");
  } else {
    printf("Test index 3 Success\n\n");
  }



  printf("\n--- Test asum Complexe float: ---\n");

  double cor_res1_Cfloat = 0;
  double cor_res2_Cfloat = 0;
  double cor_res3_Cfloat = 0;
  double cor_res4_Cfloat = 0;
  double cor_res5_Cfloat = 0;
  complexe_float_t cf[10];
  for (int i = 0; i < 10; i++) {
    if (i == 5){
      cf[i].real = -(i+4 + ((float)i/10));
      cf[i].imaginary = -(i+2 + ((float)i/1000));
    } else {
      cf[i].real = i+4 + ((float)i/10);
      cf[i].imaginary = i+2 + ((float)i/1000);
    }
  }

  for (int i = 0; i < 10; i++) {
    if (cf[i].real >= 0 && cf[i].imaginary >= 0){
      if (i%2 == 0){
        cor_res2_Cfloat += cf[i].real + cf[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cfloat += cf[i].real + cf[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cfloat += cf[i].real + cf[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cfloat += cf[i].real + cf[i].imaginary;
      }
      cor_res1_Cfloat += cf[i].real + cf[i].imaginary;
    } else if (cf[i].real < 0 && cf[i].imaginary < 0) {
      if (i%2 == 0){
        cor_res2_Cfloat += -cf[i].real - cf[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cfloat += -cf[i].real - cf[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cfloat += -cf[i].real - cf[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cfloat += -cf[i].real - cf[i].imaginary;
      }
      cor_res1_Cfloat += -cf[i].real - cf[i].imaginary;
    } else if (cf[i].real >=0 && cf[i].imaginary < 0){
      if (i%2 == 0){
        cor_res2_Cfloat += cf[i].real - cf[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cfloat += cf[i].real - cf[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cfloat += cf[i].real - cf[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cfloat += cf[i].real - cf[i].imaginary;
      }
      cor_res1_Cfloat += cf[i].real - cf[i].imaginary;
    } else {
      if (i%2 == 0){
        cor_res2_Cfloat += -cf[i].real + cf[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cfloat += -cf[i].real + cf[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cfloat += -cf[i].real + cf[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cfloat += -cf[i].real + cf[i].imaginary;
      }
      cor_res1_Cfloat += -cf[i].real + cf[i].imaginary;
    }
  }

  float res1_Cfloat = cblas_casum(10, cf, 1);
  float res2_Cfloat = cblas_casum(10, cf, 2);
  float res3_Cfloat = cblas_casum(10, cf, 3);
  float res4_Cfloat = cblas_casum(10, cf, 4);
  float res5_Cfloat = cblas_casum(10, cf, 5);

  printf("Test vecteur {");
  for (int i = 0; i < 10; i++) {
    if (i == 9){
        printf(" %f + %f i",cf[i].real, cf[i].imaginary );
    } else {
        printf(" %f + %f i,",cf[i].real, cf[i].imaginary );
    }
  }
  printf(" } :\n");
  if (res1_Cfloat< cor_res1_Cfloat-0.01 || res1_Cfloat> cor_res1_Cfloat+0.01){
    printf("Test failed for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res2_Cfloat< cor_res2_Cfloat-0.01 || res2_Cfloat> cor_res2_Cfloat + 0.01){
    printf("Test failed for index 2\n");
  } else {
    printf("Test index 2 Success\n");
  }
  if (res3_Cfloat< cor_res3_Cfloat-0.01 || res3_Cfloat > cor_res3_Cfloat+0.01){
    printf("Test failed for index 3\n");
  } else {
    printf("Test index 3 Success\n");
  }
  if (res4_Cfloat< cor_res4_Cfloat-0.01 || res4_Cfloat > cor_res4_Cfloat+0.01){
    printf("Test failed for index 4\n");
  } else {
    printf("Test index 4 Success\n");
  }
  if (res5_Cfloat< cor_res5_Cfloat-0.01 || res5_Cfloat > cor_res5_Cfloat+0.01){
    printf("Test failed for index 5\n");
  } else {
    printf("Test index 5 Success\n");
  }

  printf("\n--- Test asum Complexe double: ---\n");

  double cor_res1_Cdouble = 0;
  double cor_res2_Cdouble = 0;
  double cor_res3_Cdouble = 0;
  double cor_res4_Cdouble = 0;
  double cor_res5_Cdouble = 0;
  complexe_double_t cd[10];
  for (int i = 0; i < 10; i++) {
    if (i == 2){
      cd[i].real = -(i+3.8 + ((double)i/1000));
      cd[i].imaginary = -(i+9.2 + ((double)i/1000000));
    } else {
      cd[i].real = i+4.6532 + ((float)i/1000);
      cd[i].imaginary = i+2.984678 + ((float)i/1000000);
    }
  }

  for (int i = 0; i < 10; i++) {
    if (cd[i].real >= 0 && cd[i].imaginary >= 0){
      if (i%2 == 0){
        cor_res2_Cdouble += cd[i].real + cd[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cdouble += cd[i].real + cd[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cdouble += cd[i].real + cd[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cdouble += cd[i].real + cd[i].imaginary;
      }
      cor_res1_Cdouble += cd[i].real + cd[i].imaginary;
    } else if (cd[i].real < 0 && cd[i].imaginary < 0) {
      if (i%2 == 0){
        cor_res2_Cdouble += -cd[i].real - cd[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cdouble += -cd[i].real - cd[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cdouble += -cd[i].real - cd[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cdouble += -cd[i].real - cd[i].imaginary;
      }
      cor_res1_Cdouble += -cd[i].real - cd[i].imaginary;
    } else if (cd[i].real >=0 && cd[i].imaginary < 0){
      if (i%2 == 0){
        cor_res2_Cdouble += cd[i].real - cd[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cdouble += cd[i].real - cd[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cdouble += cd[i].real - cd[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cdouble += cd[i].real - cd[i].imaginary;
      }
      cor_res1_Cdouble += cd[i].real - cd[i].imaginary;
    } else {
      if (i%2 == 0){
        cor_res2_Cdouble += -cd[i].real + cd[i].imaginary;
      }
      if (i%3 == 0){
        cor_res3_Cdouble += -cd[i].real + cd[i].imaginary;
      }
      if (i%4 == 0){
        cor_res4_Cdouble += -cd[i].real + cd[i].imaginary;
      }
      if (i%5 == 0){
        cor_res5_Cdouble += -cd[i].real + cd[i].imaginary;
      }
      cor_res1_Cdouble += -cd[i].real + cd[i].imaginary;
    }
  }

  double res1_Cdouble = cblas_zasum(10, cd, 1);
  double res2_Cdouble = cblas_zasum(10, cd, 2);
  double res3_Cdouble = cblas_zasum(10, cd, 3);
  double res4_Cdouble = cblas_zasum(10, cd, 4);
  double res5_Cdouble = cblas_zasum(10, cd, 5);

  printf("Test vecteur {");
  for (int i = 0; i < 10; i++) {
    if (i == 9){
        printf(" %f + %f i",cd[i].real, cd[i].imaginary );
    } else {
        printf(" %f + %f i,",cd[i].real, cd[i].imaginary );
    }
  }
  printf(" } :\n");
  if (res1_Cdouble< cor_res1_Cdouble-0.01 || res1_Cdouble> cor_res1_Cdouble+0.01){
    printf("Test failed for index 1\n");
  } else {
    printf("Test index 1 Success\n");
  }
  if (res2_Cdouble< cor_res2_Cdouble-0.01 || res2_Cdouble> cor_res2_Cdouble + 0.01){
    printf("Test failed for index 2\n");
  } else {
    printf("Test index 2 Success\n");
  }
  if (res3_Cdouble< cor_res3_Cdouble-0.01 || res3_Cdouble > cor_res3_Cdouble+0.01){
    printf("Test failed for index 3\n");
  } else {
    printf("Test index 3 Success\n");
  }
  if (res4_Cdouble< cor_res4_Cdouble-0.01 || res4_Cdouble > cor_res4_Cdouble+0.01){
    printf("Test failed for index 4\n");
  } else {
    printf("Test index 4 Success\n");
  }
  if (res5_Cdouble< cor_res5_Cdouble-0.01 || res5_Cdouble > cor_res5_Cdouble+0.01){
    printf("Test failed for index 5\n");
  } else {
    printf("Test index 5 Success\n");
  }

  exit (0) ;

}
