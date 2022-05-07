//without stack
int solve(string s) {
    int stack=0, res=0;
    for(char c: s){
        if(c=='(') stack++;
        else if(stack && c==')'){
                stack--;
                res+=2;
        }
    }
    return res;
}

//with stack
int solve(string s) {
    stack<char>stk;
    int res = 0;
    for(char c: s){
        if(c=='('){
           stk.push(c); 
        }else{
            if(stk.empty() || stk.top()==')') continue;
            stk.pop();
            res+=2;
        }
    }
    return res;
}
