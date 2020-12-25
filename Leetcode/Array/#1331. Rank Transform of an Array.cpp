//more efficient approach
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>cpy(arr);
        sort(cpy.begin(), cpy.end());
        unordered_map<int,int>mp;
        int cnt=1;
        for(auto &e: cpy){
            if(mp.count(e)) continue;
            mp[e]=cnt++;
        }
        
        for(int i=0; i<arr.size(); i++){
            arr[i]=mp[arr[i]];
        }
        
        return arr;
    }
};


class Solution {
public:
    
    static bool compare(pair<int,int>A, pair<int,int>B){
        return A.first < B.first;
    }
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return arr;
        vector<pair<int,int>>rank;
        for(int i=0; i<arr.size(); i++){
            rank.push_back({arr[i],i});
        }
        
        sort(rank.begin(), rank.end(), compare);
        
        int cnt=1;
        int before = rank[0].first;
        arr[rank[0].second]=1;
        
        for(int i=1; i<rank.size(); i++){
            if(rank[i].first==before) arr[rank[i].second] = cnt;
            else arr[rank[i].second] = ++cnt;
            before = rank[i].first;
        }
        
        for(auto i: rank){
            cout<<"("<<i.first<<","<<i.second<<") ";
        }
        
        return arr;
    }
};
