class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_map<int,int>mp;
        vector<int>res;
        
        for(int i=0; i<m; i++) mp[arr2[i]]=i;
        vector<vector<int>>table(m+1);
        
        for(auto i: arr1){
            if(mp.count(i))table[mp[i]].push_back(i);
            else table[m].push_back(i);
        }
        
        sort(table[m].begin(),table[m].end());

        for(auto i: table){
            for(auto x: i){
                res.push_back(x);
            }
        }
        
        return res;
    }
};