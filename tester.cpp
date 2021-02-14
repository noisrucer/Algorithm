#include <iostream>
#include <vector>
using namespace std;
int solve(int n, int m) {
    if(n==1) return (m+1)/2;
    if(m==1) return (n+1)/2;
    if(n%2==0 || m%2==0) return n*m/2;
    return solve(n,m-1) + solve(n,1);
}
int main(){
   double x = 1.5;
   cout<<int(x)<<endl;
   cout<<(int)x<<endl;
}