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
            if(arr[j]<arr[min_index]) min_index = j;
        }
        if(min_index!=i){
            swap(arr[min_index],arr[i]);
        }
    }
}

int main(){
    vector<int>arr={1,8,4,4,1,6,4,5,2,7,467,8746,3567,2,2,3,2,7,8,8,5,35,25,12,1,7,7};
    selectionSort(arr);
    for(auto i:arr) cout<<i<<" ";
}