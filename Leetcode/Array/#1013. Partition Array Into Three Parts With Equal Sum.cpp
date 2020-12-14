class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
       unordered_map<int,int>mp;
        vector<int>prefix(n,0);
        prefix[0]=A[0];
        for(int i=1; i<n; i++)
            prefix[i]=prefix[i-1]+A[i];
        int target = prefix[n-1];
        bool flag=false;

        for(int i=n-2; i>=0; i--){
            if(!flag && prefix[i]==target*2/3){
                flag=true; continue;
            }
            if(flag){
                if(prefix[i]==target/3) return true;
            }
        }
        return false;
        
    }
};