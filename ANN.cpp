#include<bits/stdc++.h>
#include<ctime>
using namespace std;

typedef long long ll;
typedef long double ld;

class Dense{
    vector<double>* inputs;
    vector<double>* data;
    vector<double>* outputs;
    vector<double>* bias;
    vector<vector<double>*>* weights;

    int nInputs, nUnits, activation = 0;

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
    // (0) class initializer
    Dense(int units, string activation){
        nUnits = units;
        data = new vector<double>(units, 0.0);
        bias = new vector<double>(units, 0.0);

        if(activation == "sigmoid"){
            this->activation = 1;
        }
    }

    // (1) set nInputs, initialize weights
    void setVals(int inChannels){
        nInputs = inChannels;
        weights = new vector<vector<double>*>(nUnits);

        srand(time(0));
        for(int i = 0; i< nUnits; i++){
            vector<double>* temp = new vector<double>(nInputs);
            for(int j = 0; j< nInputs; j++){
                temp->at(j) = (double) rand();
            }
            weights->push_back(temp);
        }
    }

    // (2) Get a pair of nInputs and nUnits each perceptron in the layer
    pair<int, int> getInfo(){
        pair<int, int> p;
        p.first = nInputs;
        p.second = nUnits;
        return p;
    }

    // (3) process the input and store it in (*data) 
    void process(){
        vector<int> ans(nUnits, 0.0);
        for(int i = 0; i< nUnits; i++){
            ans[i] = dot(inputs, weights->at(i)) + bias->at(i);
            data->at(i) = ans[i];
        }
    }

    // (2.5) connecting input streams
    void parseChannel(vector<double>* in){
        if(in->size() != nInputs){
            cout << "Error: Dimension mismatch." << endl;
            return;
        }
        inputs = new vector<double>(nInputs);
        for(int i = 0; i< in->size(); i++){
            inputs->at(i) = in->at(i);
        }
    }

    // (4) Sequential access to output streams and setting it
    vector<double>* getOutputs(){
        outputs = new vector<double>(nUnits);
        for(int i = 0; i< nUnits; i++){
            outputs->at(i) = data->at(i);
        }
        return outputs;
    }
};

class Sequential{
    vector<Dense*> v;
    vector<double>* finalVals;
    int nLayers, nInputs, nOutputs;

public:
    Sequential(int Inputs, vector<Dense*>& dense){
        int n = dense.size();
        nLayers = n;
        nInputs = Inputs; 
        v = dense;
        
        //step 0
        Dense* init = dense[0];
        
        // step 1
        init->setVals(Inputs);

        for(int i = 1; i< n-1; i++){
            // step 0
            Dense* temp = dense[i];
            Dense* prev = dense[i-1];
            
            // step 2
            pair<int, int> p = prev->getInfo();
            
            //step 1
            temp->setVals(p.second);
        }

        init = dense[n-1];
        pair<int, int> p = init->getInfo();
        nOutputs = p.second;
    }
    void ForwardProp(vector<double> x){
        if(x.size() != nInputs){
            cout << "Error: Dimension mismatch; expected (" << nInputs << ") but recieved (" << x.size() << ")." << endl;
            return;
        }
        vector<double>* input = &x;
        for(int i = 0; i< nLayers; i++){
            Dense* temp = v[i];

            // step 2.5
            temp->parseChannel(input);

            // step 3
            temp->process();

            // step 4
            input = temp->getOutputs();
        }

        Dense* fin = v[nLayers-1];
        finalVals = fin->getOutputs();
    }
    
    void displayProp(){
        cout << "[ ";
        for(int i = 0; i< nOutputs; i++){
            cout << finalVals->at(i) << " ";
        }
        cout << " ]" << endl;
    }
};

int main(){
    //complete main here
 
    return 0;
}