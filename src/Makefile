# une bibliotheque statique (libmnblas.a)
# une bibliotheque dynamique (libmnblasdyn.so)

all: libmnblas.a libmnblasdyn.so

LIB_DIR=../lib
INC_DIR=../include
OPTIM=-O2 -fopenmp

OPTIONS=-O2 -Wall -fPIC $(OPTIM) -I$(INC_DIR)
# Bibliothèque statique

libmnblas.a: copy.o swap.o axpy.o dot.o complexe.o nrm2.o gemv.o gemm.o
	rm -f libmnblas.a $(LIB_DIR)/libmnblas.a
	ar -r libmnblas.a copy.o swap.o axpy.o dot.o complexe.o nrm2.o gemv.o gemm.o
	cp libmnblas.a $(LIB_DIR)

# Bibliothèque dynamique

libmnblasdyn.so:copy.o swap.o axpy.o dot.o complexe.o nrm2.o gemv.o gemm.o
	rm -f libmnblasdyn.so $(LIB_DIR)/libmnblasdyn.so
	gcc -shared -o libmnblasdyn.so copy.o swap.o axpy.o dot.o complexe.o nrm2.o gemv.o gemm.o
	cp libmnblasdyn.so $(LIB_DIR)

complexe.o: $(INC_DIR)/complexe.h complexe.c
	gcc $(OPTIONS) -c complexe.c

# BLAS 1

copy.o : copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c -fopenmp copy.c

swap.o : swap.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c -fopenmp swap.c

dot.o : dot.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c -fopenmp dot.c

axpy.o : axpy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c -fopenmp axpy.c

nrm2.o : nrm2.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c -fopenmp nrm2.c -lm

# BLAS 2

gemv.o : gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c -fopenmp gemv.c

# BLAS 3

gemm.o : gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c -fopenmp gemm.c

clean:
	rm -f *.o *.a *.so *~  $(INC_DIR)/*~ $(LIB_DIR)/libmnblasdyn.so  $(LIB_DIR)/libmnblas.a 


