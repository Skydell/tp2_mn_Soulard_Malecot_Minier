#include <stdbool.h>

void cblas_sgemv(const bool Layout, const int trans, const int m, const int n, const float alpha, const float *a, const int lda, const float *x, const int incx, const float beta, float *y, const int incy){
	if(trans == 1){
		if(layout){
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
		else{
			for(int i = 0;i<m*n;i++){
				a[i] = a[i]*alpha;
			}
			for(int j = 0; j<m; j++){
				float sum = 0;
				for(int i = 0; i<n; i++){
					sum += a[i]*x[i];
				}
				y[j] = sum + y[j]*beta;
			}
		}
	}
	else if(trans == 2){

	}
	else{

	}
}