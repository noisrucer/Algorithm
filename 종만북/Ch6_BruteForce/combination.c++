#include <iostream>
#include <vector>
using namespace std;

// nCk - combination
int cnt = 0;

void printPicked(vector<int>&picked){
    // for(auto &i: picked) cout<<i<<" ";
    cout<<"\n";
}

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

int main(){
    int n = 100;
    int k = 4;
    vector<int>picked{};
    pick(n,picked, k);
    cout<<cnt;
}