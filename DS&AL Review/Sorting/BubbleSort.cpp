#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    bool flag;
    for(int i=0; i<n; i++){
        flag = false;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            flag = true;
        }
        if(!flag) return;
    }
}
int main(){
    vector<int>arr = {1,2,32,324532,2345,4,5,1,3,4,2,4,201,143,134,4356345};
    //Before Sort
    cout<<"Before Sort: ";
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";
    bubbleSort(arr);
    //After Sort
    cout<<"After Sort: ";
    for(auto i:arr) cout<<i<<" ";
}