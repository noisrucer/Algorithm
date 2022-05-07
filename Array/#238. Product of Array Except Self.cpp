class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProd = 1, rightProd = 1;
        vector<int>res(n, 1);
        
        for(int i=0; i<n-1; i++){
            leftProd *= nums[i];
            res[i+1] *= leftProd;
            
            rightProd *= nums[n-1-i];
            res[n-2-i] *= rightProd;
        }
        
        return res;
    }
};