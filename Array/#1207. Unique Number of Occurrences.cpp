class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>unique;
        unordered_map<int,int>freq;
        
        for(auto &e: arr){
            freq[e]++;
        }
        
        for(auto p: freq){
            if(unique.count(p.second)) return false;
            unique.insert(p.second);
        }
        
        return true;
    }
};