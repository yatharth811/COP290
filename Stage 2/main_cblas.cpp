#include<bits/stdc++.h>
// #include<mkl.h>
#include<cblas.h>
using namespace std;
typedef vector<vector<float>> vc2d;
typedef vector<float> vc1d;
typedef tuple<float*, int, int> tff;
#define endl '\n'

// Function to calculate inner product of two matrices and add bias vector.
vc2d FClayer(vc2d &input_matrix, vc2d &weight_matrix, vc2d &bias_vector){
    int n = input_matrix[0].size();
    int m = weight_matrix.size();
    int a = input_matrix.size();
    int b = weight_matrix[0].size();
    vc2d final(a, vc1d(b,0));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<n;k++){
                final[i][j] += input_matrix[i][k]*weight_matrix[k][j];
            }
            final[i][j] += bias_vector[i][j];
        }
    }
    
    return final;
}

// Function to take input vector from a file
tuple<float*, int, int> input_vector(string filename){
    ifstream myfile;
    myfile.open(filename);
    if(myfile.fail()){
        cerr<<"File doen't exist\n";
        exit(0);
    }

    int c,r;
    myfile >> c >> r;
    float* v = new float[c*r];
    
    for(int i=0;i<c*r;i++){
        myfile >> v[i];
    }
    myfile.close();

    return make_tuple(v, c, r);
}

// Function to multiply matrix using cblas available in openblas library
float* openBlasMultiplication(float* input_matrix, float* weight_matrix, float* bias_matrix, int m, int n, int k){
    // A -> m*k, B -> k*n, C -> m*n, alpha -> scale product, A -> array of float
    // beta -> scales C

    cblas_sgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1.0f, input_matrix, m, weight_matrix, k, 1.0f, bias_matrix, m);

    return bias_matrix;
}

// Function to ouput matrix in column major form in a text file.
void outmatrix(float* output_matrix, int column, int row,  string fileName){
    ofstream fout;
	fout.open(fileName);
	fout << column << endl;
	fout << row << endl;

	// Writing matrix elements to the file.
	for (int i=0; i<column*row; i++){
        fout << *(output_matrix + i) << endl;
    }

	fout.close();
	return;
}



int main(int argc,char **argv){
    
    string s = argv[1];
    
    if (s == "fullyconnected" && (argc == 6)){
        string a = argv[2], b = argv[3], c = argv[4], d = argv[5]; 

        tff temp1 = input_vector(a);
        float* abc = get<0>(temp1);
        int n1 = get<1>(temp1), m1 = get<2>(temp1);
        
        tff temp2 = input_vector(b);
        float* weight = get<0>(temp2);
        int n2 = get<1>(temp2), m2 = get<2>(temp2);
        
        tff temp3 = input_vector(c);
        float* bias = get<0>(temp3);    
        int n3 = get<1>(temp3), m3 = get<2>(temp3);

        auto start = chrono::steady_clock::now();
        float* output_matrix = openBlasMultiplication(abc, weight, bias, m3, n3, n1);
        auto end = chrono::steady_clock::now();

        cout << "Elapsed time in milliseconds: "
            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
            << " ms" << endl;
          
        outmatrix(output_matrix, n3, m3, d);

        delete[] abc, weight, bias;
    }

    return 0;

}
