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
        double denom = 1 + std::exp(-z);
        return (double)(1 / denom);
    }

    double ReLU(double z){
        return max(0.0, z);
    }

    // Dot product
    double dot(vector<double>* v1, vector<double>* v2){
        int n = v1->size();
        double ans = 0.0;
        for(int i = 0; i< n; i++){
            //cout << v1->at(i) << " || " << v2->at(i) << endl;
            ans += ((v1->at(i)) * (v2->at(i)));
        }
        //cout << "Dotting : " << ans << endl;
        return ans;
    }

    // adding two vectors
    vector<double> assign_add(vector<double>* v1, vector<double>* v2){
        int n = v1->size();
        vector<double> ans;
        for(int i = 0; i< n; i++){
            //cout << "Adding : " << (v1->at(i) + v2->at(i)) << endl;
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
            weights->at(i) = temp;
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
        vector<double> ans(nUnits);
        for(int i = 0; i< nUnits; i++){
            //cout << "Dot product " << (i+1) << " time." << endl;
            ans[i] = dot(inputs, weights->at(i)) + bias->at(i);
            //cout << "Answer of dot product: " << ans[i];
            data->at(i) = ans[i];
        }
        if(activation){
            for(int i = 0; i< nUnits; i++){
                double z = data->at(i);
                //cout << "Sigmoid of " << z << " : " << sigmoid(z);
                data->at(i) = sigmoid(z);
            }
        }
        else{
            for(int i = 0; i< nUnits; i++){
                double z = data->at(i);
                data->at(i) = ReLU(z);
            }
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
        //cout << "Check 0 done" << endl;
        Dense* init = dense[0];
        
        // step 1
        //cout << "Check 1 done" << endl;
        init->setVals(Inputs);

        for(int i = 1; i< n; i++){
            // step 0
            //cout << "Check 0 done " << (i) << "th time." << endl;
            Dense* temp = dense[i];
            Dense* prev = dense[i-1];
            
            // step 2
            //cout << "Check 2 done" << endl;
            pair<int, int> p = prev->getInfo();
            //cout << "Layer " << (i) << " units: " << p.second << " and inputs: " << p.first << endl; 
            
            //step 1
            //cout << "Check 1 done" << endl;
            temp->setVals(p.second);
        }

        init = dense[n-1];
        pair<int, int> p = init->getInfo();
        nOutputs = p.second;
        //cout << "final layer Inputs: " << p.first << " and outputs: " << p.second << endl;
        //cout << "Check init done" << endl;
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
            //cout << "Check 2.5 done" << endl;

            // step 3
            temp->process();
            //cout << "Check 3 done" << endl;

            // step 4
            input = temp->getOutputs();
            //cout << "Check 4 done" << endl;
        }

        Dense* fin = v[nLayers-1];
        finalVals = fin->getOutputs();
        //cout << "Check fwdprop done" << endl;
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
    int n = 5;
    vector<double> x(n);
    for(int i = 0; i< n; i++){
        double val;
        cout << "Enter the value of " << i+1 << " element: ";
        cin >> val;
        x[i] = val;
    }

    vector<Dense*> v;
    cout << "Enter number of layers: ";
    int m;
    cin >> m;
    cout << endl;

    for(int i = 0; i< m; i++){
        cout << "Enter the number of units: ";
        int l;
        cin >> l;
        cout << endl;

        cout << "Enter the activation of layer: ";
        string a;
        cin >> a;
        cout << endl;

        Dense* d = new Dense(l, a);
        v.push_back(d);
    }   

    Sequential model(n, v);
    cout << "Model ready." << endl;

    model.ForwardProp(x);
    model.displayProp();
    return 0;
}