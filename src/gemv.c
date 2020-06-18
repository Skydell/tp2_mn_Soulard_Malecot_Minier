#include "complexe.c"

void cblas_sgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a, const int lda, const float *x, const int incx, const float beta, float *y, const int incy){
	for(int i = 0;i<m*n;i++){
		a[i] = a[i]*alpha;
	}
	for(int j = 0; j<n; j+=incy){
		float sum = 0;
		for(int i = 0; i<m; i+=incx){
			sum += a[i]*x[i];
		}
		y[j] = sum + y[j]*beta;
	}
}

void cblas_dgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const double alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	for(int i = 0;i<m*n;i++){
		((double*)a)[i] = ((double*)a)[i]*alpha;
	}
	for(int j = 0; j<n; j+=incy){
		double sum = 0;
		for(int i = 0; i<m; i+=incx){
			sum += ((double*)a)[i]*((double*)x)[i];
		}
		((double*)y)[j] = sum + ((double*)y)[j]*beta;
	}
}

void cblas_cgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const void *alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	complexe_float_t resalpha = malloc(sizeof(complexe_float_t));
	resalpha.real = alpha;
	resalpha.imaginary = 0;
	for(int i = 0;i<m*n;i++){
		((complexe_float_t*)a)[i] = mult_complexe_float(((complexe_float_t*)a)[i], resalpha);
	}
	for(int j = 0; j<n; j+=incy){
		complexe_float_t sum = malloc(sizeof(complexe_float_t));
		sum.real = 0;
		sum.imaginary = 0;
		for(int i = 0; i<m; i+=incx){
			sum = add_complexe_float( mult_complexe_float(((complexe_float_t*)a)[i], ((complexe_float_t*)x)[i]), sum);
		}
		complexe_double_t resbeta = malloc(sizeof(complexe_float_t));
		resbeta.real = beta;
		resbeta.imaginary = 0;
		((complexe_float_t*)y)[j] = add_complexe_float(sum, mult_complexe_float(((complexe_float_t*)y)[j], resbeta));
	}
}

void cblas_zgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const void *alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	complexe_double_t resalpha = malloc(sizeof(complexe_double_t));
	resalpha.real = alpha;
	resalpha.imaginary = 0;
	for(int i = 0;i<m*n;i++){
		((complexe_double_t*)a)[i] = mult_complexe_double(((complexe_double_t*)a)[i], resalpha);
	}
	for(int j = 0; j<n; j+incy){
		complexe_double_t sum = malloc(sizeof(complexe_double_t));
		sum.real = 0;
		sum.imaginary = 0;
		for(int i = 0; i<m; i+incx){
			sum = add_complexe_double( mult_complexe_double(((complexe_double_t*)a)[i], ((complexe_double_t*)x)[i]), sum);
		}
		complexe_double_t resbeta = malloc(sizeof(complexe_double_t));
		resbeta.real = beta;
		resbeta.imaginary = 0;
		((complexe_double_t*)y)[j] = add_complexe_double(sum, mult_complexe_double(((complexe_double_t*)y)[j], resbeta));
	}
}