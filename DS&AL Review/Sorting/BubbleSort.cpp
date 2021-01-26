#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    bool flag;
    for(int i=0; i<n-1; i++){
        flag = false;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            flag = true;
        }
        if(!flag) return;
    }
}

int main(){
    vector<int>arr = {10,9,8,7,6,5,4,3,2,1};
    //Before Sort
    cout<<"Before Sort: ";
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";
    bubbleSort(arr);
    //After Sort
    cout<<"After Sort: ";
    for(auto i:arr) cout<<i<<" ";
}