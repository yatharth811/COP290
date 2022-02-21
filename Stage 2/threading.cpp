#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

typedef vector<vector<float>> vc2d;
typedef vector<float> vc1d;

vc2d input;
vc2d weight;
vc2d bias;
vc2d output;


// Function to take input matrix from a file
vc2d input_matrix(string file_name){
    int c,r;
    ifstream myfile;
    myfile.open(file_name);
    if(myfile.fail()){
        cerr<<"File doen't exist\n";
        exit(0);
    }
    myfile >> c >> r;
    vc2d inp(r, vc1d(c,0));
    for(int j=0; j<c; j++){
        for(int i=0; i<r; i++){
            float t;
            myfile >> t;
            inp[i][j] = t;
        }
    }
    myfile.close();
    return inp;
    
}

void* thread_matrix_multiplication( void* arg){

    int* r1 = (int *)arg;
    int row1= *r1;
    // cout<<row1<<endl;
    for(int j=0; j< bias[0].size(); j++){
        for(int k=0; k < input[0].size(); k++){
            output[row1][j] += input[row1][k]*weight[k][j];
        }
        output[row1][j] += bias[row1][j];
    }
    
    pthread_exit(0);
}

// Function to write a output matrix in column major order in a file
void ouput_matrix(vc2d v, string filename){
    ofstream myfile(filename, ofstream::trunc);
    if(myfile.is_open()){
        myfile << v[0].size() <<"\n";
        myfile << v.size() << "\n";
        for(int i=0;i<v[0].size();i++){
            for(int j=0;j<v.size();j++){
                myfile << fixed << setprecision(10)<<v[j][i] << "\n";
            }
        }
    }
}

int main(int argc,char **argv){
    string s = argv[1];              // Reads the second argument from command line
    if(s.compare("fullyconnected")==0 && argc==7){
        string h = argv[2];
        if(h.compare("pthread")==0){
        string  a=argv[3],b= argv[4], c= argv[5], d= argv[6];
        cout<<a<<"\n";
        input = input_matrix(a);       // Reads the input matrix from filename in var a
        weight = input_matrix(b);    // Reads the wight matrix from filename in var a
        bias = input_matrix(c);      // Reads the bias matrix from filename in var a
        
        int r_s = bias.size();
        int c_s = bias[0].size();

        vc2d output_mat( r_s , vc1d (c_s, 0));
        output = output_mat;

        auto start = steady_clock::now();
	    pthread_t tids[r_s];

        int arr[r_s];
        for(int j=0;j<r_s;j++){
            arr[j] = j;
        }
        
        for(int i = 0; i < r_s; i++){
            int row = i;
            //cout << row<<"\n";
            pthread_create(&tids[i], NULL, thread_matrix_multiplication, &arr[i]);
        }

        for (int i = 0; i < r_s; i++) {
            pthread_join(tids[i], NULL);
        }    
        auto end = steady_clock::now();
            
        cout << "Elapsed time in milliseconds: "
            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
            << " ms" << endl;    

        ouput_matrix(output,d);
        
        }

    }

    return 0;
}