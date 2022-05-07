class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if(root==NULL)return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2==NULL)return true;
        if(r1==NULL || r2==NULL)return false;
        if(r1->val != r2->val)return false;
        return helper(r1->left,r2->right) && helper(r1->right,r2->left);
    }
};