#include <iostream>
#include <vector>
using namespace std;
//O(n^2)
void selectionSort(vector<int>&arr){
    int n = arr.size();
    int min_index;
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]) min_index = j;
        }
        if(min_index!=i){
            swap(arr[min_index],arr[i]);
        }
    }
}

int main(){
    vector<int>arr={10,9,8,7,6,5,4,3,2,1};
    selectionSort(arr);
    for(auto i:arr) cout<<i<<" ";
}