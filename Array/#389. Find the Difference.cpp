class Solution {
public:
    char findTheDifference(string s, string t) {
       vector<int>word(26,0);
        for(auto c: s) word[c-'a']++;
        for(auto c: t){
            if(word[c-'a']==0) return c;
            word[c-'a']--;
        }
        return 'F';
    }
};