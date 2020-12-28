#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
   map<int,int>mp;
  mp[0]=6;
  mp[364]=4;
  mp[3]=5;
  for(auto &p: mp){
      cout<<p.first<<" "<<p.second<<endl;
  }
}