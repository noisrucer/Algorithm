class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int mx = *max_element(candies.begin(), candies.end());
        
        vector<bool>res(n);
        
        for(int i=0; i<n; i++){
            res[i] = candies[i] + extraCandies >= mx;
        }
        
        return res;
    }
};