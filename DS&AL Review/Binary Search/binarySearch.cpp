#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>&arr, int i, int j, int &target){
    if(i>j) return -1; //when i>j, BS fails and there's no target in the array
    int m = i + (j-i)/2; //set the mid
    if(arr[m] == target) return m; //when found, return its index
    else if(arr[m] > target) return binarySearch(arr,i,m-1,target);
    else return binarySearch(arr,m+1,j,target);
}
int main(){
    vector<int>arr = {1,2,53,0,14,45,4,6,3,52,27,245,81,57,348,34,7};
    sort(arr.begin(),arr.end()); //To perform BS, must sort it
    int target = 348;
    cout << binarySearch(arr,0,arr.size()-1,target)<<"\n";
}