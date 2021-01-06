#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <deque>
using namespace std;
struct Stack{
    int h;
    int w;
    int l;
};

int main(){
    vector<int>A={1,2,3};
    vector<int>arr(A);
    for(auto i:arr)
    cout<<i<<" ";
    deque<int>dq;
    dq.push_back(1);
    dq.push_back(5);
    dq.push_back(2);
    cout<<*max_element(dq.begin(),dq.end());
}