class Solution {
public:
    int N = 9;
    int M;
    int target;
    vector<vector<int>>ans;
    vector<int>res;
    void backtracking(int sum, int size, int k){
        if(sum>target) return;
        if(sum==target && size==M){
            ans.push_back(res);
            return;
        }
        if(k>9 || size==M) return;
        res.push_back(k);
        backtracking(sum+k, size+1, k+1);
        res.pop_back();
        backtracking(sum, size, k+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        M = k;
        target = n;
        backtracking(0,0,1);
        return ans;
    }
};