#include "mnblas.h"
#include "complexe2.h"

float cblas_isamax (const int n, const float *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	float res = x[0];
	for (int i = incx; i < n; i+=incx) {
		if (x[i] > res) res = x[i];
	}
	return res;
}

double cblas_idamax (const int n, const double *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = x[0];
	for (int i = incx; i < n; i+=incx) {
		if (x[i] > res) res = x[i];
	}
	return res;
}

void cblas_icamax (const int n, const void *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	float res = x[0]->real + x[0]->imaginary;
	for (int i = incx; i < n; i+=incx) {
		if (x[i]->real + x[i]->imaginary > res) res = x[i]->real + x[i]->imaginary;
	}
	return res;
}

void cblas_izamax (const int n, const void *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = x[0]->real + x[0]->imaginary;
	for (int i = incx; i < n; i+=incx) {
		if (x[i]->real + x[i]->imaginary > res) res = x[i]->real + x[i]->imaginary;
	}
	return res;
}


