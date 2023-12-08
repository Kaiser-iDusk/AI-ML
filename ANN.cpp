#include<bits/stdc++.h>
#include "numPy.cpp"
using namespace std;

typedef long long ll;
typedef long double ld;

class Perceptron{
    //code here
    double sigmoid(double inp){
        return (1 / (1 + exp(-inp)));
    }

    double ReLU(double inp){
        return max(0, inp);
    }

    double

public:
    int units;
    int swt = 0;
    int* child;
    double data;
    double* weights;
    double* bias;

    Perceptron(int units, string activation){
        srand();
        this->units = units;
        bias = new double[units];
        weights = new double[units];

        for(int i = 0; i< units; i++){
            bias[i] = 0.0;
            weights[i] = (double)(rand() % 1e6);
        } 

        if(activation == "ReLU"){
            swt = 0;
        }
        else if(activation == "sigmoid"){
            swt = 1;
        }
    }

    double process(double val){
        if(swt == 0){

        }
    }
};
 
int main(){
    //complete main here
 
    return 0;
}