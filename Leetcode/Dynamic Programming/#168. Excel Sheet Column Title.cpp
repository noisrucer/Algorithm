class Solution {
public:
    string convertToTitle(int n) {
        string ans;
       char temp;
        while(n>0){
            n--;
            temp = n%26+'A';
            ans = temp + ans;
            n/=26;
        }
        return ans;
    }
};