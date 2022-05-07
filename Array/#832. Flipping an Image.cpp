class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for(auto &sub:A){
            reverse(sub.begin(),sub.end());
            for(auto &i: sub)i=!i;
        }
        return A;
    }
};