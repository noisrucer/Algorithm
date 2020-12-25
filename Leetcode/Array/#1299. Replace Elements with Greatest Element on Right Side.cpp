class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), max_element = -1, cur;
        for(int i=n-1; i>=0; i--){
            cur = arr[i];
            arr[i]=max_element;
            max_element = max(max_element,cur);
        }
        return arr;
    }
};
