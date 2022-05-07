
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>Q;
        vector<vector<int>> res;
        Q.push(root);
        int cnt=0;
        while(!Q.empty()){
            int size = Q.size();
            res.push_back({});
            while(size--){
                auto cur = Q.front(); Q.pop();
                res[cnt].push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            } cnt++;
        }
        return res; 
    }
};