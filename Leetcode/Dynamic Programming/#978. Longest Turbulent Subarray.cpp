//O(n) Time, O(1) Space
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int inc=1, dec=1, res=1;
        for(int i=1; i<n; i++){
                if(A[i-1]<A[i]){
                    inc=dec+1;
                    dec=1;
                }
                else if(A[i-1]>A[i]){
                    dec=inc+1;
                    inc=1;
                }
                else inc=dec=1;
            res=max(res,max(inc,dec));
        }
        return res;
    }
};


//O(n) Space Complexity O(n) Time Complexity
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        int res=1;
        for(int i=1; i<n; i++){
           int j = i-1;
                if(A[j]<A[i])
                    inc[i]=max(inc[i],dec[j]+1);
                else if(A[j]>A[i])
                    dec[i]=max(dec[i],inc[j]+1);
            
            res=max({res,inc[i],dec[i]});
        }
        return res;
    }
};