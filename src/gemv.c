void cblas_sgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a, const int lda, const float *x, const int incx, const float beta, float *y, const int incy){
	for(int i = 0;i<m*n;i++){
		a[i] = a[i]*alpha;
	}
	for(int j = 0; j<n; j++){
		float sum = 0;
		for(int i = 0; i<m; i++){
			sum += a[i]*x[i];
		}
		y[j] = sum + y[j]*beta;
	}
}

void cblas_dgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const double alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	for(int i = 0;i<m*n;i++){
		((double*)a)[i] = ((double*)a)[i]*alpha;
	}
	for(int j = 0; j<n; j++){
		float sum = 0;
		for(int i = 0; i<m; i++){
			sum += ((double*)a)[i]*((double*)x)[i];
		}
		((double*)y)[j] = sum + ((double*)y)[j]*beta;
	}
}

void cblas_cgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const void *alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	for(int i = 0;i<m*n;i++){
		((double*)a)[i] = ((double*)a)[i]*alpha;
	}
	for(int j = 0; j<n; j++){
		float sum = 0;
		for(int i = 0; i<m; i++){
			sum += ((double*)a)[i]*((double*)x)[i];
		}
		((double*)y)[j] = sum + ((double*)y)[j]*beta;
	}
}

void cblas_zgemv(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const int m, const int n, const void *alpha, const void *a, const int lda, const void *x, const int incx, const void *beta, void *y, const int incy){
	for(int i = 0;i<m*n;i++){
		((double*)a)[i] = ((double*)a)[i]*alpha;
	}
	for(int j = 0; j<n; j++){
		float sum = 0;
		for(int i = 0; i<m; i++){
			sum += ((double*)a)[i]*((double*)x)[i];
		}
		((double*)y)[j] = sum + ((double*)y)[j]*beta;
	}
}