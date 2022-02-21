#include<bits/stdc++.h>
#include<random>
#define endl '\n'
using namespace std;

float get_random(){
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(e);
}


int main(){
    int n = 2048, m = 2048;
    ofstream fout;
    fout.open("random.txt");
    fout << n << endl;
    fout << m << endl;
    srand(time(0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            fout << ((10) * ((float)rand() / RAND_MAX)) << " ";
        }
        fout << endl;
    }
    return 0;
}