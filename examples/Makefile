all: test_complexe2 test_complexe perf_asum perf_dot perf_dot_dyn perf_copy perf_axpy perf_swap perf_gemv test_asum perf_gemm test_swap test_copy test_axpy test_nrm2 test_gemm test_gemv

INC_DIR=../include

LIB_DIR=../lib

LIBST=-lmnblas
LIBDYN=-lmnblasdyn

OPTIONS_COMPIL  =-Wall -O2 -fPIC -I$(INC_DIR)

OPTIONS_LINK_STATIC  =   -fopenmp -L$(LIB_DIR) $(LIBST)
OPTIONS_LINK_DYN  = -fopenmp -L$(LIB_DIR) $(LIBDYN)

perf_dot: perf_dot.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_dot perf_dot.o flop.o $(OPTIONS_LINK_STATIC)

perf_copy: perf_copy.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_copy perf_copy.o flop.o $(OPTIONS_LINK_STATIC)

perf_axpy: perf_axpy.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_axpy perf_axpy.o flop.o $(OPTIONS_LINK_STATIC)

perf_asum: perf_asum.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_asum perf_asum.o flop.o $(OPTIONS_LINK_STATIC)

perf_swap: perf_swap.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_swap perf_swap.o flop.o $(OPTIONS_LINK_STATIC)

perf_gemv: perf_gemv.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_gemv perf_gemv.o flop.o $(OPTIONS_LINK_STATIC)

perf_gemm: perf_gemm.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o perf_gemm perf_gemm.o flop.o $(OPTIONS_LINK_STATIC)

flop.o: flop.c flop.h
	gcc $(OPTIONS_COMPIL) -c flop.c

perf_dot_dyn: perf_dot.o flop.o
	gcc -o perf_dot_dyn flop.o perf_dot.o $(OPTIONS_LINK_DYN) -lm

perf_dot.o: perf_dot.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_dot.c

perf_copy.o: perf_copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_copy.c

perf_axpy.o: perf_axpy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_axpy.c

perf_asum.o: perf_asum.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_asum.c

perf_swap.o: perf_swap.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_swap.c

perf_gemv.o: perf_gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_gemv.c

perf_gemm.o: perf_gemm.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c perf_gemm.c

test_complexe.o: test_complexe.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_complexe.c

test_complexe: test_complexe.o flop.o
	gcc -o test_complexe test_complexe.o flop.o $(OPTIONS_LINK_STATIC)

test_complexe2.o: test_complexe2.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe2.c

test_complexe2: test_complexe2.o flop.o
	gcc -o test_complexe2 test_complexe2.o flop.o $(OPTIONS_LINK_STATIC)

test_asum.o: test_asum.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_asum.c

test_asum: test_asum.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_asum test_asum.o flop.o $(OPTIONS_LINK_STATIC)

test_swap.o: test_swap.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_swap.c

test_swap: test_swap.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_swap test_swap.o flop.o $(OPTIONS_LINK_STATIC)

test_copy.o: test_copy.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_copy.c

test_copy: test_copy.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_copy test_copy.o flop.o $(OPTIONS_LINK_STATIC)

test_nrm2.o: test_nrm2.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_nrm2.c -lm

test_nrm2: test_nrm2.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_nrm2 test_nrm2.o flop.o $(OPTIONS_LINK_STATIC) -lm

test_axpy.o: test_axpy.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_axpy.c

test_axpy: test_axpy.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_axpy test_axpy.o flop.o $(OPTIONS_LINK_STATIC)

test_gemv.o: test_gemv.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_gemv.c

test_gemv: test_gemv.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_gemv test_gemv.o flop.o $(OPTIONS_LINK_STATIC)

test_gemm.o: test_gemm.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_gemm.c

test_gemm: test_gemm.o flop.o  $(LIB_DIR)/libmnblas.a
	gcc -o test_gemm test_gemm.o flop.o $(OPTIONS_LINK_STATIC)

clean:
	rm -f *.o perf_dot perf_dot_dyn perf_copy perf_axpy perf_asum perf_swap perf_gemv perf_gemm test_complexe test_complexe2 test_asum test_swap test_copy test_axpy test_nrm2 test_gemm test_gemv*~

