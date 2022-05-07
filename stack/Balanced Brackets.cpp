
bool solve(string s) {
    int n = s.length();
    int left = 0;

    for(char &c: s){
        if(c=='('){
            left++;
        }else{
            if(left--==0) return false;
        }
    }

    return left==0;
}