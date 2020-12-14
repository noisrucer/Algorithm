class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if(n==0) return nums;
        int m = nums[0].size();
        int total = n*m;
        if(total!=r*c) return nums;
        
        vector<vector<int>>res(r,vector<int>(c));
        
       for(int i=0; i<total; i++){
           res[i/c][i%c]=nums[i/m][i%m];
       }
        return res;
    }
};