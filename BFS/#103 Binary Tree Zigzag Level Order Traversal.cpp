
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(!root) return {};
        vector<vector<int>>res;
        deque<TreeNode*> Q;
        Q.push_front(root);
        int cnt=0;
        while(!Q.empty()){
            int size = Q.size();
            res.push_back({});
            while(size--){
                TreeNode* cur;
                if(cnt%2==0){cur = Q.front(); Q.pop_front();} 
                else {cur = Q.back(); Q.pop_back();}
                
                res[cnt].push_back(cur->val);
                if(cnt%2==0){
                  if(cur->left) Q.push_back(cur->left);
                  if(cur->right) Q.push_back(cur->right);
                }else{
                  if(cur->right) Q.push_front(cur->right);
                  if(cur->left) Q.push_front(cur->left);
                }
            } cnt++;
        }
        return res;
    }
};