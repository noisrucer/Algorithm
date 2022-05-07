class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0 && (i>0?flowerbed[i-1]==0:true) && (i<flowerbed.size()-1?flowerbed[i+1]==0:true)){
                flowerbed[i]=1;
                cnt++;
            }
        }
        return n<=cnt?true:false;
    }
};