class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int total=0, maxSum=A[0], curMax=0, minSum=A[0], curMin=0;
        for(auto &i: A){
            curMax = max(i,curMax+i);
            maxSum = max(maxSum,curMax);
            curMin = min(i,curMin+i);
            minSum = min(minSum,curMin);
            total+=i;
        }
        
        return minSum==total ? maxSum : max(maxSum,total-minSum);
    }
};