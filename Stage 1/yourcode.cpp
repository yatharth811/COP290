#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0),cin.tie(0)
#define endl "\n"
#define forp(i,a,b) for(int i=a; i<b; i++)
using namespace std;
typedef vector<float> vf;
typedef vector<vector<float>> vff;

ifstream fin; // To read files 
ofstream fout; // To write to files
vff res; // To store output matrices
vf resv; // To store output vectors
int n, m;
string fileName;


vff fullyconnected(vff &a, vff &b, vff &c){
    int n1 = a.size(), m1 = a[0].size();
    int n2 = b.size(), m2 = b[0].size();
    vff res(n1, vf(n2, 0));
	// Matrix multiplication followed by addition of bias matrix element wise.
    forp(i,0,n1){
        forp(j, 0, m2){
            forp(k, 0, m1){
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] += c[i][j];
        }
    }
    return res;
}


void printMatrix(vff &a){
	// Helper function to print matrix on console.
    forp(i,0,a.size()){
        forp(j,0,a[i].size()){
            cout << a[i][j] << " \n"[j==(int)a[i].size()-1];
        }
    }
}


vff relu(vff &a){
	// Applying relu function on elements of matrix. Relu: f(x) = max(0, x).
	vff res(a.size(), vf(a[0].size()));
    forp(i,0,a.size()){
        forp(j, 0, a[i].size()){
            res[i][j] = max(.0f, a[i][j]);
        }
    }
    return res;
}


vff tanh(vff &a){
	// Applying tanh function on matrix elements. Tanh: f(x) : (e^x - e^-x)/(e^x + e^-x).
	vff res(a.size(), vf(a[0].size()));
    forp(i,0,a.size()){
        forp(j, 0, a[i].size()){
            res[i][j] = (exp(a[i][j]) - exp(-a[i][j]))/ (exp(a[i][j]) + exp(-a[i][j]));
        }
    }
    return res;
}


vf sigmoid(vf &a){
	// Applying sigmoid on the vector.
	vf res;
	for (auto x: a){
		float sig = 1/(1+exp(-x));
		res.push_back(sig);
	}
	return res;
}


vf softmax(vf &a){
	// Applying softmax on the vector.
	vf res;
	float sumsig = 0;
	for (auto x: a){
		sumsig += exp(x);
	}
	for (auto x: a){
		res.push_back(exp(x)/sumsig);
	}
	return res;
}


vff maxpool(vff &a, int stride){
	// Applying maxpool using filter of dimensions stride x stride.
	int n = a.size(), m = a[0].size();
	vff res(n/stride, vf(m/stride));
	forp(i,0,n/stride){
		forp(j, 0, m/stride){
			float maxx = a[i*stride][j*stride];
			forp(k, i*stride, (i+1)*stride){
				forp(l, j*stride, (j+1)*stride){
					maxx = max(a[k][l], maxx);
				}
			}
			res[i][j] = maxx;
		}
	}
	return res;
}


vff avgpool(vff &a, int stride){
	// Applying average pooling using filter of dimensions stride x stride.
	int n = a.size(), m = a[0].size();
	vff res(n/stride, vf(m/stride));
	forp(i,0,n/stride){
		forp(j, 0, m/stride){
			float avg = 0;
			forp(k, i*stride, (i+1)*stride){
				forp(l, j*stride, (j+1)*stride){
					avg += a[k][l];
				}
			}
			res[i][j] = avg/(stride*stride);
		}
	}
	return res;
}


vff inmatrix(string fileName){
	fin.open(fileName);		
			// If unable to open file raise error on console and exit program gracefully. 
	if (fin.fail()){
		cout << fileName << " is required for input but it doesn't exist." << endl;
		exit(0);
	}
	// Reading matrix dimensions from the appropriate file and declaring corresponding vector.
	fin >> m >> n;
	vff inputmatrix(n, vf(m));
	//Reading matrix elements
	forp(j, 0, m){
		forp(i,0,n){
			fin >> inputmatrix[i][j];
		}
	}
	fin.close();
	return inputmatrix;
}



