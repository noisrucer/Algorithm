string solve(vector<string>& words) {
    int n = words.size(), firstLength = words[0].length();
    char temp;
    string res="";
    int pos = 0;
    while(pos < firstLength){
        temp = words[0][pos];
        for(int i=0; i<n; i++){
            if(pos >= words[i].length() || words[i][pos] != temp) return res;
        }
        res += words[0][pos];
        pos++;
    }
    return res;
}