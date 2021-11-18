#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int>st;

    st.insert(3);
    st.insert(1);
    st.insert(2);

    for(auto i: st){
        cout<<i<<" ";
    }
}