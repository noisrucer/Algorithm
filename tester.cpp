#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    map<int,int>mp;
    mp[1]=3;
    mp[3]=4;
    for(auto i: mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
}