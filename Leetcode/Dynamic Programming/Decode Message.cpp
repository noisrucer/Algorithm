vector<int>dp;
int topdown(string &msg, int i){
    if(i<0) return 1;
    if(i==0) return 1;
   if(dp[i]!=-1) return dp[i];

   if(msg[i]=='0'){
       if(msg[i-1]=='1' || msg[i-1]=='2') dp[i] = topdown(msg,i-2);
       else dp[i] = 0;
   }else{
       string str = msg.substr(i-1,2);
       if(stoi(str)>=1 && stoi(str)<=26 && msg[i-1]!='0') dp[i] = topdown(msg,i-1) + topdown(msg,i-2);
       else dp[i] = topdown(msg,i-1);
   }
    return dp[i];
    
}


int solve(string message) {
    dp={}; dp.clear();
    int n = message.length();
    dp.resize(n,-1);
    return topdown(message,n-1);
    
}
