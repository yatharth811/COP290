Author: Yatharth Kumar, 2020CS10413
Filename: yourcode.cpp

Instructions to run the file:

1. In terminal run make to first compile the c++ file.
2. Then use any of the following commands
   2.1 ./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt
   2.2 ./yourcode.out activation relu inputmatrix.txt outputmatrix.txt
   2.3 ./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt
   2.4 ./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt
   2.5 ./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt
   2.6 ./yourcode.out probability softmax inputvector.txt outputvector.txt
   2.7 ./yourcode.out probability sigmoid inputvector.txt outputvector.txt

   Please note the files to be used as input must be present already in same directory as the cpp file.
   Otherwise you will get a message on console stating the missing file.

3. In the end, run make clean in terminal to remove all the "*.out" files.


Submission for Part 1 of Task 1

Different functions declared in the file yourcode.cpp are:

1. fullyconnected: This function takes inputmatrix, weightmatrix and biasmatrix as input
   and returns the output matrix.

2. printmatrix: This is a helper function I created for myself for debugging. It takes a 
   matrix as an input and outputs it on console.

3. relu: This function takes an input matrix as input and applies relu activation method
   on elements of the input matrix and outputs a new matrix.
   Relu function is : f(x) = max(0, x).

4. tanh: This function takes an input matrix as input and applies tanh activation method
   on elements of the input matrix and outputs a new matrix.
   Tanh function is : f(x) = (e^x - e^-x) / (e^x + e^-x).

5. sigmoid: This function takes a vector as input and outputs a new vector by applying 
   sigmoid function on the elements of vector.
   Sigmoid function is : f(x) = 1/(1 + exp(-x))

6. softmax: This function takes a vector as input and outputs a new vector by applying 
   softmax function on the elements of vector.
   Softmax function is : f(x) = exp(x) / [sigma(exp(i)) where i belongs to input vector]

7. maxpool: Maxpool is maximum pooling method, it takes matrix and stride as input where
   stride is the dimension of filter matrix. It applies filter on certain area of the
   matrix and returns the maximum element out of that area, and these maximum elements 
   are used to generate new matrix which is returned as output.

8. avgpool: Avgpool is average pooling method, it takes matrix and stride as input where
   stride is the dimension of filter matrix. It applies filter on certain area of the
   matrix and returns the average of elements in that area, and these maximum elements 
   are used to generate new matrix which is returned as output.

9. main: Main function is used to handle the calling of different functions based on the
   different arguments passed along with ./yourcode.out.