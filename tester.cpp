#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n=1, m=3;
   vector<vector<vector<int>>>board(n,vector<vector<int>>(m));
   board[0][0].push_back(0);
   cout<<board[0][0];
}