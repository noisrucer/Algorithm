class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int carry=0;
        int i = A.size()-1;
        while(carry || K>0 || i>=0){
            int sum=0;
            if(K>0){
                sum+= K%10;
                K/=10;
            }
            if(i>=0) sum+=A[i];
            if(carry) sum+=carry;
            ans.push_back(sum%10);
            carry = sum/10;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};