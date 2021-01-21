#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>&arr, int i, int j, int &target){
    int m;
    while(i<=j){
        m = i + (j-i)/2; //find mid
        if(arr[m] == target) return m; //If found, return the index
        else if(arr[m] > target) j = m - 1;
        else i = m + 1;
    }
    return -1; //Not found, return -1;
}
int main(){
    vector<int>arr = {1,2,53,0,14,45,4,6,3,52,27,245,81,57,348,34,7};
    sort(arr.begin(),arr.end()); //To perform BS, must sort it
    int target = 348;
    cout << binarySearch(arr,0,arr.size()-1,target)<<"\n";
}