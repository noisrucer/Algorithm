class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
       unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>Q;
        Q.push(beginWord);
        int cnt=0;
        while(!Q.empty()){
            int size = Q.size();
            cnt++;
             while(size--){
            auto cur = Q.front(); Q.pop();
                 if(cur==endWord) return cnt;
            for(int i=0; i<cur.length(); i++){
                string temp = cur;
                for(int j=0; j<26; j++){
                    cur[i]='a'+j;
                    if(st.count(cur)){
                        st.erase(cur);
                        Q.push(cur);
                  }
                 }
                cur = temp;
                 }
            }
            
        }
        return 0;
        
    }
};