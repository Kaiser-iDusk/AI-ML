#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wconversion-null"
using namespace std;

template<typename T>
class ndArray {
    //code here
    int bitSize;
    int pos;
    T* arr;

public:
    // Constructor
    ndArray(int sz){
        bitSize = sz;
        pos = 0;
        arr = new T[sz];
        for(int i = 0; i< sz; i++){
            arr[i] = 0.0;
        }
    }

    // Deep Copy Constructor
    ndArray(ndArray const &a){
        bitSize = a.size();
        arr = new T[bitSize];
        for(int i = 0; i< a.length(); i++){
            arr[i] = a.At(i);
            pos++;
        }    
    }
    ndArray(vector<T> const &v){
        bitSize = v.size();
        arr = new T[bitSize];
        for(int i = 0; i< bitSize; i++){
            arr[i] = v[i];
            pos++;
        }
    }
    ndArray(const T v[], int N){
        bitSize = N;
        arr = new T[bitSize];
        for(int i = 0; i< bitSize; i++){
            arr[i] = v[i];
            pos++;
        }
    }

    // Util Functions
    int size() const{
        return bitSize;
    }

    int length() const{
        return pos;
    }

    void push(T x){
        if(pos >= bitSize){
            return;
        }
        arr[pos] = x;
        pos++;
        return;
    }
    T At(int index) const{
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
    static double dot(ndArray<double> const& a1, ndArray<double> const& a2){
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

    // Overloaded operators
    ndArray<double>& operator+(ndArray<double> const& a){
        ndArray<double>* ans = new ndArray<double>(a.size());
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
    ndArray<double>& operator-(ndArray<double> const& a){
        ndArray<double>* ans = new ndArray<double>(a.size());
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
 