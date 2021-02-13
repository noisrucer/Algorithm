#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&arr, int l, int m , int r){
    int i = l, j = m+1;
    vector<int>temp;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]); 
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=m) temp.push_back(arr[i++]);
    while(j<=r) temp.push_back(arr[j++]);

    int k = l;
    for(auto e: temp){
        arr[k++] = e;
    }
}

void mergeSort(vector<int>&arr, int l, int r){
    if(l>=r) return;
    int m = l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
int main(){
    vector<int>arr = {1,6,32,4,1,5,3,6,2,41,14,63,567,1,1,35,36,5};
    cout<<"Before Merge Sort: ";
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";

    cout<<"After Merge Sort: ";
    mergeSort(arr,0,arr.size()-1);
    for(auto i: arr) cout<<i<<" ";
}