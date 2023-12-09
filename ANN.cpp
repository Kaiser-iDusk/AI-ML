#include<bits/stdc++.h>
#include<ctime>
#include "numPy.cpp"
using namespace std;

typedef long long ll;
typedef long double ld;

class Sequential{

};

class Dense{
    vector<double>* inputs;
    vector<double>* data;
    vector<double>* bias;
    vector<vector<double>*>* weights;

    int nInputs, nOutputs, nUnits, activation = 0;

    // Activation functions
    double sigmoid(double z){
        return (1 / (1 + std::exp(-z)));
    }

    double ReLU(double z){
        return max(0.0, z);
    }

    // Dot product
    double dot(vector<double>* v1, vector<double>* v2){
        int n = v1->size();
        double ans = 0;
        for(int i = 0; i< n; i++){
            ans += (v1->at(i) * v2->at(i));
        }
        return ans;
    }

    // adding two vectors
    vector<double> assign_add(vector<double>* v1, vector<double>* v2){
        int n = v1->size();
        vector<double> ans(n, 0.0);
        for(int i = 0; i< n; i++){
            ans.push_back(v1->at(i) + v2->at(i));
        }
        return ans;
    }
    
public:
    // class initializer
    Dense(int units, string activation){
        nUnits = units;
        data = new vector<double>(units, 0.0);
        bias = new vector<double>(units, 0.0);

        if(activation == "sigmoid"){
            this->activation = 1;
        }
    }

    // set nInputs, initialize weights and set nOutputs
    void setVals(int inChannels, int outChannels){
        nInputs = inChannels;
        nOutputs = outChannels;

        srand(time(0));
        for(int i = 0; i< nUnits; i++){
            vector<double>* temp = new vector<double>(nInputs);
            for(int j = 0; j< nInputs; j++){
                temp->at(j) = (double) rand();
            }
            weights->push_back(temp);
        }
    }

    // process the input and store it in (*data) 
    void process(){
        for(int i = 0; i< nUnits; i++){

        }
    }
};

int main(){
    //complete main here
 
    return 0;
}