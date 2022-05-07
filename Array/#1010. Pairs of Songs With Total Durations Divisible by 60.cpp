class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
      vector<int>rem(60,0);
        int cnt=0;
        for(auto &i: time){
            cnt+=rem[(60-i%60)%60];
            rem[i%60]++;
        }
        return cnt;
    }
};