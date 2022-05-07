class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc=true;
        bool dec=true;
        for(int i=1; i<n; i++){
            if(A[i]<A[i-1]) inc=false;
            if(A[i]>A[i-1]) dec=false;
        }
        return inc||dec;
    }
};