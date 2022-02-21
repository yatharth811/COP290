# **COP290 Subtask 2**
## **Authors**: Yatharth Kumar (2020CS10413), Geetansh Juneja (2020CS50649) 
---
## **Main Files**: main_cblas.cpp, main_mkl.cpp and threading.cpp
---
1. **main_cblas.cpp**: Matrix Multiplication using OpenBLAS.
2. **main_mkl.cpp**: Matrix Multiplication using Intel-MKL.
3. **threading.cpp**: Matrix Multiplication using pthreads.
---

Instructions to run the file are as follows:

1. run `make main_cblas.out` to generate openblas executable, `make main_mkl.out` to generate mkl executable and `make threading.out` to generate pthread executable.
2. The command line format to generate output text file is as follows:
    * `./main_cblas.out fullyconnected openblas inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt`
    *  `./main_mkl.out fullyconnected mkl inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt`
    *  `./threading.out fullyconnected pthread inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt`
---
Functions implemented in the main_cblas.cpp are as follows:
1. **FCLayer**: This function is the implementation for matrix multiplication used in stage 1.
2. **input_vector**: This function takes input of file name, reads it and returns a tuple of float pointer pointing to the matrix read and its dimensions.
3. **openBlasMultiplication**: This function takes float matrices as input and returns matrix multiplication of input and weight matrix, followed by addition of bias matrix.
4. **outmatrix**: This function returns output matrix in a textfile.

---
Functions implemented in the main_mkl.cpp are as follows:
1. **FCLayer**: This function is the implementation for matrix multiplication used in stage 1.
2. **input_vector**: This function takes input of file name, reads it and returns a tuple of float pointer pointing to the matrix read and its dimensions.
3. **mklMultiplication**: This function takes float matrices as input and returns matrix multiplication of input and weight matrix, followed by addition of bias matrix.
4. **outmatrix**: This function returns output matrix in a textfile.

---
Functions implemented in the threading.cpp are as follows:
1. **input_matrix**: This function takes input of file name, reads it and returns a 2d vector.
2. **thread_matrix_multiplication**: This function takes float matrices as input and returns matrix multiplication of input and weight matrix, followed by addition of bias matrix. This functions is executed by threads created in main function.
3. **ouput_matrix**: This function returns output matrix in a textfile.

---
Few helper files, scripts and plots have been added as well.
1. **random_matrix.cpp**: Generates random float matrix of specified size (used for testing).
2. **fclayerplot.p**: GNU Script for plotting fclayer implementation.
3. **mklplt.p**: GNU Script for plotting mkl implementation
4. **openblasplot.p**: GNU Script for plotting openblas implementation.
5. **thtreadplot.p**: GNU Script for plotting pthread implementation.

---
Plot scripts, png and data are storef in folder Plot Data.