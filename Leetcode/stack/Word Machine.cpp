int solve(vector<string>& ops) {
    stack<string>stk;
    string first, second;
    int sum;
    for(string &op: ops){
        if(op=="POP"){
            if(stk.empty()) return -1;
            stk.pop();
        }
        else if(op=="DUP"){
            if(stk.empty()) return -1;
            stk.push(stk.top());
        }
        else if(op=="+"){
            if(stk.size() < 2) return -1;
            first = stk.top(); stk.pop();
            second = stk.top(); stk.pop();
            sum = stoi(first) + stoi(second);
            stk.push(to_string(sum));
            
        }
        else if(op=="-"){
            if(stk.size()<2) return -1;
             if(stk.size() < 2) return -1;
            first = stk.top(); stk.pop();
            second = stk.top(); stk.pop();
            sum = stoi(first) - stoi(second);
            stk.push(to_string(sum));
        }
        else{
            stk.push(op);
        }
    }
    return stoi(stk.top());
}