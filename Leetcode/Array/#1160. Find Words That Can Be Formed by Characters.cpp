class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        int res=0;
        unordered_map<char,int>check;
            
        for(auto i: chars) mp[i]++;
        for(auto word: words){
            check=mp; bool exist=true;
            for(auto w: word){
                check[w]--;
                if(check[w]<0){
                    exist=false; break;
                }
            }
            if(exist) res+=word.length();
        }
        
        return res;
        
        
    }
};