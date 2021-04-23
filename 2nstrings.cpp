#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <iomanip>
using namespace std;

int n;
vector<vector<vector<int>>>res;
double minVariance = numeric_limits<double>::max();

double findVariance(vector<int>arr){
    double average = accumulate(arr.begin(), arr.end(), 0) / (double) arr.size();
    double sum = 0;
    for(auto &e: arr){
        sum += (e-average)*(e-average);
    }
    return sum;
}

void topdown(vector<int>&arr, vector<vector<int>>category, vector<int>temp, int i, int k, double var){
    if(k<0 || (i<n && k==0)) return;
    if(i==n){
        if(k!=0) return;
        else{
            if(var > minVariance) return;
            else if(var == minVariance){
                res.push_back(category);
            }
            else{
                minVariance = var;
                res.clear();
                res.push_back(category);
            }
            return;
        }
    }

    temp.push_back(arr[i]);
    topdown(arr,category,temp,i+1,k,var);

    if(i!=0 && arr[i]==arr[i-1] && !category.empty()){
        category.back().push_back(arr[i]);
        topdown(arr,category,{},i+1,k-1,var+findVariance(temp));
    }
    else{
        category.push_back(temp);
        topdown(arr,category,{},i+1,k-1,var+findVariance(temp));
    }
}

int main(){
    int k = 5;
    vector<int>arr = {1,1,1,1,1};
    sort(arr.begin(), arr.end());
    n = arr.size();

    topdown(arr,{},{},0,k,0.0);

    cout<<"K: "<<k<<endl;

    cout<<fixed<<setprecision(2)<<minVariance<<endl;

    for(auto &distribution: res){
        int distSize = distribution.size();
        for(int i=0; i<k - distSize; i++){
            cout<<"[]";
        }
        for(auto &category: distribution){
            cout<<"[";
            for(auto &e: category){
                cout<<e<<" ";
            }
            cout<<"]";
        }
        cout<<"\n";
    }
}