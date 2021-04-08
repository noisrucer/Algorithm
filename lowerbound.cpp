#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std; 

int main(){
 vector<int>arr={0,2,2,2,2,7,7,11,13,19};
 //lower bound
 int x = 2;
 int LB;
 int n = arr.size();
 int l = 0, h = n-1, m;
 while(l<=h){
     m = (l+h)/2;
     if(arr[m]>=x && (m == 0 || x > arr[m-1])){
         break;
     }
     if(arr[m] >= x){
         h = m - 1;
     }
     else{
         l = m + 1;
     }
 }
//  cout<<l<<" "<<h<<endl;
 cout<<arr[m]<<" "<<m;
  
}