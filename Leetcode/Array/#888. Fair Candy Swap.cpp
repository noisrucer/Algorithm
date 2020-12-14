class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int n = A.size(); int m = B.size();
        int diff = (accumulate(B.begin(),B.end(),0)-accumulate(A.begin(),A.end(),0))/2;
        unordered_set<int>st(B.begin(),B.end());
        for(int i=0; i<n; i++){
            if(st.count(A[i]+diff)) return {A[i],A[i]+diff};
        }
        return {};
        
    }
};