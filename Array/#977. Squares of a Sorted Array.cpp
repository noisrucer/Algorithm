class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int>res(n);
        int i=0, j=n-1, k=n-1;
        while(i<=j){
            if(abs(A[i])==abs(A[j])) res[k--]=pow(A[j--],2);
            else if(abs(A[i])<abs(A[j])) res[k--]=pow(A[j--],2);
            else res[k--]=pow(A[i++],2);
        }
        return res;
    }
};