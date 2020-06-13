#include "../include/complexe.h"

void cblas_sgemm(const int m, const int n, const int k, const float alpha, const float *a, const int lda, const float *b, const int ldb, const float beta, float *c, const int ldc) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c[i*n+j] = c[i*n+j] * beta;
			float caseVal = 0.0;
			for (int l = 0; l < k; l++) {
				caseVal += a[i*k+l] * b[l*n+j];
			}
			caseVal = caseVal * alpha;
			c[i*n+j] += caseVal;
		}
	}
} 

void cblas_dgemm(const int m, const int n, const int k, const double alpha, const double *a, const int lda, const double *b, const int ldb, const double beta, double *c, const int ldc) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c[i*n+j] = c[i*n+j] * beta;
			float caseVal = 0.0;
			for (int l = 0; l < k; l++) {
				caseVal += a[i*k+l] * b[l*n+j];
			}
			caseVal = caseVal * alpha;
			c[i*n+j] += caseVal;
		}
	}
} 

void cblas_cgemm(const int m, const int n, const int k, const void* alpha, const void *a, const int lda, const void *b, const int ldb, const void* beta, void *c, const int ldc) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(((complexe_float_t **)c)[i*n+j]) = mult_complexe_float(*(((complexe_float_t **)c)[i*n+j]), *((complexe_float_t *)beta));
			complexe_float_t caseVal;
			for (int l = 0; l < k; l++) {
				caseVal = add_complexe_float(caseVal, mult_complexe_float(*(((complexe_float_t **)a)[i*k+l]), *(((complexe_float_t **)b)[l*n+j])));
			}
			caseVal = mult_complexe_float(caseVal, *((complexe_float_t *)alpha));
			*(((complexe_float_t **)c)[i*n+j]) = add_complexe_float(*(((complexe_float_t **)c)[i*n+j]), caseVal);
		}
	}
} 

void cblas_zgemm(const int m, const int n, const int k, const void* alpha, const void *a, const int lda, const void *b, const int ldb, const void* beta, void *c, const int ldc) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(((complexe_double_t **)c)[i*n+j]) = mult_complexe_double(*(((complexe_double_t **)c)[i*n+j]), *((complexe_double_t *)beta));
			complexe_double_t caseVal;
			for (int l = 0; l < k; l++) {
				caseVal = add_complexe_double(caseVal, mult_complexe_double(*(((complexe_double_t **)a)[i*k+l]), *(((complexe_double_t **)b)[l*n+j])));
			}
			caseVal = mult_complexe_double(caseVal, *((complexe_double_t *)alpha));
			*(((complexe_double_t **)c)[i*n+j]) = add_complexe_double(*(((complexe_double_t **)c)[i*n+j]), caseVal);
		}
	}
} 
