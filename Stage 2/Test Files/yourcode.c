// #include "/mnt/c/Users/yatha/desktop/tmp/openblas/cblas.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "mkl.h"

using namespace std;


int main()
{
    //(m*k) X (k*n) = (m*n);

    int m,k,n;
    m=200;
    k=20;
    n=100;

    vector<float> A(m*n), B(k*n), C(m*n);
    //int m,n,k,i,j;
    
    
    // alpha*A*B + beta*C

    float alpha = 1.0;
    float beta  = 1.0;

    for(int i=0 ; i< (m*k) ; i++)
    {
        A[i]= 1.0;
    }

    for(int i=0 ; i< (k*n) ; i++)
    {
        B[i]= 1.0;
    }

    for(int i=0 ; i< (m*n) ; i++)
    {
        C[i]= 1.0;
    }

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, alpha, A, k, B, n, beta, C, n);

    cout<<"done?\n";

    for(int i=0 ; i< (m*n) ; i++)
    {
        cout<<C[i]<<" ";
    }

    cout<<endl;
     




}