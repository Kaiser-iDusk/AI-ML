#include<bits/stdc++.h>
#include<ctime>
#include "numPy.cpp"
using namespace std;

typedef long long ll;
typedef long double ld;

class Dense{
    //code here
    int ID;
    int units, preInputs = 1, Outputs = 1;
    ndArray<double>* input;
    ndArray<double>* data;
    vector<ndArray> weights;
    ndArray<double>* bias;
    int* child;
    bool setActivaion;

    double sigmoid(double inp){
        return (1 / (1 + exp(-inp)));
    }

    double ReLU(double inp){
        return max(0, inp);
    }

    ndArray<ndArray<double>> const& get_weights(){
        ndArray<ndArray<double>(preInputs)> wts(units);
        for(int i = 0; i< units; i++){
            ndArray<double> temp(preInputs);
            for(int j = 0; j< preInputs; j++){
                temp.push(weights[i].At(j));
            }
            wts.push(temp);
        }
        return &wts;
    } 

public:
    Dense(int units, string activation){
        this->units = units;
        bias = new ndArray(units);

        srand(time(0));
        for(int i = 0; i< units; i++){
            bias->setAt(0.0, i);
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
        input = new ndArray<double>(preInputs);
    }

    void process(){
        data = new ndArray<double>(units);
        for(int i = 0; i< units; i++){
            data->push(ndArray::dot(v[i], *input));
        }
        (*data) = (*data) + (*bias);
        if(setActivaion){
            for(int i = 0; i< units; i++){
                data->setAt(sigmoid(data->At(i)), i);
            }
            return;
        }else{
            for(int i = 0; i< units; i++){
                data->setAt(ReLU(data->At(i)), i);
            }
            return;
        }
    }
    
    void disp_weights(){
        ndArray<ndArray<double>(preInputs)> wts(units) = get_weights();
        for(int i = 0; i< units; i++){
            ndArray<double> temp = wts.At(i);

            cout << "unit " << i+1 << " : ";
            for(int j = 0; j< preInputs; j++){
                cout << temp.At(j) << " ";
            }
            cout << endl;
        }
    }

    int getId(){
        return ID;
    }
    void setId(int x){
        ID = x;
        return;
    }
    ndArray<double> getOutput(){
        if(Outputs==1){
            
        }
    }
};
 
int main(){
    //complete main here
 
    return 0;
}