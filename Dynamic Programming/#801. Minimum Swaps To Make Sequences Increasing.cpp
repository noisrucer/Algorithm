class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
      vector<int>swap(n,0);
        vector<int>noswap(n,0);
        swap[0]=1;
        for(int i=1; i<n; i++){
            swap[i]=noswap[i]=n+1;
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                swap[i]=swap[i-1]+1;
                noswap[i]=noswap[i-1];
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                noswap[i]=min(noswap[i],swap[i-1]);
                swap[i]=min(swap[i],noswap[i-1]+1);
            }
        }
        return min(swap[n-1],noswap[n-1]);
    }
};