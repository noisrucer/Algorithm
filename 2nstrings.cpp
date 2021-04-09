#include <iostream>
#include <vector>
using namespace std;
int size;
void printBinary(string s1, string s2, int s1_cnt, int s2_cnt, int n){
    if(n==0){
        if(s1_cnt!=0 || s2_cnt != 0) return;
        cout<< s1+s2 <<endl;
        return;
    }   

    if(s1_cnt>0 && s2_cnt>0){
        printBinary(s1+'0',s2+'0',s1_cnt,s2_cnt,n-1);
        printBinary(s1+'1',s2+'0',s1_cnt-1,s2_cnt,n-1);
        printBinary(s1+'0',s2+'1',s1_cnt,s2_cnt-1,n-1);
        printBinary(s1+'1',s2+'1',s1_cnt-1,s2_cnt-1,n-1);
    }
    else if(s1_cnt==0 && s2_cnt>0){
        printBinary(s1+'0',s2+'0',s1_cnt,s2_cnt,n-1);
        printBinary(s1+'0',s2+'1',s1_cnt,s2_cnt-1,n-1);
    }
    else if(s1_cnt>0 && s2_cnt==0){
        printBinary(s1+'0',s2+'0',s1_cnt,s2_cnt,n-1);
        printBinary(s1+'1',s2+'0',s1_cnt-1,s2_cnt,n-1);
    }
    else{
        printBinary(s1+'0',s2+'0',s1_cnt,s2_cnt,n-1);
    }
}

int main(){
    int n = 3;
    // for(int i=0; i<n; i++){
    //     printBinary("","",i,i+1,n);
    // }
    printBinary("","",1,2,3);
}