#include <iostream>
#include <vector>
using namespace std;

// nCk - combination


// 1.
// n = total # elements
// picked: 지금까지 고른 원소들의 번호
// toPick: 앞으로 더 고를 원소의 수
// void pick(int n, vector<int>&picked, int toPick){
//     if(toPick == 0){
//         printPicked(picked);
//         cnt++;
//         return;
//     }

//     int smallest = picked.empty() ? 0 : picked.back() + 1;

//     for(int next=smallest; next<n; next++){
//         picked.push_back(next);
//         pick(n, picked, toPick - 1);
//         picked.pop_back();
//     }
// }

int cnt = 0;

void printPicked(vector<char>&picked){
    for(auto &i: picked) cout<<i<<" ";
    cout<<"\n";
}

// 2. Combinations of pick k elements from 0 ~ n, starting from [idx: ]
vector<char>people;
vector<char>titanic;
int capacity;
int last_index;

void comb(int idx, int num_people){
    // Success
    if(num_people == capacity){
        // printPicked(titanic);
        cnt+=1;
        return;
    }

    if(idx >= last_index) return;

    // Include current idx
    titanic.push_back(people[idx]);
    comb(idx + 1, num_people + 1);

    // Not include current idx
    titanic.pop_back();
    comb(idx + 1, num_people);
}

int main(){                               
    people = {'a','b','c','d','e','f','g','z','y','t'};
    capacity = 4;
    last_index = people.size();
    comb(0, 0);
    cout<<cnt;
}





