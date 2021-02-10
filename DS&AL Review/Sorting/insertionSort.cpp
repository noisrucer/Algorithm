#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;
    }
}
int main(){
    vector<int>arr{1,9,5,5,2,67,56,6345,28,143,2345,4356,2};
    cout<<"Before Sort: ";
    for(auto i: arr) cout<<i<<" ";
    cout<<"\n";

    insertionSort(arr);
    cout<<"After Sort: ";
    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
}