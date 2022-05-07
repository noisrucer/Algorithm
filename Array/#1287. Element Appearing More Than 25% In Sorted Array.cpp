class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt;
        if(arr.size()%4==0) cnt=arr.size()/4+1;
        else cnt = ceil(arr.size()*0.25);
        unordered_map<int,int>mp;
        for(int i:arr){
            if(++mp[i]>=cnt) return i;
        }
        
        return 0;
    }
};