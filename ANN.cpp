#include<bits/stdc++.h>
#include<ctime>
#include "numPy.cpp"
using namespace std;

typedef long long ll;
typedef long double ld;

class Dense{
    //code here
    int units, preInputs = 1, Outputs = 1;
    double input, data, output;
    vector<ndArray> weights;
    ndArray* bias;
    int* child;
    bool setActivaion;

    double sigmoid(double inp){
        return (1 / (1 + exp(-inp)));
    }

    double ReLU(double inp){
        return max(0, inp);
    }

public:
    Dense(int units, string activation){
        this->units = units;
        bias = new ndArray(units);

        srand(time(0));
        for(int i = 0; i< units; i++){
            bias[i] = rand();
            ndArray a(preInputs);
            for(int j = 0; j< preInputs; j++){
                double z = (double)(rand() % 1e3);
                a.push(z);
            }
            weights.push_back(a);
        }

        if(activation == "sigmoid"){
            setActivaion = true;
        }
        else if(activation == "ReLU"){
            setActivaion = false;
        }
    }

    void setInputs(int num){
        preInputs = num;
    }

    
};
 
int main(){
    //complete main here
 
    return 0;
}