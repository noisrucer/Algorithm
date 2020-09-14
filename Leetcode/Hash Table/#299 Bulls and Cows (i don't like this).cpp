class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        unordered_set<int>st;
        string s;
        int bull=0;
        int cow=0;
        for(int i=0; i<secret.size(); i++)
            mp[secret[i]]++;
         
        for(int i=0; i<secret.size(); i++){
            if(guess[i]==secret[i]){
                bull++; mp[secret[i]]--;
                st.insert(i);
            }
        }
        for(int i=0; i<guess.size(); i++){
            if(st.count(i)) continue;
            if(mp.count(guess[i])){
                if(mp[guess[i]]==0) continue;
                cow++; mp[guess[i]]--;
            }      
        }
        string str1=to_string(bull);
        string str2=to_string(cow);
        s=to_string(bull)+'A'+to_string(cow)+'B';
        return s;
    }
};