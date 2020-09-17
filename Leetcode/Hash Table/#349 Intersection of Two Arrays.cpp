class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     unordered_set<int>st;
        vector<int>res;
        for(auto i: nums1)
            st.insert(i);
        for(auto i: nums2){
            if(st.count(i)){
                res.push_back(i);
                st.erase(i);
            }
        }
        return res;
    }
};