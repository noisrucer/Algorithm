class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>Q;
        Q.push(root);
        int depth=0;
        while(!Q.empty()){
            depth++;
            int queueCount=Q.size(); 
            for(int i=0; i<queueCount; i++){
            TreeNode* cur = Q.front();Q.pop();
             if(!cur->left && !cur->right) return depth;
            if(cur->left) Q.push(cur->left);
            if(cur->right) Q.push(cur->right);
            }
        }
        return 0;
    }
};