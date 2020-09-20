
class Solution {
public:
    
    int path(TreeNode* root, int& m){
    int l = root->left ? path(root->left, m) : 0;
    int r = root->right ? path(root->right, m) : 0;
    l = (root->left && root->val == root->left->val) ? l+1 : 0;
    r = (root->right && root->val == root->right->val) ? r+1 : 0;
    m = max(m, l+r);
    return max(l,r);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int longestPath =0;
        path(root,longestPath);
        return longestPath;
    }
};