//1st
class Solution {
public:
   //keep track of 'left' condition for each node
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if(!root) return 0;
        if(!root->left&&!root->right)
          return left ? root->val:0;
        
        return sumOfLeftLeaves(root->left,true)+sumOfLeftLeaves(root->right,false);
    }
};

//2nd
class Solution {
public:
    int tot=0;
    
    void func(TreeNode* root, bool left){
    if(!root) return;
    if(!root->left && !root->right){
        if(left) tot+=root->val;
        return;
    }
        
        func(root->left,true);
        func(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        func(root,false);
        return tot;
    }
};

