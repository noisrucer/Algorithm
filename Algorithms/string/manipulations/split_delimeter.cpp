#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s = "hello + myname + is + jason";
    string delimeter = " + ";
    size_t pos = 0;
    vector<string>data;

    while((pos = s.find(delimeter)) != string::npos){
        data.push_back(s.substr(0, pos));
        s.erase(0, pos + delimeter.length());   
    }

    data.push_back(s);

    for(string &t: data){
        cout<<t<<" ";
    }
    
}