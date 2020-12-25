#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

int main(){
   unordered_map<int,int>mp;
   mp.emplace(1,2);
   mp.emplace(1,3);
   for(auto i: mp){
       cout<<i.first<<" "<<i.second<<endl;
   }
}