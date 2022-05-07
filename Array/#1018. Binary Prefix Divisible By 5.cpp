class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size(), res=0;
        vector<bool>div(n,false);
        for(int i=0; i<n; i++){
            res=res*2+A[i];
            div[i]=!(res=res%5);
        }
        return div;
    }
};