 class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int n; //2
    int tar; //1
    void backtracking(vector<int> candidates, int sum, int k){
        if(sum>tar) return;
        if(sum==tar){
            ans.push_back(res);
            return;
        }
        if(k>=n) return;
        res.push_back(candidates[k]); //res = 1
        backtracking(candidates, sum+candidates[k], k+1);
        res.pop_back();
        
        k++;
        if(k>=n) return;
        while(k<n && candidates[k]==candidates[k-1]) k++;
        backtracking(candidates, sum, k);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        tar = target;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0);
        return ans;
        
    }
};