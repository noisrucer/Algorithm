class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int>cnt(26,INT_MAX);
        for(auto i:A){
            vector<int>temp(26,0);
            for(auto sub: i) temp[sub-'a']++;
            for(int i=0; i<26; i++) cnt[i]=min(cnt[i],temp[i]);
        }
        vector<string>res;
        for(int i=0; i<26; i++){
            if(cnt[i]>0){
                for(int j=0; j<cnt[i]; j++){
                   res.push_back(string(1,i+'a'));
                }
            }
        }
        return res;
    }
};