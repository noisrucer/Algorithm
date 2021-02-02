#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    vector<int>card(n);
    for(int i=0; i<n; i++){
        cin >> card[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            if(i-(j+1)<0) break;
                dp[i] = max(dp[i],card[j]+dp[i-(j+1)]);
        }
    }
    cout<<dp[n];
}

// 4
// 1 2 3 4
// 1 5 6 7