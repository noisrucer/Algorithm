#include <iostream>
#include <vector>
using namespace std;

vector<int>perm;
vector<int>visited;
vector<int>temp;
int N;
int cnt;

void printArray(vector<int>&arr){
    for(auto i: arr){
        cout<<i;
    }
    cout<<"\n";
    return;
}

// Make permutations of size k, with elements in array which are NOT yet visited
void permute(vector<int>&arr, int k){
    if(k == N){
        // printArray(temp);
        cnt++;
        return;
    }

    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        temp.push_back(arr[i]);
        permute(arr, k + 1);
        temp.pop_back();
        visited[i] = false;
    }
    
}

int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8,9,10};
    N = arr.size();
    visited.resize(N, false);
    cnt = 0;
    permute(arr, 0);
    cout<<cnt;
}
