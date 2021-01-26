#include <iostream>
#include <vector>
using namespace std;
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
//heapify array of size "size" starting from index i to the end
void heapify(vector<int>&arr, int size, int i){
    int cur_max = i;
    if(left(i)<size && arr[left(i)]>arr[cur_max]){
        cur_max = left(i);
    }
    if(right(i)<size && arr[right(i)]>arr[cur_max]){
        cur_max = right(i);
    }

    if(cur_max!=i){
        swap(arr[cur_max],arr[i]);
        heapify(arr,size,cur_max);
    }
}
void printHeap(vector<int>&arr){
    for(auto i: arr) cout<<i<<" ";
}

void heapSort(vector<int>&arr, int size){
    for(int i=size/2-1; i>=0; i--){
        heapify(arr,size,i);
    }
    
    //heapsort by deleting max
    for(int i=size-1; i>=1; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    vector<int>arr = {1,8,3,6,2,56,55,88,34,7354,357,562,25,1,5,3,4,5,2,3,134,51,56,456,3756,23,11,423,3};
    heapSort(arr,arr.size());
   printHeap(arr);
}