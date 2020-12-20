class Solution {
public:
   
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>res;
        unordered_map<string,multiset<string>>mp;
        stack<string>S;
        
        for(auto &ticket: tickets){
            mp[ticket[0]].insert(ticket[1]);
        }
        
        S.push("JFK");
        while(!S.empty()){
            auto curr = S.top();
            if(mp[curr].empty()){
                res.push_back(curr);
                S.pop();
            }else{
                auto dst = mp[curr].begin();
                S.push(*dst);
                mp[curr].erase(dst);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};