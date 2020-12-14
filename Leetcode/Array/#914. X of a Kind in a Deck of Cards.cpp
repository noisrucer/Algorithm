class Solution {
public:

    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        if(n==0 || n==1) return false;
        unordered_map<int,int>mp;
        for(auto i:deck) mp[i]++;
        int res=0;
        for(auto i:mp) res=__gcd(res,i.second);
        return res>=2;
    }
};