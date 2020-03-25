#include "mnblas.h"
#include "complexe2.h"

float cblas_snrm2 (const int n, const float *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	float res = 0;
	for (int i = 0; i < n; i+=incx) {
		res+=pow(x[i], 2);
	}
	res=sqrt(res);
	return res;
}

double cblas_dnrm2 (const int n, const double *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = 0;
	for (int i = 0; i < n; i+=incx) {
		res+=pow(x[i], 2);
	}
	res=sqrt(res);
	return res;
}

void cblas_scnrm2 (const int n, const void *x, const int incx) { // A vérifier j'ai pas trop compris
	if (n <= 0 || incx <= 0) return 0;
	float res = 0;
	for (int i = 0; i < n; i+=incx) {
		res+=pow(x[i]->imaginary,2)+pow(x[i]->real,2);
	}
	res=sqrt(res);
	return res;
}

void cblas_dznrm2 (const int n, const void *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = 0;
	for (int i = 0; i < n; i+=incx) {
		res+=pow(x[i]->imaginary,2)+pow(x[i]->real,2);
	}
	res=sqrt(res);
	return res;
}



