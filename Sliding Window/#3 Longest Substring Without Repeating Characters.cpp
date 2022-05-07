//1st Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        
        unordered_set<char>st;
        int maxLength = INT_MIN;
       int start=0,end=0, n=s.size();
        
        while(end<n && start<n){
            if(!st.count(s[end])){ //it doesn't exist -> allowed to add
                st.insert(s[end++]);
                maxLength = max(maxLength,end-start);
            }else{ //if does exist->can't proceed, repeat deleting from the "start" untill X exist
                st.erase(s[start++]);
            }
        }
        return maxLength;
        
    }
};

//2nd Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_set<char>st;
        int maxLength = INT_MIN;
        int windowStart=0;
        for(int windowEnd=0; windowEnd<s.length(); windowEnd++){
            if(!st.count(s[windowEnd])){
            st.insert(s[windowEnd]);
            }else{
            while(st.count(s[windowEnd])){
                st.erase(s[windowStart]);
                windowStart++;
            }
                st.insert(s[windowEnd]);
            }
            maxLength = max(maxLength,windowEnd-windowStart+1);
        }
        return maxLength;
        
    }
};