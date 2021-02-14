#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>res;
    res.reserve(2);
    cout<<res.size();
    res[0]=10;
    res[1]=20;
    for(auto i: res) cout<<i<<" ";
}