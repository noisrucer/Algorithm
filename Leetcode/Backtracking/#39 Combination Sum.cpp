//faster 
class Solution {
public:
    //vector<vector<int>> ans;
    vector<int> res;
    int n;
    int tar;
    void backtracking(vector<vector<int>>&ans,vector<int>candidates,int k, int sum){
        if(sum>tar) return;
        if(sum==tar){
            ans.push_back(res);
            return;
        }
        if(k>=n) return;
        for(int i=k; i<n; i++){
            res.push_back(candidates[i]);
            backtracking(ans, candidates,i,sum+candidates[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        tar = target;
        vector<vector<int>>ans;
        backtracking(ans, candidates,0,0);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    int n;
    int tar;
    void backtracking(vector<int>candidates,int index, int k, int sum){
        if(sum>tar) return;
        if(sum==tar){
            ans.push_back(res);
            return;
        }
        if(k>=n) return;
        res.push_back(candidates[k]);
        backtracking(candidates,index+1, k, sum+candidates[k]);
        res.pop_back();
        backtracking(candidates,index, k+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        tar = target;
        backtracking(candidates,0,0,0);
        return ans;
    }
};