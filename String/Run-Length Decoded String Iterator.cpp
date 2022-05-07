class RunLengthDecodedIterator {
    public:
    vector<int>freq;
    string str;
    int idx = 0; 

    RunLengthDecodedIterator(string s) {
        int prev = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]>='a' && s[i]<='z'){
                freq.push_back(stoi(s.substr(prev,i-prev)));
                str += s[i];
                prev = i+1;
            }
        }
        len = str.length();
    }

    string next() {
        string ret = string(1,str[idx]);
        if(--freq[idx]<=0) idx++;
        return ret;
    }

    bool hasnext() {
        return idx <= str.length()-1;
    }
};
