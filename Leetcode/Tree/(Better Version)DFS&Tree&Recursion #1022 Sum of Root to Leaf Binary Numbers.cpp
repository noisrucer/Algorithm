
    int sumRootToLeaf(TreeNode* root, int val =0) {
      if (!root) return 0;
        val = (val * 2 + root->val);
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }

OR you can write as (same thing basically)


class Solution {
public:
    int func(TreeNode* root, int sum){
    if(!root) return 0;
    sum = sum*2 + root->val;
    if(!root->left && !root->right) return sum;
    return func(root->left,sum) + func(root->right,sum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
     return func(root,0);
    }
};
    