#include<bits/stdc++.h>
#include "audio.h"
using namespace std;

vector<string> audios{"silence", "unknown", "yes", "no", "up", "down", "left", "right", "on", "off", "stop", "go"};

int main(int argc, char** argv){
    pred_t* ans = new pred_t[3];
    ans = libaudioAPI(argv[1], ans);
    pred_t a1 = *(ans);
    pred_t a2 = *(ans+1);
    pred_t a3 = *(ans+2);
    ofstream fout;
    fout.open(argv[2], ios_base::app);
    fout << argv[1] << " " << audios[a1.label-1] << " " << audios[a2.label-1] << " " << audios[a3.label-1] << " " << a1.prob << " " << a2.prob << " " << a3.prob << endl; 
    fout.close();
    delete[] ans;
    return 0;
}