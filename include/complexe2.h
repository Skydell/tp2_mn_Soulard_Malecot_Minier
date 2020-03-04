
typedef struct {
  float real ;
  float imaginary ;
} complexe_float_t ;

typedef struct {
  double real ;
  double imaginary ;
} complexe_double_t ;

inline complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

inline complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

inline complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
	complexe_float_t r ;

	r.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
	r.imaginary = c1.real * c2.imaginary - c1.imaginary * c2.real;
  
	return r ;
}

inline complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
	complexe_double_t r ;

	r.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
	r.imaginary = c1.real * c2.imaginary - c1.imaginary * c2.real;
  
	return r ;
}


inline complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t c2conjug;

  c2conjug.real = c2.real;
  c2conjug.imaginary = (-1.0)*c2.imaginary;

  complexe_float_t resinter = mult_complexe_float(c1, c2conjug);
  complexe_float_t resinter2 = mult_complexe_float(c2, c2conjug);

  complexe_float_t res;
  res.real = resinter.real/resinter2.real;
  res.imaginary = resinter.imaginary/resinter2.real;

  return res;
}

inline complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t c2conjug;

  c2conjug.real = c2.real;
  c2conjug.imaginary = (-1.0)*c2.imaginary;

  complexe_double_t resinter = mult_complexe_double(c1, c2conjug);
  complexe_double_t resinter2 = mult_complexe_double(c2, c2conjug);

  complexe_double_t res;
  res.real = resinter.real/resinter2.real;
  res.imaginary = resinter.imaginary/resinter2.real;

  return res;
}