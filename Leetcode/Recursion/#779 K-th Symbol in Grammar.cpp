class Solution {
public:
    int help(int k, int cnt){
        if(k==2) return (cnt%2==1) ? 0 : 1;
        if(k%2==0) cnt++; 
        return help((k+1)/2,cnt);
    }
    int kthGrammar(int N, int K) {
        if(K==1) return 0;
        return help(K,0);
    }
};