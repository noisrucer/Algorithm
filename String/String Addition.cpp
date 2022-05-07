string solve(string a, string b) {
    string res="";
    int i = a.length()-1, j = b.length()-1;
    int carry = 0;
    int sum;
    while(i>=0 || j>=0 || carry){
        sum = 0;
        if(i>=0) sum += (a[i--] -'0');
        if(j>=0) sum += (b[j--] - '0');
        if(carry) sum += (carry);
        res  = to_string(sum%10) + res;
        carry = sum/10;
    }
    return res;
}

