#include<bits/stdc++.h>
#include<ctime>
#include "numPy.cpp"
using namespace std;

typedef long long ll;
typedef long double ld;

class Dense{
    int id;
    vector<double>* input;
    vector<double>* data;
    
    vector<vector<double>> weights;
    vector<double>* bias;

    int nInputs, nUnits, nOutputs;
    bool setActivation;

    vector<double> sigmoid(vector<double>& v){
        vector<double> ans;
        for(int i = 0; i< v.size(); i++){
            double z = (1 / (1 + std::exp(-v[i])));
            ans.push_back(z);
        }
        return ans;
    }

    vector<double> ReLU(vector<double>& v){
        vector<double> ans;
        for(int i = 0; i< v.size(); i++){
            double z = max(0, v[i]);
            ans.push_back(z);
        }
        return ans;
    }

    static dot(vector<double>& v1, vector<double>& v2) const{
        if(v1.size() != v2.size()){
            cout << "Error: Dimensions not same." << endl;
            return 0.0;
        }
        double ans = 0;
        for(int i = 0; i< v1.size(); i++){
            ans += (v1[i] * v2[i]);
        }
        return ans;
    }

    static vector<double> assign_add(vector<double> const& v1, vector<double> const& v2){
        if(v1.size() != v2.size()){
            cout << "Error: Dimensions not same." << endl;
            return NULL;
        }
        vector<double> ans;
        for(int i = 0; i< v1.size(); i++){
            ans.push_back(v1[i] + v2[i]);
        }
        return ans;
    }

public:
    Dense(int units, string activation){
        srand(time(0));
        nUnits = units;

        bias = new vector<double>(units, 0.0);
        data = new vector<double>(units, 0.0);
        if(activation == "sigmoid"){
            setActivation = true;
        }
        else{
            setActivation = false;
        }
    }

    // Setting Inputs and Retrieving Outputs
    void setInputs(vector<double>* v){
        nInputs = v->size();
        for(int i = 0; i< units; i++){
            vector<double> temp(nInputs);
            for(int j = 0; j< nInputs; j++){
                temp[j] = (double) rand();
            }
            weights.push_back(temp);
        }
        input = v;
    }
    
    // Weights and Bias Display
    void show_weights(){
        cout << "([ ";
        for(int i = 0; i< nUnits; i++){
            for(int j = 0; j< nInputs; j++){
                cout << weights[i] << " ";
            }
            cout << endl;
        }
        cout << " ], etype = weights, dtype = double)" << endl;
    }

    void show_bias(){
        cout << "([ ";
        for(int i = 0; i< nUnits; i++){
            cout << bias->at(i) << " ";
        }
        cout << " ], etype = bias, dtype = double)" << endl;
    }

    // ID related
    int getID(){
        return id;
    }
    void setID(int x){
        id = x;
    }

    // Actual processing
    void process(){
        vector<double> res1(units, 0.0);
        for(int i = 0; i< nUnits; i++){
            double temp = dot(*input, weights[i]);
            res1[i] = temp;
        }
        vector<double> res2(units);
        res2 = assign_add(res1, *bias);
        data = &res2;
    }
};

class Sequential{
    int layers;
    vector<Dense*> v;
    Input* inpL;

public:
    Sequential(Input* inL, vector<Dense*>& v){
        layers = v.size();

        for(int i = 0; i< v.size(); i++){

        }       
        else{
            cout << "Error: Sequential with 0 layers not valid." << endl;
        }
    }
};

class Input{

}
 
int main(){
    //complete main here
 
    return 0;
}