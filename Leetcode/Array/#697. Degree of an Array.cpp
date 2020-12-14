class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
     map<int,int>freq;
	map<int,int>pos;
	int res=0; int degree=0;
	for(int i=0; i<nums.size(); i++){
		freq[nums[i]]++;
		if(!pos.count(nums[i]))
			pos[nums[i]]=i;
		
		if(freq[nums[i]]>degree){
			degree=freq[nums[i]];
			res=i-pos[nums[i]]+1;
		}
		else if(freq[nums[i]]==degree){
			res = min(res,i-pos[nums[i]]+1);
		}
	}
	return res;
    }
};