#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wconversion-null"
using namespace std;

class ndArray {
    //code here
    int bitSize;
    int pos;
    double* arr;

public:

    ndArray(int sz){
        bitSize = sz;
        pos = 0;
        arr = new double[sz];
        for(int i = 0; i< sz; i++){
            arr[i] = 0.0;
        }
    }
    ndArray(ndArray const &a){
        bitSize = a.size();
        arr = new double[bitSize];
        for(int i = 0; i< a.length(); i++){
            arr[i] = a.At(i);
            pos++;
        }    
    }

    int size() const{
        return bitSize;
    }

    int length() const{
        return pos;
    }

    void push(double x){
        if(pos >= bitSize){
            return;
        }
        arr[pos] = x;
        pos++;
        return;
    }
    double At(int index) const{
        if(index >= pos){
            return 0.0;
        }
        return arr[index];
    }
    void print(){
        for(int i = 0; i< pos; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    static dot(ndArray const& a1, ndArray const& a2){
        if(a1.length() != a2.length()){
            cout << "Error: Dimensions not matching." << endl;
            return 0.0;
        }
        double ans = 0.0;
        for(int i = 0; i< a1.length(); i++){
            ans += (a1.At(i) * a2.At(i));
        }
        return ans;
    }
    ndArray& operator+(ndArray const& a){
        ndArray* ans = new ndArray(a.size());
        if(this->bitSize != a.size()){
            cout << "Error: Invalid dimensions." << endl;
            return *ans;
        }
        for(int i = 0; i< a.size(); i++){
            ans->push(this->At(i) + a.At(i));
            pos++;
        }
        return *ans;
    }
    ndArray& operator-(ndArray const& a){
        ndArray* ans = new ndArray(a.size());
        if(this->bitSize != a.size()){
            cout << "Error: Invalid dimensions." << endl;
            return *ans;
        }
        for(int i = 0; i< a.size(); i++){
            ans->push(this->At(i) - a.At(i));
            pos++;
        }
        return *ans;
    }
};
 