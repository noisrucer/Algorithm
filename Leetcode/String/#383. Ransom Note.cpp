class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(auto i: magazine)
            mp[i]++;
        
        for(auto i: ransomNote){
            if(!mp.count(i) || mp[i]==0) return false;
            mp[i]--;
        }
        return true;
    }
};