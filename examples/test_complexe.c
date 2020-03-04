#include <stdio.h>
#include <x86intrin.h>

#include "mnblas.h"
#include "complexe.h"

#include "flop.h"

#define    NB_FOIS        4194304

int main (int argc, char **argv)
{
 complexe_float_t c1= {1.0, 2.0} ;
 complexe_float_t c2= {3.0, 6.0} ;
 complexe_float_t c3 ;
 complexe_float_t c4;

 complexe_double_t cd1 ;
 complexe_double_t cd2 ;
 complexe_double_t cd3 ;
 complexe_double_t cd4 ;

 unsigned long long int start, end ;
 unsigned long long int start2, end2 ;
 unsigned long long int start3, end3 ;
 unsigned long long int start4, end4 ;
 int i ;

 init_flop () ;

 c3 = add_complexe_float (c1, c2) ;

 printf("---------Addition de complexes simples :--------\n");
 printf("c1.r %f c1.i %f\n", c1.real, c1.imaginary);
 printf("c2.r %f c2.i %f\n", c2.real, c2.imaginary);
 printf("--- c1 + c2 = c3 ---\n");
 printf ("c3.r %f c3.i %f\n", c3.real, c3.imaginary) ;

 c4 = mult_complexe_float(c1, c2) ;

 printf("---------Multiplication de complexes simples :--------\n");
 printf("--- c1 x c2 = c4 ---\n");
 printf ("c4.r %f c4.i %f\n", c4.real, c4.imaginary) ;


 cd1 = (complexe_double_t) {10.0, 7.0} ;
 cd2 = (complexe_double_t) {25.0, 32.0} ;

 cd3 = add_complexe_double (cd1, cd2) ;

 printf("---------Addition de complexes doubles :--------\n");
 printf("cd1.r %f cd1.i %f\n", cd1.real, cd1.imaginary);
 printf("cd2.r %f cd2.i %f\n", cd2.real, cd2.imaginary);
 printf("--- cd1 + cd2 = cd3 ---\n");
 printf ("cd3.r %f cd3.i %f\n", cd3.real, cd3.imaginary) ;

 cd4 = mult_complexe_double (cd1, cd2) ;

 printf("---------Multiplication de complexes simples :--------\n");
 printf("--- cd1 x cd2 = cd4 ---\n");
 printf ("cd4.r %f cd4.i %f\n", cd4.real, cd4.imaginary) ;

 start =_rdtsc () ;

 for (i = 0 ; i < NB_FOIS; i++)
   {
     cd3 = add_complexe_double (cd1, cd2) ;
   }

 end = _rdtsc () ;

 start2 = _rdtsc () ;

 for (i = 0; i < NB_FOIS; i++) {
   cd4 = mult_complexe_double (cd1, cd2) ;
 }

 end2 = _rdtsc () ;

 start3 = _rdtsc () ;

 for (i = 0; i < NB_FOIS; i++) {
   c3 = add_complexe_float (c1, c2) ;
 }

 end3 = _rdtsc () ;

 start4 = _rdtsc () ;

 for (i = 0; i < NB_FOIS; i++) {
   c4 = mult_complexe_float (c1, c2) ;
 }

 end4 = _rdtsc () ;

  printf("--- Addition complexe simple : ---\n");
  printf ("apres boucle c3.real %f c3.imaginary %f %lld cycles \n", c3.real, c3.imaginary, end3-start3) ;
  calcul_flop ("calcul complexe ", NB_FOIS*4, end3-start3) ;
  printf("--- Multiplication complexe simple : ---\n");
  printf ("apres boucle c4.real %f c4.imaginary %f %lld cycles \n", c4.real, c4.imaginary, end4-start4) ;
  calcul_flop ("calcul complexe ", NB_FOIS*4, end4-start4) ;
  printf("--- Addition complexe double : ---\n");
  printf ("apres boucle cd3.real %f cd3.imaginary %f %lld cycles \n", cd3.real, cd3.imaginary, end-start) ;
  calcul_flop ("calcul complexe ", NB_FOIS*4, end-start) ;
  printf("--- Multiplication complexe double : ---\n");
  printf ("apres boucle cd4.real %f cd4.imaginary %f %lld cycles \n", cd4.real, cd4.imaginary, end2-start2) ;
  calcul_flop ("calcul complexe ", NB_FOIS*4, end2-start2) ;
  exit (0) ;
}
