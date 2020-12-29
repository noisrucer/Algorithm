#include <iostream>
#include <math.h>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s = "Abc";
    s+=string(1,'c');
    cout<<(s.length()>1);
}