void outmatrix(vff &res, string fileName){
	fout.open(fileName);
	fout << res.size() << endl;
	fout << res[0].size() << endl;

	// Writing matrix elements to the file.
	forp(j,0,res[0].size()){
		forp(i,0,res.size()){
			fout << res[i][j] << endl;
		}
	}

	fout.close();
	return;
}


vf invector(string fileName){
	fin.open(fileName);
	// If unable to open file raise error on console and exit program gracefully. 
	if (fin.fail()){
		cout << fileName << " is required for input but it doesn't exist." << endl;
		exit(0);
	}

			// Reading vector dimension and elements from the input file.
	fin >> n;
	vf inputvector(n);
	forp(i,0,n){
		fin >> inputvector[i];
	}
	fin.close();
	return inputvector;
}

void outvector(vf &a, string fileName){
	fout.open(fileName);
	fout << n << endl;
	for (auto x: a) fout << x << endl;
	fout.close();
}


int main(int argc, char **argv){
    FAST;
    string whatToDo = argv[1], choice; 
	
	try{

   		if (whatToDo == "fullyconnected" && argc == 6){
			//To open text file
			fileName = argv[2];
			vff inputmatrix = inmatrix(fileName);

			fileName = argv[3];
			vff weightmatrix = inmatrix(fileName);

			fileName = argv[4];
			vff biasmatrix = inmatrix(fileName);

			res = fullyconnected(inputmatrix, weightmatrix, biasmatrix);
			fileName = argv[5];

			outmatrix(res, fileName);

   		}
   		else if (whatToDo == "activation" && argc == 5){
			// Choice variable to store whether to use relu or tanh activation.
			choice = argv[2];

			fileName = argv[3];
			vff inputmatrix = inmatrix(fileName);

			if (choice == "relu"){
				res = relu(inputmatrix);
			}
			else if (choice == "tanh"){
				res = tanh(inputmatrix);
			}
			else{
				cout << "You were supposed to pass either relu or tanh after activation. But you have passed something else." << endl;
				return 0; 
			}

			
			fileName = argv[4];
			outmatrix(res, fileName);

   		}
   		else if (whatToDo == "pooling" && argc == 6){
			// Storing whether max pool or average pool in choice variable
			choice = argv[2];
			string st = argv[4];
			int stride = stoi(st);

			fileName = argv[3];
			vff inputmatrix = inmatrix(fileName);

			if (m%stride !=0 || n%stride!=0){
				cout << "You have passed in wrong stride. It either is not an int value or it doesn't divide matrix dimensions. Please check again." << endl;
				return 0;
			}

			// Opening file to write output
			if (choice == "max"){
				res = maxpool(inputmatrix, stride);
			}
			else if (choice == "average"){
				res = avgpool(inputmatrix, stride);
			}
			else{
				cout << "You were supposed to pass either max or average after pooling. But you have passed something else." << endl;
				return 0;
			}
	
			fileName = argv[5];
			outmatrix(res, fileName);


   		}
   		else if (whatToDo == "probability" && argc == 5){
			choice = argv[2];
			
			fileName = argv[3];
			vf inputvector = invector(fileName);
			
			if (choice == "sigmoid"){
				resv = sigmoid(inputvector);
			}
			else if (choice =="softmax"){
				resv = softmax(inputvector);
			}
			else{
				cout << "You were supposed to pass either sigmoid or softmax after probability. But you have passed something else." << endl;
			}

			fileName = argv[4];
			outvector(resv, fileName);
			
   		}
   		else{
   			cout << "You have either passed wrong arguments or insufficient arguments. Check spellings as well." << endl;
   		}
	}
	catch(string e){
		cout << e << "Please check that the arguments passed exist or not." << endl;
	}
    return 0;
}