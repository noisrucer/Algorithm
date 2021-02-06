string solve(string s) {
    if(s.length()==0) return s;
    s+=s[s.length()-1]-1;
    stack<char>stk;
    int n = s.length();
    bool flag = false;
    for(int i=0; i<n; i++){
        if(stk.empty()){
            stk.push(s[i]);
        }else{
            if(s[i]!=stk.top()){
                if(flag){
                    stk.pop();
                    if(i==n-1) break;
                    flag = false;
                    --i;
                    continue;
                }
                if(i<n-1) stk.push(s[i]);
            }else{
                flag = true;
            }
        }
    }
    string res="";
    while(!stk.empty()){
        res+=stk.top();
        stk.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}