#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(){
//    vector<int>arr;
//    arr.insert(arr.begin(),4,1);
//    for(auto i: arr){
//        cout<<i<<" ";
//    }

   set<int,greater<int>>st;
   st.insert(1);
   st.insert(6);
   st.insert(4);
   st.insert(6);
   for(auto i: st){
       cout<<i<<" ";
   }
}