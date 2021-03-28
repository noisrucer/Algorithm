#include <iostream>
#include <vector>
using namespace std; //

int main(){
    vector<int>arr = {16,7,26,3};
    int r0 = 1;
    int r1,r2,r3,r4;
    r2 = 4;
    for(int i=0; i<4; i++){
        r0 = 1;
        r2 = 4;
    
    while(r0<r2){
        r1 = r0 - 1;
        r3 = arr[r0];
        r4 = arr[r1];
        if(r3>=r4){
            r0+=1;
            continue;
        }
        arr[r0] = r4; 
        arr[r1] = r3;

        r0+=1;
    }
    }
    for(auto i: arr){
        cout<<i<<" ";
    }
}