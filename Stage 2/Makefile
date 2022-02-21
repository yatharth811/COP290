COMPILEFLAGS1 = -fopenmp -lmkl_intel_lp64 -lmkl_core -lmkl_gnu_thread -lpthread -lm -ldl 

COMPILEFLAGS2 =  -lopenblas -lpthread -lgfortran

LIB1 = /opt/intel/mkl/lib
LIB2 = /opt/OpenBLAS/lib
INC1 = /opt/intel/mkl/include
INC2 = /opt/OpenBLAS/include

main_cblas.out: main_cblas.cpp
	g++ main_cblas.cpp -o main_cblas.out -L $(LIB2) -I $(INC2) $(COMPILEFLAGS2)

main_mkl.out: main_mkl.cpp
	g++ main_mkl.cpp -o main_mkl.out -L $(LIB1) -I $(INC1) $(COMPILEFLAGS1)

threading.out: threading.cpp
	g++ threading.cpp -o threading.out  -lpthread

random_matrix.out: random_matrix.cpp
	g++ random_matrix.cpp -o random_matrix.out		

.PHONY: clean

clean:
	rm -f *.out *.exe