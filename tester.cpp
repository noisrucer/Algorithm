#include <iostream>
#include <vector>
using namespace std;
void iknowyouknow(bool iknow, int i) {
    if(i==0){
        cout<<"we know";
        return;
    }
    if(iknow) cout<<"i know that (";
    else cout<<"you know that (";
    iknowyouknow(!iknow, i-1);
    cout<<")";
}
int main(){
   iknowyouknow(true,3);

}