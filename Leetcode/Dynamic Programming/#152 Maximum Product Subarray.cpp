class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //two Product Variables and sort of "swap"
       if(nums.empty()) 
        return 0;
    
    int currentMax = nums[0];
    int currentMin = nums[0];
    int max_res = nums[0];
        for(int i=1; i<nums.size(); i++){
            int p1 = currentMax * nums[i];
            int p2 = currentMin * nums[i];
            currentMax = max(nums[i],max(p1,p2));
            currentMin = min(nums[i],min(p1,p2));
            max_res = max_res < currentMax ? currentMax : max_res;
        }
        return max_res; 
        
        /*Prefix Product Array
        unordered_set<int>st;
        st.insert(1);
        int product=1;
        int max_product=INT_MIN;
        for(auto i: nums){
            if(i==0){
                st.clear();
                st.insert(1);
                product=1;
                continue;
            }
            product = product * i;
            for(auto itr: st){
                if(product/itr>0) max_product = max(max_product, product/itr);
            }
            st.insert(product);
        }
        return max_product==INT_MIN ? *max_element(nums.begin(),nums.end()) : max_product;
        */
        
    }
};