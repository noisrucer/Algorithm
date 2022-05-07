class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        
        while(i<n-1){
            if(arr[i]==0){
                cout<<i<<" ";
                int temp = i+2;
                int prev = arr[temp-1];
                arr[i+1]=0;
                int curr;
                while(temp<n){
                    curr=arr[temp];
                    arr[temp++]=prev;
                    swap(prev,curr);
                }
                i+=2;
            }else i++;
            
        }
    }
};