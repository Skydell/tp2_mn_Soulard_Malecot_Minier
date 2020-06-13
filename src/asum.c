#include "../include/mnblas.h"
#include "../include/complexe2.h"

float cblas_sasum (const int n, const float *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	float res = 0;
	for (int i = 0; i < n; i+=incx) {
		if (x[i] < 0) res+=-x[i];
		else res+=x[i];
	}
	return res;
}

double cblas_dasum (const int n, const double *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = 0;
	for (int i = 0; i < n; i+=incx) {
		if (x[i] < 0) res+=-x[i];
		else res+=x[i];
	}
	return res;
}

float cblas_casum (const int n, const complexe_float_t *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	float res = 0;
	for (int i = 0; i < n; i+=incx) {
		if (x[i].real < 0) res+=-x[i].real;
		else res+=x[i].real;
		if (x[i].imaginary < 0) res+=-x[i].imaginary;
		else res+=x[i].imaginary;
	}
	return res;
}

double cblas_zasum (const int n, const complexe_double_t *x, const int incx) {
	if (n <= 0 || incx <= 0) return 0;
	double res = 0;
	for (int i = 0; i < n; i+=incx) {
		if (x[i].real < 0) res+=-x[i].real;
		else res+=x[i].real;
		if (x[i].imaginary < 0) res+=-x[i].imaginary;
		else res+=x[i].imaginary;
	}
	return res;
}
