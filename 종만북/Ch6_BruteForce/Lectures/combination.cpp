#include <iostream>
#include <vector>
using namespace std;

// nCk - combination
int cnt = 0;

void printPicked(vector<int>&picked){
    for(auto &i: picked) cout<<i<<" ";
    cout<<"\n";
}

// 1.
// n = total # elements
// picked: 지금까지 고른 원소들의 번호
// toPick: 앞으로 더 고를 원소의 수
void pick(int n, vector<int>&picked, int toPick){
    if(toPick == 0){
        printPicked(picked);
        cnt++;
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for(int next=smallest; next<n; next++){
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

// 2. Combinations of pick k elements from 0 ~ n, starting from [idx: ]
void comb(int &n, vector<int>&temp, int idx, int k){
    // Success
    if(k == 0){
        printPicked(temp);
        cnt++;
        return;
    }

    if(idx >= n) return;

    // Include current idx
    temp.push_back(idx);
    comb(n, temp, idx + 1, k - 1);

    // Not include current idx
    temp.pop_back();
    comb(n, temp, idx + 1, k);
}

int main(){
    int n = 10;
    int k = 2;
    vector<int>picked{};
    pick(n,picked, k);
    // comb(n, picked, 0, k);
    cout<<cnt;
}