class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0, max_len = 0;
        string cur = "";
        unordered_set<char>box;
        
        for(int i=0; i<n; i++){
            while(cur.find(s[i]) != string::npos)
                cur = cur.substr(1);
            
            cur += s[i];
    
            if(static_cast<int>(cur.length()) > max_len)
                max_len = cur.length();
        }
        
        return max_len;
    }
};